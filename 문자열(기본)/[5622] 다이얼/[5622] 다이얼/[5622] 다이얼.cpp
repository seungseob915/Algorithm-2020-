#include <iostream>
#include <string>
using namespace std;
//알파벳에 번호 저장
int cnt[26] = { 0, };

int main() {
    string str;
    cin >> str;

    char alp = 'A';
    for (int i = 3; i <= 10; i++) {
        if (i == 8 || i == 10) {
            for (int j = 0; j < 4; j++) {
                cnt[int(alp - 'A')] = i;
                alp++;
            }
        }
        else {
            for (int j = 0; j < 3; j++) {
                cnt[int(alp - 'A')] = i;
                alp++;
            }
        }
    }
    int total = 0;
    for (int i = 0; i < str.size(); i++) {
        total += cnt[int(str[i] - 'A')];
    }
    cout << total;
}