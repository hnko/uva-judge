/* AC - queue - move through two queues */
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int t, N, T, M, arrive, time_arrived[10000], time_left[10000], next_, current_side, current_time, cnt;
string side;

int main(){

	cin >> t;
	while(t--){
		cin >> N >> T >> M;
		queue<int> q[2];

		for(int i=0; i<M; i++){
			cin >> arrive >> side;
			if( side == "left") q[0].push(i);
			else q[1].push(i);
			time_arrived[i] = arrive;
		}
		current_time = current_side = 0;
		while(!q[0].empty() or !q[1].empty()){

			next_ = (q[0].empty() ? time_arrived[q[1].front()] :
					q[1].empty() ? time_arrived[q[0].front()] :
					min(time_arrived[q[0].front()], time_arrived[q[1].front()]));

			cnt = 0;
			current_time = max(current_time, next_);
			
			while(!q[current_side].empty() and time_arrived[q[current_side].front()] <= current_time and cnt < N){
				cnt++;
				time_left[q[current_side].front()] = current_time + T;
				q[current_side].pop();
				
			}
			current_side = (current_side + 1 ) % 2;
			current_time += T;
		}
		for(int i=0; i<M; i++){
			printf("%d\n", time_left[i]);
		}
		if(t) cout << endl;
	}
}