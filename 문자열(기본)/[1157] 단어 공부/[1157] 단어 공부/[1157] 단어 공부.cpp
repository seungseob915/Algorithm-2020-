#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int chk[26] = { 0, };

int main() {
    string str;
    cin >> str;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') chk[str[i] - 'a']++;
        else chk[str[i] - 'A']++;
    }

    char ans='0';
    int idx;
    bool flag = false;
    int cnt = *max_element(chk, chk + 26);

    for (int i = 0; i < 26; i++) {
        if (flag == true && cnt == chk[i]) {
            ans = '?';
            break;
        }
        if (flag == false && cnt == chk[i]) {
            idx = i;
            flag = true;
        }
    }
    if (ans != '?') {
        ans = char(idx + 'A');
    }
    cout << ans;
}