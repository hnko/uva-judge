/* AC geometry - triangle */
#include <iostream>
#include <cmath>

using namespace std;
/*
	Heron's formula
	4/3 *(sqrt(s*(s-a)*s(s-b)*(s-c))) and s is the semi-perimeter
*/
int main(){

	double a, b, c, s, area;
	
	while(cin >> a >> b >> c){
		
		s = (a + b + c)/2.0;
		
		area = 4/3.0 * sqrt(s*(s-a)*(s-b)*(s-c));

		printf("%0.3f\n", (area > 0) ? area : -1);

	}


	return 0;
}