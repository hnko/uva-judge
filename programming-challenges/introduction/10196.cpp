/* AC - introduction */

#include <iostream>
#include <string>
#include <utility>

using namespace std;

string board[8];
pair<int, int> white_king, black_king;
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, 2, -2, 1, -1};
int diagonalesx[4] = {-1, 1, 1, -1};
int diagonalesy[4] = { 1, 1, -1, -1};
int ejex[4] = {0, 1, 0, -1};
int ejey[4] = {1, 0, -1, 0};

bool is_save(int x, int y){	return (x>=0 and x<8 and y>=0 and y<8) ? true : false;}


bool check_white(){
	int x, y;
	/* caballos */
	for(int i=0; i<8; i++){
		x = white_king.first + dx[i];
		y = white_king.second + dy[i];
		if(is_save(x, y) and board[x][y] == 'n') return true;
	}
	/* diagonales */
	for(int i=0; i<4; i++){
		x = white_king.first + diagonalesx[i];
		y = white_king.second + diagonalesy[i];
		while(is_save(x, y) and board[x][y] == '.'){
			x += diagonalesx[i];
			y += diagonalesy[i];
		}
		if (is_save(x, y)) {
			if (board[x][y] > 'a') {
				if ((board[x][y] == 'q') || (board[x][y] == 'b') || ((board[x][y] == 'p') && (x+1 == white_king.first))) return true;
			}
		}
	}
	/* ejes */
	for(int i=0; i<4; i++){
		x = white_king.first + ejex[i];
		y = white_king.second + ejey[i];
		while (is_save(x, y) && (board[x][y] == '.')) {
			x += ejex[i];
			y += ejey[i];
		}
		if (is_save(x, y)) {
			if (board[x][y] > 'a') {
				if ((board[x][y] == 'q') || (board[x][y] == 'r')) return true;
			}
		}
	}
	return false;
}


bool check_black () {
	
	int x, y;
	
	//checkea los caballos
	for (int i=0; i<8; i++) {
		x = black_king.first+dx[i];
		y = black_king.second+dy[i];
		if (is_save(x, y) && (board[x][y] == 'N')) return true;
	}
	
	//checkea las diagonales
	for (int i=0; i<4; i++) {
		x = black_king.first+diagonalesx[i];
		y = black_king.second+diagonalesy[i];
		while (is_save(x, y) && (board[x][y] == '.')) {
			x += diagonalesx[i];
			y += diagonalesy[i];
		}
		if (is_save(x, y)) {
			if (board[x][y] < 'a') {
				if ((board[x][y] == 'Q') || (board[x][y] == 'B') || ((board[x][y] == 'P') && (x-1 == black_king.first))) return true;
			}
		}
	}
	
	//checkea los ejes
	for (int i=0; i<4; i++) {
		x = black_king.first+ejex[i];
		y = black_king.second+ejey[i];
		while (is_save(x, y) && (board[x][y] == '.')) {
			x += ejex[i];
			y += ejey[i];
		}
		if (is_save(x, y)) {
			if (board[x][y] < 'a') {
				if ((board[x][y] == 'Q') || (board[x][y] == 'R')) return true;
			}
		}
	}
	
	return false;
	
}
bool read_board(){
	bool ans = false;
	for (int i=0; i<8; i++) {
		cin >> board[i];
		for (int j=0; j<8; j++) {
			if (board[i][j] != '.') {
				ans = true;
				if (board[i][j] == 'K') {
					white_king.first = i;
					white_king.second = j;
				} else if (board[i][j] == 'k') {
					black_king.first = i;
					black_king.second = j;
				}
			}
		}
	}
	return ans;
}

int main(){
	int cases = 0;
	while(read_board()){
		if (check_white()) printf("Game #%d: white king is in check.\n", ++cases);
		else if (check_black()) printf("Game #%d: black king is in check.\n", ++cases);
		else printf("Game #%d: no king is in check.\n", ++cases);
		for(int i=0; i<8; i++) board[i].clear();
		cin.ignore();
	}


	return 0;
}