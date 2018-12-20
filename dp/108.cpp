/* AC - use Kadane algorithm in the columns */
#include <iostream>
#include <cstring>

using namespace std;

int M[101][101], arr[101];
int max_sum, final_left, final_right, final_top, final_bottom, sum, top, bottom, N;
int sum_current, sum_total;

int kadane_column(){
	sum_current = sum_total = arr[0];
	top = bottom = 0;
	for(int i = 1; i< N; i++){
		if(sum_current + arr[i] > arr[i]){
			sum_current += arr[i];
			bottom = i;
		}else{
			sum_current = arr[i];
			top = bottom = i;
		}
		sum_total = max(sum_total, sum_current);
	}
	return sum_total;
}

int kadane_matrix(){
	max_sum = -1e6;
	for(int left = 0; left < N; left++){
		memset(arr, 0, sizeof arr);
		for(int right=left; right < N; right++){

			for(int i=0; i<N; i++) arr[i] += M[i][right];
			sum  = kadane_column();
			if(sum > max_sum){
				max_sum = sum;
				final_left = left; final_right = right;
				final_top = top; final_bottom = bottom;
			}
		}
	}
	return max_sum;
}


int main(){

	while(cin >> N){
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				cin >> M[i][j];
			}
		}
		cout << kadane_matrix() << endl;
		
		/*for(int i=final_top; i<=final_bottom; i++){
			for(int j=final_left; j<=final_right; j++){
				printf("%d ", M[i][j]);
			}
			printf("\n");
		}
		*/
	}
	return 0;
}