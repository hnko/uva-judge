#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <map>
#include <vector>

using namespace std;

int main(){
	string line, a, b;
	getline(cin, line);
	int space = line.find(" ");
	a = line.substr(0, space);
	b = line.substr(space+1);
	
	
	cout << a << b << endl;
	return 0;
}