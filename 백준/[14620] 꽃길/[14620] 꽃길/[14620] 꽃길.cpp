// [14620] 꽃길.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
using namespace std;

int board[11][11];
bool chk[11][11];

int N, ans=987654321;
int dx[] = { 0,-1, 0, 1, 0 };
int dy[] = { 0, 0, 1, 0, -1 };

void dfs(int now, int cost) {
	if (cost >= ans) {
		return;
	}
	
	if (now == 3) {
		ans = min(ans, cost);
		return;
	}

	bool t_chk[11][11] = {};
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			t_chk[i][j] = chk[i][j];

	for (int i = 2; i <= N - 1; i++) {
		for (int j = 2; j <= N - 1; j++) {
			if (chk[i][j]) continue;
			int n_cost = cost;
			bool go = true;
			for (int k = 0; k < 5; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (chk[nx][ny]) {
					go = false;
					break;
				}
				chk[nx][ny] = true;
				n_cost += board[nx][ny];
			}

			if (!go) {
				for (int i = 1; i <= N; i++)
					for (int j = 1; j <= N; j++)
						chk[i][j] = t_chk[i][j];
				continue;
			}
			
			else {
				dfs(now + 1, n_cost);
				for (int i = 1; i <= N; i++)
					for (int j = 1; j <= N; j++)
						chk[i][j] = t_chk[i][j];
			}
		}
	}
}

int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
		}
	}

	dfs(0, 0);

	cout << ans;
}
