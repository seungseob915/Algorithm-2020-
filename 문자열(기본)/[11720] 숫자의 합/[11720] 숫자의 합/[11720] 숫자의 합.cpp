#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    string str;
    cin >> str;

    int sum = 0;
    for (int i = 0; i < str.size(); i++) sum += str[i] - '0';
    cout << sum;
}