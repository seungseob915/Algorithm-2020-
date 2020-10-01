// BruteForce 1182.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

void check(int, int);

int n, s, arr[20], cnt = 0;

int main()
{
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    check(0, 0);

    if (s == 0)
        cnt--;

    cout << cnt;
}

void check(int num, int sum) {
    if (num == n) {
        if (sum == s)
            cnt++;
    }
    else {
        check(num + 1, sum);    // 아무것도 더하지 않음
        check(num + 1, sum + arr[num]);
    }
}