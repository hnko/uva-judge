#include <iostream>

using namespace std;
int n, m, carry, num_carries;
int main(int argc, char const *argv[]){
	while(true){
		cin >> n >> m;
		if (n==0 and m==0) return 0;
		carry = num_carries = 0;
		while(n > 0 or m > 0){
			carry = (n%10 + m%10 + carry)/10;
			n /= 10;
			m /= 10;
			if (carry) num_carries++;
		}
		cout << num_carries << endl;
	}
	return 0;
}