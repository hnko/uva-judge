#include <iostream>


using namespace std;

int main(int argc, char const *argv[]){
	long long n;
	while(cin >> n){
		bool stan = true;
		bool ollie = false;
		long long value = 1;
		while(value < n){
			if(stan){
				stan = false; ollie = true;
				value *= 9;
			}else{
				stan=true; ollie=false;
				value *= 2;
			}
		}
		cout << ((!stan) ? ("Stan wins.") : ("Ollie wins.")) << "\n";
	}

	return 0;
}