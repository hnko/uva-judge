#include <iostream>
#include <queue>
#include <string>
#include <cmath>
#include <vector>
#include <sstream>
#include <cstring>

using namespace std;
typedef pair<double, double> dd;
dd s, t, a;

double distance(dd a, dd b){
	return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}
int main(){

	int vel, m;

	while(cin >> vel >> m and (vel!=0 and m!=0)){
		string line;
		vector< dd > v;

		cin >> s.first >> s.second;
		cin >> t.first >> t.second;
		v.push_back(s); v.push_back(t);

		cin.ignore();
		while(getline(cin, line)){
			if(line.empty()) break;
			stringstream ss;
			ss << line;
			ss >> a.first >> a.second;
			v.push_back(a);
		}
		queue<int> q;
		q.push(0);
		int dist[v.size()];
		memset(dist, -1, sizeof dist);
		dist[0] = 0;
		while(!q.empty()){
			int point = q.front(); q.pop();
			if(point == 1) break;
			for(int i=1; i<v.size(); i++){
				if((distance(v[point], v[i]) <= vel*m*60) and (dist[i] == -1)){
					q.push(i);
					dist[i] = dist[point] + 1;
				}
			}
		}
		if(dist[1] > -1){
			cout << "Yes, visiting " << dist[1] - 1 << " other holes." << endl;
		}else{
			cout << "No." << endl;
		}


	}

	return 0;
}