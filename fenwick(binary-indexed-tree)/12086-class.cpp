/* AC - Fenwick */
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 200002

int arr[MAX], tree[MAX], N, a, b, cases;
string option, line;

class Fenwick{
private: 
	vector<int> tree;
	int LSB(int i){return i&(-i);}
public:
	Fenwick(int n){ tree.assign(n+1, 0);}
	
	int query(int i){
		if( i == 0) return 0;
		int sum = 0;
		for(; i ; i -= LSB(i)) sum += tree[i];
		return sum;
	}
	int query(int i, int j){ return query(j) - query(i-1);}

	void adjust(int i, int value){
		for(; i<tree.size(); i+=LSB(i)) tree[i] += value;
	}
};
int main(){
	cases = 0;
	while(cin >> N and N){
		if (cases) cout << endl;
		printf("Case %d:\n", ++cases);
		Fenwick ft(N);
		for(int i=1; i<=N; i++){
			cin >> arr[i]; 
			ft.adjust(i, arr[i]);
		}
		cin.ignore();

		while(getline(cin, line) and line != "END"){
			stringstream ss;
			ss << line;
			ss >> option;
			if(option == "M"){
				ss >> a >> b;
				printf("%d\n", ft.query(a, b));
			}else{
				ss >> a >> b;
				ft.adjust(a, b - arr[a]);
				arr[a] = b;
			}
		}
	}

	return 0;
}