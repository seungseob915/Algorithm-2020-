// [17837] 새로운 게임 2(Final).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef struct Horse {
	int x, y, dir;
}H;

int N, K;
int board[13][13][11] = { 0, };
int chk[13][13] = { 0, };
H h[11] = {};
int dx[] = { 0,0,0,-1,1 };
int dy[] = { 0,1,-1,0,0 };

int main()
{
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j][0];
		}
	}

	for (int i = 1; i <= K; i++) {
		cin >> h[i].x >> h[i].y >> h[i].dir;
		for (int j = 1; j <= K; j++) {
			if (board[h[i].x][h[i].y][j] != 0) continue;
			board[h[i].x][h[i].y][j] = i;
			break;
		}
		chk[h[i].x][h[i].y]++;
	}

	int cnt = 0;

	while (cnt <= 1000) {
		bool finish = false;

		//말 1번부터 K번까지 움직이자
		for (int i = 1; i <= K; i++) {
			int x = h[i].x;
			int y = h[i].y;
			int d = h[i].dir;

			deque<int> q;
			bool psh = false;

			for (int j = 1; j <= K; j++) {
				if (board[x][y][j] == 0) break;
				if (board[x][y][j] == i) {
					psh = true;
					q.push_back(board[x][y][j]);
					board[x][y][j] = 0;
					chk[x][y]--;
				}
				else if (psh) {
					q.push_back(board[x][y][j]);
					board[x][y][j] = 0;
					chk[x][y]--;
				}
			}


			//deque에 저장했음 다음칸 가보자
			int nx = x + dx[d];
			int ny = y + dy[d];

			// 파란색 or 경계일떄
			if (nx<1 || nx>N || ny<1 || ny>N || board[nx][ny][0] == 2) {
				if (d % 2 == 0) d--;
				else d++;

				nx = x + dx[d];
				ny = y + dy[d];

				//다음칸도 파란색 or 경계이면 보드 위치 저장해주고 continue;
				if (nx<1 || nx>N || ny<1 || ny>N || board[nx][ny][0] == 2) {
					h[i].x = x;
					h[i].y = y;
					h[i].dir = d;

					while (!q.empty()) {
						int temp=q.front();
						q.pop_front();
						h[temp].x = x;
						h[temp].y = y;
						chk[x][y]++;

						for (int j = 1; j <= K; j++) {
							if (board[x][y][j] != 0) continue;
							board[x][y][j] = temp;
							break;
						}
					}
					continue;
				}
			}

			//빨갱이이면
			if (board[nx][ny][0] == 1) {
				h[i].x = nx;
				h[i].y = ny;
				h[i].dir = d;

				while (!q.empty()) {
					int temp = q.back();
					q.pop_back();
					h[temp].x = nx;
					h[temp].y = ny;
					chk[nx][ny]++;

					for (int j = 1; j <= K; j++) {
						if (board[nx][ny][j] != 0) continue;
						board[nx][ny][j] = temp;
						break;
					}
				}
			}

			//하양이면
			else {
				h[i].x = nx;
				h[i].y = ny;
				h[i].dir = d;

				while (!q.empty()) {
					int temp = q.front();
					q.pop_front();
					h[temp].x = nx;
					h[temp].y = ny;
					chk[nx][ny]++;

					for (int j = 1; j <= K; j++) {
						if (board[nx][ny][j] != 0) continue;
						board[nx][ny][j] = temp;
						break;
					}
				}
			}

			//말움직일때마다 끝났는지 확인해줘야한다.
			for (int xx = 1; xx <= N; xx++) {
				for (int yy = 1; yy <= N; yy++) {
					if (chk[xx][yy] >= 4) {
						finish = true;
						break;
					}
				}
			}
			if (finish)break;
		}

		cnt++;
		if (finish)break;
	}

	if (cnt > 1000) cnt = -1;

	cout << cnt;
}