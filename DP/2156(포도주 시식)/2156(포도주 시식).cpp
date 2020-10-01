// 2156(포도주 시식).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[10001];
long long int d[10001][3];

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    d[1][0] = 0;
    d[1][1] = a[1];

    for(int i=2; i<=n; i++)
        for (int j = 0; j <= 2; j++) {
            if (j == 0)
                d[i][0] = max({ d[i - 1][0], d[i - 1][1], d[i - 1][2] });
            if (j == 1)
                d[i][1] = d[i - 1][0] + a[i];
            if (j == 2)
                d[i][2] = d[i - 1][1] + a[i];
        }
    long long int ans = max({ d[n][0], d[n][1], d[n][2]});
    cout << ans;
    return 0;
}
