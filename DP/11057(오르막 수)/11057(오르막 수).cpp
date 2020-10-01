// 11057(오르막 수).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int n;
int d[1001][10];

int main()
{
    cin>>n;

    for (int i = 0; i <= 9; i++)
        d[1][i] = 1;

    for(int i=2; i<=n; i++)
        for(int j=0; j<=9; j++)
            for (int k = 0; k <= j; k++) {
                d[i][j] += d[i - 1][k];
                d[i][j] %= 10007;
            }
    long long int ans = 0;
    for (int i = 0; i <= 9; i++)
        ans += d[n][i];
    ans %= 10007;

    cout << ans << "\n";
    return 0;

}
