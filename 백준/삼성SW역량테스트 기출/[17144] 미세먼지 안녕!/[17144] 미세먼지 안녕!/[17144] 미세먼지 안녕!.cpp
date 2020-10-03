// [17144] 미세먼지 안녕!.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include<memory.h>
using namespace std;

int R, C, T;
int board[51][51];
int temp[51][51];
pair<int, int> clean[2];    // 공기청정기 위치
queue<pair<int, int>> dust;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1, 1,0,0 };

int main()
{
	cin >> R >> C >> T;

	int c = 0;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> board[i][j];
			if (board[i][j] == -1) clean[c++] = { i, j };
			else if (board[i][j] > 0) dust.push({ i, j });
		}
	}

	while (T--) {
		memset(temp, 0, sizeof(temp));
		//먼지 확산
		while (!dust.empty()) {
			pair<int, int> now = dust.front();
			dust.pop();
			int s_dust = board[now.first][now.second] / 5;
			int cnt = 0;

			for (int k = 0; k < 4; k++) {
				int nx = now.first + dx[k];
				int ny = now.second + dy[k];

				if (nx<1 || nx>R || ny<1 || ny>C) continue;
				if (board[nx][ny] == -1) continue;

				temp[nx][ny] += s_dust;
				cnt++;
			}
			board[now.first][now.second] -= s_dust * cnt;
		}

		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				if (board[i][j] == -1) continue;
				board[i][j] += temp[i][j];
			}
		}


		// 공기청정기 작동 (상 하)
		for (int i = 0; i < 2; i++) {
			if (i == 0) {
				int nx = clean[0].first;
				int ny = clean[0].second;

				nx--;
				while (nx > 1) {
					board[nx][ny] = board[nx - 1][ny];
					nx--;
				}

				while (ny <= C - 1) {
					board[nx][ny] = board[nx][ny + 1];
					ny++;
				}

				while (nx + 1 <= clean[0].first) {
					board[nx][ny] = board[nx + 1][ny];
					nx++;
				}

				while (ny - 1 >= 2) {
					board[nx][ny] = board[nx][ny - 1];
					ny--;
				}
				board[nx][ny] = 0;
			}

			else {
				int nx = clean[1].first;
				int ny = clean[1].second;

				nx++;
				while (nx + 1 <= R) {
					board[nx][ny] = board[nx + 1][ny];
					nx++;
				}

				while (ny + 1 <= C) {
					board[nx][ny] = board[nx][ny + 1];
					ny++;
				}

				while (nx - 1 >= clean[1].first) {
					board[nx][ny] = board[nx - 1][ny];
					nx--;
				}

				while (ny - 1 >= 2) {
					board[nx][ny] = board[nx][ny - 1];
					ny--;
				}
				board[nx][ny] = 0;
			}
		}

		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				if (board[i][j] > 0) dust.push({ i,j });
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (board[i][j] > 0)
				ans += board[i][j];
		}
	}
	cout << ans;
}