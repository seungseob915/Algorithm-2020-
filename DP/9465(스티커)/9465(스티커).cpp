// 9465(스티커).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>

using namespace std;

long long int a[3][100001];
long long int d[100001][3];

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

            for (int j = 1; j <= n; j++)
                cin >> a[1][j];
            for (int j = 1; j <= n; j++)
                cin >> a[2][j];

            d[0][0] = d[0][1] = d[0][2] = 0;
          
            for (int x = 1; x <= n; x++){
                d[x][0] = max({ d[x - 1][1], d[x - 1][2], d[x - 1][0] });
                d[x][1] = max(d[x - 1][0], d[x - 1][2]) + a[1][x];
                d[x][2] = max(d[x - 1][0], d[x - 1][1]) + a[2][x];
            }

        long long int ans = max({ d[n][0], d[n][1], d[n][2] });


        cout << ans << "\n";
    }
    return 0;
}