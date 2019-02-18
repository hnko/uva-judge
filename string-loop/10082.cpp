/* AC - use map */
#include <iostream>
#include <string>
#include <map>

using namespace std;

string line;
map<char, char> mp;


int main() {
    mp['W'] =  'Q'; mp['E'] =  'W'; mp['R'] =  'E';
    mp['T'] =  'R'; mp['Y'] =  'T'; mp['U'] =  'Y';
    mp['I'] =  'U'; mp['O'] =  'I'; mp['P'] =  'O';
    mp['['] =  'P'; mp[']'] =  '['; mp['\\'] =  ']';
    mp['S'] =  'A'; mp['D'] =  'S'; mp['F'] =  'D';
    mp['G'] =  'F'; mp['H'] =  'G'; mp['J'] =  'H';
    mp['K'] =  'J'; mp['L'] =  'K'; mp[';'] =  'L';
    mp['\''] =  ';'; mp['X'] =  'Z'; mp['C'] =  'X';
    mp['V'] =  'C'; mp['B'] =  'V'; mp['N'] =  'B';
    mp['M'] =  'N'; mp[','] =  'M'; mp['.'] =  ',';
    mp['/'] =  '.'; mp['1'] =  '`'; mp['2'] =  '1';
    mp['3'] =  '2'; mp['4'] =  '3'; mp['5'] =  '4';
    mp['6'] =  '5'; mp['7'] =  '6'; mp['8'] =  '7';
    mp['9'] =  '8'; mp['0'] =  '9'; mp['-'] =  '0';
    mp['='] =  '-';

    while (getline(cin, line)) {
        for (int i = 0; i < line.length(); i++) {
            if (mp[line[i]]) line[i] = mp[line[i]];
        }
        cout << line << endl;

    }

    return 0;
}