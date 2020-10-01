// 1978(소수 찾기).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// https://www.acmicpc.net/problem/1978

#include <iostream>
using namespace std;
bool primary(int);

int num[101];
bool check[101];

int main()
{
    int n, count=0;
    cin >> n;

    fill(check, check+101, false);  //모두 거짓(소수가 아닌수로 초기화), 소수면 true

    for (int i = 1; i <= n; i++)
        cin >> num[i];

    for (int i = 1; i <= n; i++) {
        check[i] = primary(num[i]);
        if (check[i] == true)
            count++;
    }
    cout << count;
}

bool primary(int n) {
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

