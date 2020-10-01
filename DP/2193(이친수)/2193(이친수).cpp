// 2193(이친수).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int n;
long long int d[91][2];

int main()
{
    cin>>n;
    
    d[1][1] = 1;

    for(int i=2; i<=n; i++)
        for (int j = 0; j <= 1; j++) {
            if (j == 1)
                d[i][1] += d[i - 1][0];
            if (j == 0)
                d[i][0] += d[i - 1][0] + d[i - 1][1];
        }
    
    long long int ans = d[n][1] + d[n][0];
    cout << ans << "\n";

    return 0;
}
