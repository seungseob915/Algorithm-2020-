// 17779(게리맨더링 2).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 987654321

int a[21][21];
int check[21][21] = { 0, };
int n;

void fill(int r, int c, int value) {
    //경계를 벗어나면 중단
    if (r <= 0 || r > n || c <= 0 || c > n)
        return;

    //경계선을 만나면 중단
    if (check[r][c] != 0)
        return;

    check[r][c] = value;

    fill (r - 1, c, value);
    fill(r + 1, c, value);
    fill(r, c+1, value);
    fill(r, c-1, value);
}


int simulate() {
    int ret = INF;

    for(int x=1; x<=n-2; x++)
        for (int y = 2; y <= n - 1; y++) 
            for(int d1=2; x+d1<=n-2 && y-d1>=1; d1++)
                for (int d2 = 1; x + d1 + d2 <= n && y + d2 <= n; d2++) {
                    for (int i = 0; i <= d1; i++) {
                        check[x + i][y - i] = 5;
                        check[x  + i + d2][y - i + d2] = 5;
                    }

                    for (int i = 0; i <= d2; i++) {
                        check[x + i][y + i] = 5;
                        check[x + d1 + i][y -d1 + i] = 5;
                    }

                    for (int r = x - 1; r >= 1; r--) {
                        check[r][y] = 1;
                    }

                    for (int r = x + d1 + d2 + 1; r <= n; r++) {
                        check[r][y] = 4;
                    }

                    for (int c = y - d1 - 1; c >=1; c--) {
                        check[x][c] = 3;
                    }

                    for (int c = y + d2 +1; c <= n; c++) {
                        check[x][c] = 2;
                    }

                    fill(1, 1, 1);
                    fill(1, n, 2);
                    fill(n, n, 4);
                    fill(n, 1, 3);

                    int people[6] = { 0, };
                    for (int r = 1; r <= n; r++)
                        for (int c = 1; c <= n; c++)
                            people[check[r][c]]+=a[r][c];

                    // 경계선 내부에 있는 수
                    people[5] += people[0];

                    int minP=INF, maxP=0;
                    for (int i = 1; i <= 5; i++) {
                        minP = min(minP, people[i]);
                        maxP = max(maxP, people[i]);
                    }

                    ret = min(maxP - minP, ret);
                }
    return ret;
}

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin>>a[i][j];

    int ans=simulate();
    cout << ans;
}