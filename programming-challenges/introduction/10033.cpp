/* AC - introduction */
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;

string aux;
int reg, jump, a, b, c, i, aux2, t, cnt;
int registers[10], ram[1001];


int run(){
	i = 0; cnt = 0;

	while(i < 1000){
		reg = ram[i];
		
		a = reg / 100;
		b = (reg / 10) % 10;
		c = reg %10;
		
		if(a == 1 and b==0 and c==0){cnt++; return cnt;}
		else if (a == 2) registers[b] = c;
		else if (a == 3) registers[b] = (registers[b] + c) % 1000;
		else if (a == 4) registers[b] = (registers[b] * c) % 1000;
		else if (a == 5) registers[b] = registers[c];
		else if (a == 6) registers[b] = (registers[b] + registers[c]) % 1000;
		else if (a == 7) registers[b] = (registers[b] * registers[c]) % 1000;
		else if (a == 8) registers[b] = ram[registers[c]];
		else if (a == 9) ram[registers[c]] = registers[b];
		else{
			if (registers[c]!=0) i = registers[b]-1;
		}
		i++;
		cnt++;
	}
}

int main(int argc, char const *argv[]){
	cin >> t;
	cin.ignore();
	getline(cin, aux);
	while (t--){
		
		memset(registers, 0, sizeof registers);
		memset(ram, 0, sizeof ram);
		i = 0;
		while(getline(cin, aux) and !aux.empty()){
			ram[i++] = atoi(aux.data());
		}
		
		cout << run() << endl;
		if(t) cout << endl;	
	}
	

	return 0;
}