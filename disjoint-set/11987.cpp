/* AC - UFDS with move one element to another set */
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
#define MAX 200010
int p[MAX], idx[MAX], s[MAX], sm[MAX], commands, command, a, b, N, cnt;

void init(int N){
	for(int i=1; i<=N; i++){
		sm[i] = idx[i] = p[i] = i; 
		s[i] = 1;
	}
}

int find(int i){
	return (i == p[i]) ? i : (p[i] = find(p[i]));
}
void unionSet(int a, int b){
	int x = find(idx[a]), y = find(idx[b]);
	if( x != y){
		p[x] = y;
		s[y] += s[x];
		sm[y] += sm[x];
	}
}
void move(int pp, int qq){
	int x = find(idx[pp]), y = find(idx[qq]);
	if(x != y){
		s[x]--; sm[x] -= pp;
		
		idx[pp] = cnt++;
		p[idx[pp]] = y;

		sm[y] += pp; s[y]++; 
		
		
		
	}
}


int main(){

	while(cin >> N >> commands){
		init(N);
		cnt = N + 1;
		for(int i=0; i<commands; i++){
			cin >> command;
			if(command == 1){
				cin >> a >> b;
				unionSet(a, b);
			}else if(command == 2){
				cin >> a >> b;
				move(a, b);
			}else{
				cin >> a;
				printf("%d %d\n", s[find(idx[a])], sm[find(idx[a])]);
			}
		}
	}

	return 0;
}