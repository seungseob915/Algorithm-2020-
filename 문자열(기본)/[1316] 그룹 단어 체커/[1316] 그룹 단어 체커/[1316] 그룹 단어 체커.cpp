#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0;

    while (n--) {
        string str;
        cin >> str;

        bool chk[26] = { 0, };
        chk[int(str[0] - 'a')] = true;
        bool flag = true;
        for (int i = 1; i < str.size(); i++) {
            if (str[i - 1] == str[i]) continue;
            if (chk[int(str[i] - 'a')]) {
                flag = false;
                break;
            }
            chk[int(str[i] - 'a')] = true;
        }

        if (flag) ans++;
    }
    cout << ans;
}