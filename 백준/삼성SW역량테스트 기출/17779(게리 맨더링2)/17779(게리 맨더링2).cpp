// 17779(게리 맨더링2).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define INF 987654321;
int n;
int arr[20][20];
int mark[20][20]; // 지역구 기록

void fill(int r, int c, int value) {
	if (r<0 || r>n - 1 || c<0 || c>n - 1) {
		return;
	}
	if (mark[r][c] != 0)
		return;

	mark[r][c] = value;
	fill(r - 1, c, value);
	fill(r + 1, c, value);
	fill(r, c - 1, value);
	fill(r, c + 1, value);
}

int solve() {
	int ret = INF;

	//마름모 꼭지점 중 맨 위의 점이 기준(x,y)
	for(int x=0; x<n-2; x++)
		for (int y = 1; y < n - 1; y++) {
			for (int d1 = 1; x+d1 <n-1 && y-d1>=0; d1++) {
				for (int d2 = 1; x + d1 + d2 <= n - 1 && y + d2 <= n - 1; d2++) {
					memset(mark, 0, sizeof(mark));
					
					//선거구 경계 그리기
					for (int i = 0; i <= d1; i++) {
						// (x,y)에서 (x+d1, y-d1) 으로 (x+d2, y+d2)에서 (x+d1+d2, y-d1+d2)까지
						mark[x + i][y - i] = 5;
						mark[x + d2 + i][y + d2 - i] = 5;
					}
					// 마지막 2개의 변 그리기
					for (int i = 0; i <= d2; i++ ) {
						mark[x + i][y + i] = 5;
						mark[x + d1 + i][y - d1 + i];
					}

					// 구역 별 경계선 긋기
					for (int r = x - 1; r >= 0; r--)
						mark[r][y] = 1;

					for (int c = y + d2+ 1; c < n; c++)
						mark[x+d2][c] = 2;

					for (int c = y - d1 -1 ; c >= 0; c--)
						mark[x + d1][c] = 3;

					for (int r = x+d1+d2+1; r < n; r++)
						mark[r][y-d1+d2] = 4;

					fill(0, 0, 1);
					fill(0, n - 1, 2);
					fill(n - 1, 0, 3);
					fill(n - 1, n - 1, 4);

					int people[6] = { 0 };
					for (int r = 0; r < n; r++)
						for (int c = 0; c < n; c++)
							people[mark[r][c]] += arr[r][c];

					people[5] += people[0];
					int minP = INF;
					int maxP = 0;
					for (int i = 1; i < 5; i++) {
						minP = min(minP, people[i]);
						maxP = max(maxP, people[i]);
					}
					
					ret = min(ret, maxP - minP);
				}

			}
		}
	return ret;
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	cout << solve() << endl;

	return 0;
}