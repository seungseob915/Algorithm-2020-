#include <iostream>
#include <string>
using namespace std;
int T;

int main() {
    cin >> T;

    while (T--) {
        int n;
        string str;
        cin >> n >> str;

        string ns;

        for (int i = 0; i < str.size(); i++) {
            for (int j = 0; j < n; j++) {
                ns += str[i];
            }
        }
        cout << ns << endl;
    }
}