/* segment tree */
#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 100005
using namespace std;


int End[MAX], Start[MAX], Freq[MAX], st[MAX*4+10], in[MAX];

int left(int p){return p << 1;}
int right(int p){return p << 1 | 1;}

void build(int p, int L, int R){
	if(L == R) st[p] = L;
	else{
		int mid = (L+R)/2;
		build(left(p), L, mid); build(right(p), mid+1, R);

		int p1 = st[left(p)], p2 = st[right(p)];
		st[p] = (Freq[p1] >= Freq[p2]) ? p1 : p2;
	}
}
int query(int p, int L, int R, int i, int j){
	if(i>R or j<L) return -1;
	if(L>=i and R<=j) return st[p];
	int mid = (L+R)/2;
	int p1 = query(left(p), L, mid, i, j);
	int p2 = query(right(p), mid+1, R, i, j);
	return (Freq[p1]>=Freq[p2]) ? p1 : p2;
}

int main(){
	int n, q, a, b, ans;
	while (cin >> n and n){
		cin >> q;
		for(int i=1; i<=n; i++){
			cin >> in[i];
		}
		Start[1] = 1;
		for(int i=2; i<=n; i++){
			if(in[i] == in[i-1]) Start[i] = Start[i-1];
			else Start[i] = i;
		}

		End[n] = n;
		for(int i=n-1; i>=1; i--){
			if(in[i] == in[i+1]) End[i] = End[i+1];
			else End[i] = i;
		}
		for(int i=1; i<=n; i++){
			Freq[i] = End[i]-Start[i]+1;
		}

		memset(st, 0, sizeof st);
		build(1, 1, n);
		while(q--){
			cin >> a >> b;
			if(in[a] == in[b])
				ans = b-a+1;
			else{
				ans = max(End[a]-a+1, b-Start[b]+1);
				ans = max(ans, Freq[query(1, 1, n, End[a]+1, Start[b]-1)]);
			}
			cout << ans << endl;
		}
	}
	return 0;
}
