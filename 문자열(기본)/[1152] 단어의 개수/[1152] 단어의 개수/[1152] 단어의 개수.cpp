#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string str;
    getline(cin, str);
    stringstream ss(str);

    int cnt = 0;
    string s;
    vector<string> a;
    while (getline(ss, s, ' '))
        a.push_back(s);

    if (a[0] == "") cout << a.size() - 1;
    else cout << a.size();
}