#include "UILibraryContext.h"



using namespace std;

UILibraryContext::UILibraryContext(){
	this->state = NULL;
}

int validInput(){
	int index;
	cin >> index;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Bad entry.  try again \n";
		cin >> index;
	}
	return index;
}

void UILibraryContext::run() {
	int input = -1;
	while (1) {
		this->state->display();
		this->state->handleInput(validInput());
	}
}

void UILibraryContext::setState(UILibraryState* current_state_) // set state
{
	try {

		if (this->state != NULL) {
			delete this->state;
		}
		current_state_->context = this;
		this->state = current_state_;
	}
	catch (exception& e)
	{
		cout << "Standard exception: " << e.what() << endl;
	}
}



//void UILibraryContext::handleInput() // menu for ScreenContext
//{
//	FileStorage storage("db.txt");
//	IdObjectFactory factory(storage);
//	auto seasonConfig = factory.construct<SeasonConfig>(SeasonConfigId);
//	system("cls");
//
//	try{
//		int choose, choose_student_options, choose_Secretary_options; // variable to choose operation
//		while(1)
//		{
//			cout << "Enter your screen: " << endl;
//			cout << "1. Student screen\n2. Secretary screen" << endl;
//			cin >> choose;
//			switch(choose){
//			case 1  :														// display student screen
//				cout << endl << "Wellcome to student screen" << endl;
//				cout << "1. Student information\n2. Course information\n3. exit\n" << endl;
//				cin >> choose_student_options;
//				switch(choose_student_options){
//					case 1  :
//						//set_current_State(new StudentEditionState()); // go to StudentEditionState state
//						break;
//					case 2  :
//						//set_current_State(new CourseEditionState());
//						break;
//					case 3  :
//						choose_student_options = 0; // exit from the menu of screen student
//						break;
//					default :
//						handleInput(); // if default show menu again
//						break;
//				}
//				current_state->handleInput();
//			   break;
//			case 2  :														// display secretary screen
//				cout << endl << "Wellcomet to secretary screen" << endl;
//			   	cout << "1. Setting secretary Screen\n2. Student secretary screen\n3. Course secretary screen\n4. exit\n" << endl;
//				cin >> choose_Secretary_options;
//				switch(choose_Secretary_options){
//					case 1  :
//						set_current_State(new ExpressionEditingState());
//						break;
//					case 2  :
//						set_current_State(new StudentListEditingState(seasonConfig));
//						break;
//					case 3  :
//						set_current_State(new CourseListEditionState(seasonConfig));
//						break;
//					case 4  :
//						choose_student_options = 0;  // exit from the menu of screen student
//						break;
//					default :
//						handleInput();  // if default show menu again
//						break;
//				}
//				//current_state->handleInput();
//				break;
//			}
//		}
//	}
//	catch (exception& e)
//	{
//		cout << "Standard exception: " << e.what() << endl;
//	}
//}