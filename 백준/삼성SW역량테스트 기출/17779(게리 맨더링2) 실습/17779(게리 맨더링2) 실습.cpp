// 17779(게리 맨더링2) 실습.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include<algorithm>
#include <cstring>

#define INF 987654321

using namespace std;

int map[21][21];
int people[21][21];
int n;

void paint(int r, int c, int m) {

	if (r > n || r < 1 || c>n || c < 1) {
		return;
	}
	if (map[r][c] != 0) {
		return;
	}

	map[r][c] = m;

	paint(r + 1, c, m);
	paint(r - 1, c, m);
	paint(r , c+1, m);
	paint(r, c-1, m);
}

int solve(){
	int ret=INF;

	for (int x = 1; x <= n - 2; x++) {
		for (int y = 2; y <= n - 1; y++) {
			for (int d1 = 1; x + d1 <= n - 1 && y - d1 >= 1; d1++) {
				for (int d2 = 1; x + d1 + d2 <= n && y + d2 <= n; d2++) {
					memset(map, 0, sizeof(map));

					//경계구역 5로 설정
					for (int i = 0; i <= d1; i++) {
						map[x + i][y - i] = 5;
						map[x + d2 + i][y + d2 - i] = 5;
					}
					for (int i = 0; i <= d2; i++) {
						map[x + i][y + i] = 5;
						map[x + d1 + i][y - d1 + i] = 5;
					}

					for (int i = 1; i <= x - 1; i++)
						map[i][y] = 1;

					for (int i = y + d2 + 1; i <= n; i++)
						map[x + d2][i] = 2;

					for (int i = x + d1 + d2 + 1; i <= n; i++)
						map[i][y - d1 + d2] = 4;

					for (int i = 1; i <= y - d1 - 1; i++)
						map[x + d1][i] = 3;

					paint(1, 1, 1);
					paint(1, n, 2);
					paint(n, 1, 3);
					paint(n, n, 4);

					int popular[6] = { 0, };

					for (int i = 1; i <= n; i++) {
						for (int j = 1; j <= n; j++) {
							popular[map[i][j]] += people[i][j];
						}
					}
					popular[5] += popular[0];

					int maxp = 0;
					int minp = INF;

					for (int i = 1; i <= 5; i++) {
						maxp = max(maxp, popular[i]);
						minp = min(minp, popular[i]);
					}

					ret = min(ret, maxp - minp);
				}
			}
		}
	}
	return ret;
}

int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> people[i][j];

	int ans = solve();

	cout << ans << "\n";

	return 0;
}