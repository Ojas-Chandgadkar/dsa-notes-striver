// There are 2 choices in the menu:

// Choice 1 is to find the area of a circle having radius 'r'.
// Choice 2 is to find the area of a rectangle having dimensions 'l' and 'b'.
// You are given the choice 'ch' and an array 'a'.
// If ‘ch’ is 1, ‘a’ contains a single number ‘r’. If ‘ch’ is 2, ‘a’ contains 2 numbers, ‘l’ and ‘b’.






#include <cmath>										// to import pi : M_PI

double areaSwitchCase(int ch, vector<double> a) {
	
	switch(ch){
		case 1 : 
			return M_PI*a[0]*a[0];
		case 2:
			return a[0]*a[1];
	}
}
