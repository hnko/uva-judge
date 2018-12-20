/* AC - backtracking */
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
int n;
vector<int > arr={1};
set<int > primes = {3,5,7,11,13,17,19,23,29,31};

void print(){
  for(int i=0; i<n; i++){
    if(i!= n-1) printf("%d ", arr[i]);
    else printf("%d\n", arr[i]);
  }
}

bool is_save(int i){
  if(count(arr.begin(), arr.end(), i))
    return false;
  if(!primes.count(arr[arr.size()-1]+i))
    return false;
  if(arr.size() == n-1 and !primes.count(i+arr[0]) )
    return false;
  return true;
}

void solve(){
  if(n == arr.size()){
    print();
  }else{
    for(int i=2; i<=n; i++){
      if(is_save(i)){
        arr.push_back(i);
        solve();
        arr.pop_back();
      }
    }
  }

}

int main(){
  int cases=0;
  
  while(cin >> n){

    if(cases)cout << endl;
     
    if(n==1){
      printf("Case %d:\n", ++cases);
      cout << "1" << endl;
    }
    else if(n&1)
      printf("Case %d:\n", ++cases);
    else{
      printf("Case %d:\n", ++cases);
      solve();
    }


  }

  return 0;
}