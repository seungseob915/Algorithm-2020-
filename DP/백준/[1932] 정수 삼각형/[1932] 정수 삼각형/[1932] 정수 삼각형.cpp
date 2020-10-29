// [1932] 정수 삼각형.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
using namespace std;
int n;
int map[501][501] = { 0, };
int dp[501][501] = { 0, };

int find(int floor, int line) {
	if (dp[floor][line] != -1) return dp[floor][line];
	if (floor == n)
		return map[floor][line];
	
	int ret = map[floor][line];
	
	return dp[floor][line]=ret+max(find(floor + 1, line), find(floor + 1, line + 1));
}

int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> map[i][j];
		}
	}

	int ans = find(1, 1);
	cout << ans<<endl;
}
