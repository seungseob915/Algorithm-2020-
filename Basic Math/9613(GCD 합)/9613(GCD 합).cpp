// 9613(GCD 합).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// https://www.acmicpc.net/problem/9613 범위 주의!! (long long)

#include <iostream>
using namespace std;

int GCD(int, int);
long long int result[101], n[101];

int main()
{
    int t, r;

    long long gcd;

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> r;
        for (int j = 0; j < r; j++) {
            cin >> n[j];
        }
        gcd = 0;
        for (int l = 0; l < r-1; l++) {
            for (int k = l+1; k <r; k++) {
                gcd += GCD(n[l], n[k]);
            }
        }
        result[i] = gcd;
    }
    for (int i = 0; i < t; i++)
        cout << result[i]<<'\n';
}

int GCD(int x, int y) {
    if (y == 0)
        return x;
    else
        return GCD(y, x % y);
}