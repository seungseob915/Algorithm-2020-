// 14002(가장 긴 증가하는 부분 수열 4).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//


#include <iostream>
using namespace std;

int n;
int a[1000];
int d[1000];
int v[1000];

void go(int p) {
    if (p == -1)
        return;
    go(v[p]);
    cout << a[p] << ' ';
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++) {
        v[i] = -1;
        d[i] = 1;
        for (int j = 0; j <= i-1; j++) {
            if (a[i] > a[j]&& d[i] < d[j]+1) {
                    d[i] = d[j]+1;
                    v[i] = j;
                }
            }
        }
    int ans=d[0];
    int p = 0;
    for (int i = 0; i < n; i++) {
        if (ans < d[i]) {
            ans = d[i];
            p = i;
        }
    }

    cout << ans << "\n";
    go(p);
    cout << '\n';

    return 0;
}
