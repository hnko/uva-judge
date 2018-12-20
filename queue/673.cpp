/* AC use vector as stack */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<char > st;
string line;
int t;
bool accepted;
int main(){
	cin >> t;
	cin.ignore();
	while(t--){
		getline(cin, line);
		accepted = true;
		for(int i=0; i<line.size() and accepted; i++){
			
			if(line[i] == ')' or line[i] == ']'){
				
				if(st.size() and ((line[i] ==  ']' and st[st.size()-1] == '[') or (line[i] ==  ')' and st[st.size()-1] == '('))){
			
					st.pop_back();
				}else{
					accepted= false;
					break;
				}
			}else{
				st.push_back(line[i]);
			
			}
		}
		
		printf((accepted and st.size() == 0)? "Yes\n": "No\n"); 
		st.clear();
	}

	return 0;
}