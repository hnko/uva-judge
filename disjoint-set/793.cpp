/* AC  - disjointset */
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;
typedef vector<int> vi;
int t, N, a, b, acc, decc;
string line, opt;

class DisjointSet{
	private: vi p, rank;
	public:
		DisjointSet(int N){
			rank.assign(N, 0); p.assign(N, 0);
			for(int i=0; i<N; i++) p[i] = i;
		}
		int findSet(int i){return (p[i] == i) ? i : (p[i] = findSet(p[i]));}
		bool isSameSet(int i, int j){return findSet(i) == findSet(j);}
		void unionSet(int i, int j){
			if(!isSameSet(i, j)){
				int x = findSet(i), y = findSet(j);
				if(rank[x] > rank[y]) p[y] = x;
				else{
					p[x] = y;
					if(rank[x] == rank[y]) rank[y]++;
				}
			}
		}
};

int main(){

	cin >> t;
	while(t--){
		cin >> N;
		cin.ignore();

		DisjointSet ds(N);
		acc = decc = 0;
		while(getline(cin, line) and !line.empty()){
			stringstream ss;
			ss << line;
			ss >> opt >> a >> b;
			if(opt == "c") ds.unionSet(a-1, b-1);
			else{
				if(ds.isSameSet(a-1, b-1))acc++;
				else decc++; 
			}
		}
		printf("%d,%d\n", acc, decc);
		if(t) cout << endl;
	}

	return 0;
}
