#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, 2, -2, 1, -1};

struct chessBoard {
    char board[5][5];
     ii getEmptyCell() {
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                if (board[i][j] == ' ') return make_pair(i, j);
    }
     bool checkBoard() { 
        for (int i = 0; i < 4; i++)
            for (int j = (i > 1 ? i+1 : i); j < 5; j++)
                if (board[i][j] != '1') return false;
         for (int i = 1; i < 5; i++)
            for (int j = 0; j < (i > 2 ? i+1 : i); j++)
                if (board[i][j] != '0') return false;
         return board[2][2] == ' ';
    }
};
bool save(int x, int y) { return x>=0 and x<5 and y>=0 and y<5;}


int bfs(chessBoard root) {
    queue<chessBoard> q;
    q.push(root);
    int dpth = 0;
    chessBoard curr;
    for (; !q.empty() && dpth < 11; dpth++) {
    	int size = q.size();
        while (size--) {
            curr = q.front();
            q.pop();
            if (curr.checkBoard()) return dpth;
            for (int i = 0; i < 8; i++) {
                ii pos = curr.getEmptyCell();
                int x_next = pos.first + dx[i];
                int y_next = pos.second + dy[i];
                
                if (save(x_next, y_next)) {
                    chessBoard tmp = curr;
                    swap(tmp.board[pos.first][pos.second], tmp.board[x_next][y_next]);
                    q.push(tmp);
                }
            }
        }
    }
    return -1;
}
 int main() {
    int t;
    string line;
    chessBoard original;
    cin >> t;
    cin.ignore();
    while (t--) {
        for (int i = 0; i < 5; i++) {
            getline(cin, line);
            for (int j = 0; j < 5; j++) {
                if (j >= line.length()) original.board[i][j] = ' ';
                else original.board[i][j] = line[j];
            }
        }
         int res = bfs(original);
        if (res != -1) printf("Solvable in %d move(s).\n", res);
        else printf("Unsolvable in less than 11 move(s).\n");
    }
}