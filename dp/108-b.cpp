#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 101

int M[MAX][MAX], A[MAX], N;
int kadane(){
	int curr, max_so_far;
	curr = max_so_far = A[0];
	for(int i=1; i<N; i++){
		curr = max(curr+A[i], A[i]);
		max_so_far = max(max_so_far, curr);
	}
	return max_so_far;
}

int sum_rec_matrix(){
	int max_so_far = 0;
	for(int L=0; L<N; L++){
		memset(A, 0, sizeof A);
		for(int R=L; R<N; R++){
			for(int i=0; i<N; i++){
				A[i] += M[i][R];
			}
			max_so_far = max(max_so_far,  kadane());
		}
	}
	return max_so_far;
}

int main(){
	while (cin >> N){
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++)
				cin >> M[i][j];
		}

		cout << sum_rec_matrix() << endl;
	}

	return 0;
}