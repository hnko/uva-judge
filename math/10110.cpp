#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[]){
	long long n;
	while(cin >> n and n!=0){
		cout << ((pow(sqrt(n), 2) == n)? ("yes") : ("no") ) << endl;
	}
	return 0;
}