/* AC - take the middle value */ 
#include <iostream>
#include <queue>
using namespace std;

int a, b, c, cases;
priority_queue <int > pq;

int main(){
	cin >> cases;
	for(int i=0; i<cases; i++){
		cin >> a >> b >> c;
		pq.push(a); pq.push(b); pq.push(c);
		pq.pop();

		printf("Case %d: %d\n", i+1, pq.top());
		pq.pop();pq.pop();
	}

	return 0;
}