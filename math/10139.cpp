#include <iostream>
using namespace std;
long long int fact, d;

long long int factorial(){
	long long int result = 1;
	for(int i=1; i<=fact; i++){
		result *= i;
	}
	return result;
}

int main(int argc, char const *argv[])
{
	while(cin >>fact >> d){
		if(factorial()%d == 0) printf("%lld divides %lld!\n", d, fact);
		else printf("%lld does not divides %lld!\n", d, fact);
	}
	return 0;
}