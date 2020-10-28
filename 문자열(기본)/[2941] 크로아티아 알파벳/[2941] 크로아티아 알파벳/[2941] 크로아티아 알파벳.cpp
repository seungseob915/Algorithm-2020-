#include <iostream>
#include <string>
using namespace std;

string stdd[8] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=","z=" };

int main() {
    string str;
    cin >> str;

    for (int i = 0; i < 8; i++) {
        while (1) {
            int idx = str.find(stdd[i]);
            if (idx == string::npos)
                break;
            str.replace(idx, stdd[i].size(), "#");
        }
    }
    cout << str.size();
}