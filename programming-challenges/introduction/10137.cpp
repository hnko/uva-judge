/* AC - introduction - double-int - precision 0.01 */
#include <iostream>
#include <algorithm>

using namespace std;

int dollar, cents, N, converted, total, sum_low, sum_high, low_average, high_average, ans;
char point;
int expenses[1000];
int main(){
	while((cin >> N) and (N)){
		

		total = 0;
		for(int i=0; i<N; i++){
			cin >> dollar >> point >> cents;
			converted = dollar * 100 + cents;
			expenses[i] = converted;
			total += converted;
		}
		low_average = total/N;
		high_average = total/N + ((total%100 == 0) ? 0 : 1);

		sum_low = 0;
		for(int i=0; i<N; i++){
			if (expenses[i] < low_average){
				sum_low += low_average - expenses[i];
			}
		}

		sum_high = 0;
		for(int i=0; i<N; i++){
			if (expenses[i] > high_average){
				sum_high += expenses[i] - high_average;
			}
		}

		ans = max(sum_low, sum_high);
		printf("$%d.%02d\n", ans/100, (ans%100));
	}

	return 0;
}