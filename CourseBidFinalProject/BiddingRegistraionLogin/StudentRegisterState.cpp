#include "StudentRegisterState.h"


//  ask for input and check input validation
int insertNumber() {
	int num;
	cin >> num;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Bad entry.  try again \n";
		cin >> num;
	}
	return num;
}

// check if the course if valid for the acceptable list and return bool accourdingly
bool checkCourseValidation(Student & student, SeasonConfig & seasonConfig, int & countPre , double & points , int index)  {

	bool completeExist = false;
	bool biddingExist = false;
	bool registeredExist = false;

	//CHECK IF COURSE IN COMPLETED COURSES
	for (int c = 0; c < student.completedCoursesList.count(); c++){
		if (student.completedCoursesList.get(c).getId() == seasonConfig.courses.get(index).getId())
			completeExist = true;
	}
	//CHECK IF COURSE IN BIDDING COURSES
	for (int c = 0; c < student.biddingList.count(); c++){
		if (student.biddingList.get(c).courseId.get().compare(to_string(seasonConfig.courses.get(index).getId())) == 0){
			biddingExist = true;
			points -= student.biddingList.get(c).pointsAllocated.get();
		}
	}
	//CHECK IF COURSE IN REGISTERED COURSES
	for (int c = 0; c < student.registeredCoursesList.count(); c++){
		if (student.registeredCoursesList.get(c).getId() == seasonConfig.courses.get(index).getId())
			registeredExist = true;
	}

	return (!completeExist && !biddingExist  && !registeredExist ) ? true : false;

}

// build the acceptable list for specific student
double bulidAcceptableList(SeasonConfig seasonConfig, Student & student, double points){
	int countPre = 0;


	//RUN ON ALL THE COURSES
	for (int i = 0; i < seasonConfig.courses.count(); i++){

		//COURSE HAS NO PRE
		if (seasonConfig.courses.get(i).pre.count() == 0){

			if (checkCourseValidation(student, seasonConfig, countPre, points, i)) {
				student.acceptableCourses.add(seasonConfig.courses.get(i));
			}
		}
		//COURSE HAS PRE
		else
		{
			//GO THROW ALL THE PRE CORSES OF SPECIFIC COURSE
			for (int p = 0; p < seasonConfig.courses.get(i).pre.count(); p++){
				//GO THROW ALL THE COMPLETED COURSES OF THE STUDENT
				for (int c = 0; c < student.completedCoursesList.count(); c++){
					//CHECK IF THE STUDENT COMPLETE ALL THE PRE COURSES FOR SPECIFIC COURSE
					if (seasonConfig.courses.get(i).pre.get(p).getId() == student.completedCoursesList.get(c).getId()){
						countPre++;
					}
				}
			}

			if (countPre > 0 && countPre == seasonConfig.courses.get(i).pre.count() && checkCourseValidation(student, seasonConfig, countPre, points, i))
				student.acceptableCourses.add(seasonConfig.courses.get(i));

		}

		//INITILIZE 
		countPre = 0;
	}
	return points;

}

// retrive the number of points for specific student
StudentRegisterState::StudentRegisterState(SeasonConfig & seasonConfig, Student & student) :seasonConfig(seasonConfig), student(student){
	int count = 0;
	Lexer lexer = (this->seasonConfig.pointAllocFormula.get());
	this->points = lexer.getExpression(this->student.completedCoursesList.count())->evaluate();

	count = this->student.acceptableCourses.count();
	for (int i = 0; i < count ; i++) {
		this->student.acceptableCourses.remove(0);
	}

	//update points after build Acceptable list
	this->points = bulidAcceptableList(this->seasonConfig, this->student, points);


}

// get course name from acceptable courses 
string get(Student & student, int index)  {
	return student.acceptableCourses.get(index).name.get();
}

// register to course while checking validation for registerting courses
void registerCourse(Student & student, SeasonConfig & seasonConfig, double & points) {
	int choosePoints, course_index;

	if (student.acceptableCourses.count() == 0) {
		cout << "there is no courses to register" << endl;
		return;
	}
	cout << "please insert course index: ";
	course_index = insertNumber();

	while (course_index > student.acceptableCourses.count() - 1) {
		cout << "index not not exist" << endl << endl;
		course_index = insertNumber();
	}

	cout << "please choose your points for register for this course: \n";
	choosePoints = insertNumber();

	if (choosePoints < 0 || choosePoints > points){
		cout << "Please choose points between 0 to your currently points " << endl;
		return;
	}
	if (student.acceptableCourses.count() == 1) {
		while (choosePoints != points) {
			cout << "Becuase its your last course you can register you need to enter the max number of points you have " << endl;
			choosePoints = insertNumber();
		}
	}
	auto newCourseBid = seasonConfig.getFactory().allocate<Bidding>();
	points -= choosePoints;			// decrease student number of points
	newCourseBid.pointsAllocated.set(choosePoints);

	newCourseBid.courseId.set(to_string(student.acceptableCourses.get(course_index).getId()));
	student.biddingList.add(newCourseBid);
	student.acceptableCourses.remove(course_index);
	cout << "the course added to bidding list\n";
}


// count the number of courses in acceptable list
int count(Student & student) {
	return student.acceptableCourses.count();
}

// display acceptable list and ask for inputs
void StudentRegisterState::display() {

	system("cls");

	cout << "Hello " << student.name.get() << endl << endl;

	cout << "The list - courses that you can register: " << endl << endl;
	for (int i = 0; i < count(this->student); i++) {
		cout << i << ". " << get(this->student, i) << endl;
	}

	cout << "Your remaining number of points to register is: " << this->points;
	cout << endl << endl << endl;

	cout << "Enter your operation: \n\n" << endl;
	cout << "1. add\n2. exit\n\n";
}

// get input and act accourdingly
void StudentRegisterState::handleInput(int input) {
	UILibraryState * state = NULL;
	try {
		switch (input){
		case 1:
			registerCourse(this->student, this->seasonConfig, this->points);
			break;
		case 2:
			state = new LoginState(this->seasonConfig);
			if (state != NULL) {
				state->context = this->context;
				this->context->setState(state);
			}
			break;
		default:
			break;
		}
	}
	catch (exception& e){
		cout << "Standard exception: " << e.what() << endl;
	}
}