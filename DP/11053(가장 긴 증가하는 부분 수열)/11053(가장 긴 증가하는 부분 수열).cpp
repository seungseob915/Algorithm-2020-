// 11053(가장 긴 증가하는 부분 수열).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[1001];
int d[1001];

bool compare(int a, int b) {
    return a > b;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++) {
        int temp = 0;
        d[i] = 1;
        for (int j = i - 1; j >= 1; j--) {
            if (a[i] > a[j]) {
                if (temp < d[j])
                    temp = d[j];
            }
        }
        d[i] = temp + 1;
    }
    sort(d, d + 1001, compare);

    cout << d[0] << "\n";

    return 0;
}
