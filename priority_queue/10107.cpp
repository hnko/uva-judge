/* AC - priority queue */  
#include <iostream>
#include <queue>

using namespace std;
priority_queue<long long,  vector< long long>,  greater <long long> > M;
priority_queue<long long > m;

long long n;

void reorder_queues(){
	if(m.size() > M.size()){

		M.push(m.top()); 
		m.pop();
	}else{
		if (M.size()-1 > m.size()){
			m.push(M.top());
			M.pop();
		}
	}
}

int main(){
	while(cin >> n){
		if(M.empty()){
			M.push(n);
		}else{
			if(n > M.top()) M.push(n);
			else m.push(n);
		}
		reorder_queues();
		if(M.size() > m.size())
			cout << M.top() << endl;
		else
			cout << (M.top() + m.top())/2 << endl;

	}

	return 0;
}