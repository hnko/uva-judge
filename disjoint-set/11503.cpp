/* AC - UFDS */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
map <string, int > mp;
string src, dst;
int T, N, i;


class disjointSet{	
	private: vi p, rank, s;
	public:
		disjointSet(int N){
			p.assign(N, 0); rank.assign(N, 0); s.assign(N, 1);
			for(int i=0; i<N; i++){	p[i] = i;}
		}
		int findSet(int i){return (p[i] == i) ? i : (p[i] = findSet(p[i]));}
		bool isSameSet(int i, int j){return findSet(i) == findSet(j);}
		void unionSet(int i, int j){
			if(!isSameSet(i, j)){
				int x = findSet(i), y = findSet(j);
				if(rank[x] > rank[y]){
					p[y] = x;
					s[x] += s[y]; 
				} 
				else{
					p[x] = y;
					s[y] += s[x];
					if(rank[x] == rank[y]) rank[y]++;
				}
			}
		}
		int size_(int i){return s[findSet(i)];}
};


int main(){
	cin >> T;
	while(T--){
		cin >> N;

		i = 0;
		disjointSet ds(N*2);
		
		while(N--){
			cin >> src >> dst;
			if(!mp.count(src)) mp[src] = i++;
			if(!mp.count(dst)) mp[dst] = i++;
			ds.unionSet(mp[src], mp[dst]);
			cout << ds.size_(mp[src]) << endl;
		}
		mp.clear();
	}
	return 0;
}