/* AC - iterate through an array */
#include <iostream>
#include <string>

using namespace std;

string line;
bool first=true;

int main(){
    while(getline(cin, line)){

      for(int i=0; i<line.size(); i++){
        if(line[i] == '"' and first){ printf("``"); first = false;}
        else if (line[i] == '"' and !first){ printf("''"); first = true;}
        else printf("%c", line[i]);
      }
      printf("\n");
    }

  return 0;
}
