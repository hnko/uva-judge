/* AC - backtracking */
#include <iostream>
#include <unordered_set>
using namespace std;

int M[8][8], solutions[8];
int aux, row, column, T, sols;
unordered_set<int> myset;

bool is_save(int r, int c){
	// row
	for(int i=0; i<8; i++){	if(M[i][c] == 1) return false;}
	// column
	for(int i=0; i<8; i++){	if(M[r][i] == 1) return false;}
	//diagonals	
	for(int i=r, j=c; i<8 and j<8; i++, j++){if(M[i][j] == 1) return false;	}
	for(int i=r, j=c; i>=0 and j>=0; i--, j--){if(M[i][j] == 1) return false;	}
	for(int i=r, j=c; i>=0 and j<8; i--, j++){if(M[i][j] == 1) return false;	}
	for(int i=r, j=c; i<8 and j>=0; i++, j--){if(M[i][j] == 1) return false;	}

	return true;
}
void print_solution(){
	printf("%2d      %d", ++sols, solutions[0]+1);
	
	for(int i=1; i<8; i++){
		printf("% d", solutions[i]+1);
	}
	cout << endl;
}

void n_queens(int n){
	if(n == 8){
		print_solution();
		return;
	}
	bool flag = true;
	for(int c=0; c<8 and flag; c++){
		if(myset.find(c) != myset.end()) continue;

		flag = false;
		for(int r=0; r<8; r++){
			if(is_save(r, c)){
				M[r][c] = 1;
				solutions[c] = r;
				myset.insert(c);
				
				n_queens(n+1);
				
				M[r][c] = 0;
				myset.erase(c);
			}
		}
	}
}

int main(){

	cin >> T;
	aux = 0;
	while (T--){
		if(aux++) cout << endl;
		
		cin >> row >> column;

		printf("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n");
		for(int i=0; i<8; i++){
			for(int j=0; j<8; j++){
				M[i][j] = 0;
			}
		}
		myset.insert(column-1);
		solutions[column-1] = row-1;
		M[row-1][column-1] = 1;
		sols = 0;
		n_queens(1);
		myset.erase(column-1);
	}
}

 