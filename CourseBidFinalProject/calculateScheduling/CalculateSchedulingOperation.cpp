#include "CalculateSchedulingOperation.h"

// make the calculate scheduilng by checking all the validations for it 
CalculateSchedulingOperation::CalculateSchedulingOperation(SeasonConfig & seasonConfig) : seasonConfig(seasonConfig) {
	int n = 0, m = 0, l = 0, value = 0;
	Lp lp;
	Lp::Expr e1, e2, e3;
	Lp::Col  * x;
	Lp::Constr c;

	m = seasonConfig.students.count();
	n = seasonConfig.courses.count();

	x = new Lp::Col[m*n]; // allocate the memory for the array
	for (int i = 0; i < m; i++){  // Loops for setting the columns and setting the colLowerBound and colUpperBound 
		for (int j = 0; j < n; j++){
			x[i*n + j] = lp.addCol();
			lp.colLowerBound(x[i*n + j], 0);
			lp.colUpperBound(x[i*n + j], 1);
		}
	}

	for (int i = 0; i < n; i++){
		e1 = 0; //  Initialize in order to build the expressions
		e2 = this->seasonConfig.courses.get(i).maxNumberOfStudents.get(); // Assignment to expression var 
		for (int j = 0; j < m; j++){
			e1 += x[j*n + i]; // Build the Variable Constraint
		}
		c = e1 <= e2;
		lp.addRow(c);
	}

	lp.max(); // We need the max 

	for (int i = 0; i < m; i++){  // Loops for the multiplications of the values from the file 
		for (int j = 0; j < n; j++){
			for (int k = 0; k < seasonConfig.students.get(i).biddingList.count(); k++) {
				if (to_string(seasonConfig.courses.get(j).getId()).compare(seasonConfig.students.get(i).biddingList.get(k).courseId.get()) == 0) {
					value = this->seasonConfig.students.get(i).biddingList.get(k).pointsAllocated.get();
				}
				else {
					value = 0;
				}
				e3 += (x[i*n + j] * value);
			}
			
			
		}
	}

	lp.obj(e3); // Build the target function 
	lp.solve(); // Solve the problem 

	for (int i = 0; i < m; i++){   // Loops for printing the results  
		cout << seasonConfig.students.get(i).name.get() << ": ";
		for (int j = 0; j < n; j++){
			if (lp.primal(x[i*n + j]) == 1) {
				cout  << seasonConfig.courses.get(j).name.get() << " " << endl;
				seasonConfig.students.get(i).registeredCoursesList.add(seasonConfig.courses.get(j));
			}

		}
	}

	delete[] x;
}
