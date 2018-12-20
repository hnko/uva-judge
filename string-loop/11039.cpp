/* AC - iterate through two arrays */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t, ans;
long floors, previous, n;
bool is_red, is_blue;
vector< long > blues, red;

int solve_red(int i, int j){

	previous = 0;
	ans = 0;
	is_red = true;

	while(j < red.size() and i<blues.size()){
		if(is_red){
			if(red[j] > previous){
				is_red = false;
				previous = red[j];
				ans++;
			}
			j++;
			
		}else{
			if(blues[i] > previous){
				is_red = true;
				previous = blues[i];
				ans++;
			}
			i++;
		}
		
	}
	if(is_red and j<red.size()){
		while( j < red.size()){
			if(red[j] > previous){
				ans++;
				break;
			}
			j++;
		}
	}
	if(!is_red and i<blues.size()){
		while( i < blues.size()){
			if(blues[i] > previous){
				ans++;
				break;
			}
			i++;
		}
	}

	return ans;
}

int solve_blue(int i, int j){

	previous = 0;
	ans = 0;
	is_blue = true;


	while(j < red.size() and i<blues.size()){
		if(is_blue){
			if(blues[i] > previous){
				is_blue = false;
				previous = blues[i];
				ans++;
			}
			i++;
			
		}else{
			if(red[j] > previous){
				is_blue = true;
				previous = red[j];
				ans++;
			}
			j++;
		}
		
	}

	if(!is_blue and j<red.size()){
		while( j < red.size()){
			if(red[j] > previous){
				ans++;
				break;
			}
			j++;
		}
	}
	if(is_blue and i<blues.size()){
		while( i < blues.size()){
			if(blues[i] > previous){
				ans++;
				break;
			}
			i++;
		}
	}
	return ans;
}




int main(){

	
	cin >> t;
	while(t--){
		cin >> floors;
		for(int i=0; i<floors; i++){
			cin >> n;
			if(n > 0) blues.push_back(n);
			else red.push_back(-n);
		}
		sort(blues.begin(), blues.end());
		sort(red.begin(), red.end());
		if(blues.empty() and red.empty()){
			cout << "0\n";
		}else if(blues.empty()){
			cout << "1\n";
		}else if(red.empty()){
			cout << "1\n";
		}else{
			int i, j; i=0; j=0;
			while(blues[i] == red[j]){i++; j++;}
			if(blues[i] < red[j]){
				cout << solve_blue(i, j) << endl;
			}else{
				cout << solve_red(i, j) << endl;
			}

		}
		blues.clear(); red.clear();
	}
	return 0;

}