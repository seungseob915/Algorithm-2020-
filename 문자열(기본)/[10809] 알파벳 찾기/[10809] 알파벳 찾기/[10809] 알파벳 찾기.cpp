#include <iostream>
#include <string>
using namespace std;

int chk[26];

int main() {
    for (int i = 0; i < 26; i++) chk[i] = -1;
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        if (chk[str[i] - int('a')] == -1)
            chk[str[i] - int('a')] = i;
    }
    for (int i = 0; i < 26; i++) cout << chk[i] << ' ';
}