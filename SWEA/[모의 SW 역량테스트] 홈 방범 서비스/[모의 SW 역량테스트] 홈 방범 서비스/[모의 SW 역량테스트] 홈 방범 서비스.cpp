// [모의 SW 역량테스트] 홈 방범 서비스.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;

int board[21][21];	// 맵
int N, M, T, Tcnt = 1, home_no = 0;
int r[4] = { 0, 0, 1, -1 };
int c[4] = { -1, 1, 0, 0 };

void Init() {
	memset(board, 0, sizeof(board));
	home_no = 0;
}

int bfs(int x, int y) {
	int max_cnt = 0;
	int k = N+1;
	int spend_m = (k * k) + (k - 1) * (k - 1);

	int visited[21][21] = {};

	queue <pair<int, int>> q;
	q.push(make_pair(x, y));	//1, 1부터 시작(중심)
	visited[x][y] = 1;

	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();

		if (visited[now.first][now.second] == k) {
			continue;
		}

		for (int z = 0; z < 4; z++) {
			int nextx = now.first + r[z];
			int nexty = now.second + c[z];

			if (nextx > N || nextx<1 || nexty>N || nexty < 1) {
				continue;
			}
			if (visited[nextx][nexty] != 0) {
				continue;
			}

			q.push(make_pair(nextx, nexty));
			visited[nextx][nexty] = visited[now.first][now.second] + 1;
		}
	}

	while (k--) {
		int home_cnt = 0;
		// 구역에 집이 있는지 탐색
		for (int xx = 1; xx <= N; xx++) {
			for (int yy = 1; yy <= N; yy++) {
				if (visited[xx][yy] >= 1 && board[xx][yy] == 1) {
					home_cnt++;
				}
			}
		}
		int home_money = M * home_cnt;		// 이익

		if (home_money >= spend_m) {
			max_cnt = max(max_cnt, home_cnt);
		}
		if (max_cnt == home_no) {
			return max_cnt;
		}
	}
	return max_cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> T;

	while (T--) {
		Init();

		cin >> N >> M;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> board[i][j];
				if (board[i][j] == 1) {
					home_no++;
				}
			}
		}

		int max_k = N + 1;
		int ans = 0;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				ans = max(ans, bfs(i, j));
			}
		}
		cout << "#" << Tcnt << " " << ans << endl;
		Tcnt++;
	}
}
