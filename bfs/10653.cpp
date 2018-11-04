/* bfs - AC */
/* bomb = -2 */
#include <iostream>
#include <queue>
#include <utility>

using namespace std;
int graph[1010][1010];
bool visited[1010][1010];

int c, r, bombs, num_bombs, x_start, x_end, y_start, y_end, xx, yy;
int column_bomb, row_bombs, x, y;
int move_x[4] = {1, -1, 0, 0}; 
int move_y[4] = {0, 0, 1, -1}; 

bool safe(int x, int y){
	return (x<0 || y < 0 || x>=r || y>=c || graph[x][y] == -2) ? false : true;
}
int bfs(){
	queue< pair<int, int> > q;
	q.push(make_pair(x_start, y_start));
	
	graph[x_start][y_start] = 0;
	while(!q.empty()){

		pair<int, int> node = q.front(); q.pop();

		x = node.first;
		y = node.second;

		if(x == x_end and y == y_end) return graph[x][y];
		if(visited[x][y]) continue;

		visited[x][y] = true;

		for(int i=0; i<4; i++){
			xx = x+move_x[i];
			yy = y+move_y[i];

			if(safe(xx, yy) and visited[xx][yy] == false and graph[xx][yy] == -1){
				q.push(make_pair(xx, yy));
				graph[xx][yy] = graph[x][y] + 1;
			}
		}
	}
	return -1;
}

int main(){
	while((cin >> r >> c) and(r!=0 and c!=0)){
		cin >> num_bombs;
		for(int i=0; i<r; i++){
			for(int j=0; j<c; j++){
				graph[i][j] = -1;
				visited[i][j] = false;
			}
		}
		while(num_bombs--){
			cin >> row_bombs >> bombs;
			for(int i=0; i<bombs; i++){
				cin >> column_bomb;
				graph[row_bombs][column_bomb] = -2;
			}
		}

		cin >> x_start >> y_start;
		cin >> x_end >> y_end;
		cout << bfs() << endl;

	}
	return 0;
}
