/* AC - check ascii table */

#include <iostream>
#include <string>

using namespace std;
string line;

int main(){
	while(getline(cin, line)){
		for(int i=0; i<line.size(); i++)printf("%c", line[i]-7);
		printf("\n");

	}

	return 0;
}