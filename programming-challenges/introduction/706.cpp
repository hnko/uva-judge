/* AC - introduction - hint: divide the number into sections */
#include <iostream>
#include <string>

using namespace std;
string number;
int size;

void printUp(){
	for(int i=0; i<number.size(); i++){
		if(i) cout << " ";
		cout << " ";
		for(int j=0; j<size; j++){
			if(number[i] == '1' or number[i] == '4') cout << " ";
			else cout << "-";
		}
		cout << " ";
	}
	cout << endl;
}
void printAboveMid(){
	for(int j=0; j<size; j++){
		for(int i=0; i<number.size(); i++){
			if(i) cout << " ";
			if(number[i] == '1' or number[i] == '2' or number[i] == '3' or number[i] == '7')
				cout << " ";
			else cout << "|";
			
			for(int k=0; k<size; k++) cout << " ";

			if(number[i] == '5' or number[i] == '6') cout << " ";
			else cout << "|";
		}
		cout << endl;

	}
}

void printMid(){
	for(int i=0; i<number.size(); i++){
		if (i) cout << " ";
		cout << " ";
		for(int j=0; j<size; j++){
			if(number[i] == '0' or number[i] == '1' or number[i] == '7')
				cout << " ";
			else cout << "-";
		}
		cout << " ";
	}
	cout << endl;
}

void printBelowMid(){
	for(int j=0; j<size; j++){
		for(int i=0; i<number.size(); i++){
			if(i) cout << " ";
			if(number[i] == '0' or number[i] == '2' or number[i] == '6' or number[i] == '8' )
				cout << "|";
			else cout << " ";
			
			for(int k=0; k<size; k++) cout << " ";

			if(number[i] == '2') cout << " ";
			else cout << "|";
		}
		cout << endl;

	}
}

void printDown(){
	for(int i=0; i<number.size(); i++){
		if(i) cout << " ";
		cout << " ";
		for(int j=0; j<size; j++){
			if(number[i] == '1' or number[i] == '4' or number[i] == '7') cout << " ";
			else cout << "-";
		}
		cout << " ";
	}
	cout << endl;
}

int main(){
	int digit;
	while((cin >> size >> number) and size){
		printUp(); printAboveMid(); printMid(); printBelowMid(); printDown();
		cout << endl;
	}

	return 0;
}