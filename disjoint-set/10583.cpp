/* AC - disjointSet */
#include <iostream>

using namespace std;
#define MAX 50002
int p[MAX], r[MAX], N, M, religions, A, B, cases;
void init(){
    religions = N;
    for(int i=1; i<=N; i++){p[i]=i; r[i] = 0;}
}

int find(int i){return (i == p[i]) ? i : (p[i] = find(p[i]));}
void unionSet(int i, int j){
    int x = find(i), y = find(j);
    if(x != y){
        religions--;
        if(r[x] > r[y]){
            p[y] = x; 
        }else{
            p[x] = y;
            if(r[x] == r[y])r[y]++;
        }
    }
}
int main(){
    cases = 0;
    while((cin >> N >> M) and (N and M)){
        init();
        for(int i=0; i<M; i++){
            cin >> A >> B;
            unionSet(A, B);
        }
        printf("Case %d: %d\n", ++cases, religions);
    }

}