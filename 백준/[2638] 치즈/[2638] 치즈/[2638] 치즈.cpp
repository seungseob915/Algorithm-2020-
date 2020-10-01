#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

int time = 0, N, M;
int board[100][100];
int cheese[100][100] = {};
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0, 0 };

typedef struct Location {
	int x, y;
}loc;

int main()
{
	cin >> N >> M;

	vector<loc> c;

	int chs_cnt = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) {
				c.push_back({ i, j });
				cheese[i][j] = 0;
				chs_cnt++;
			}
		}
	}

	
	while (1) {
		bool check[100][100] = {};
		memset(cheese, 0, sizeof(cheese));
		vector<loc> melt_c;

		if (chs_cnt == 0)
			break;

		time++;

		//공기와 진공 구분 i=0, N-1 일때, j=0, M-1
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (i == 0 || i == N - 1 || j == 0 || j == M - 1) {
					if (board[i][j] == 0 && check[i][j] == false) {
						queue<loc> q;
						q.push({ i, j });
						check[i][j] = true;

						while (!q.empty()) {
							loc now = q.front();
							q.pop();

							for (int k = 0; k < 4; k++) {
								loc next = { now.x + dx[k], now.y + dy[k] };
								// 경계범위 초과했을때
								if (next.x > N - 1 || next.x < 0 || next.y>M - 1 || next.y < 0) continue;
								// 체크가 true면
								if (check[next.x][next.y] == true) continue;
								// 치즈 라면
								if (board[next.x][next.y] == 1) {
									cheese[next.x][next.y]++;
									//치즈가 공기를 2접촉했으면
									if (cheese[next.x][next.y] == 2) {
										melt_c.push_back(next);
									}
									continue;
								}
								// 진공상태이면 (만나는거 자체가 이미 뚫렸다는 것이다)
								if (board[next.x][next.y] == -1) {
									board[next.x][next.y] = 0;
								}
								q.push(next);
								check[next.x][next.y] = true;
							}
						}
					}
				}
			}
		}


		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				// 진공인 놈들은
				if (board[i][j] == 0 && check[i][j] == false) {
					board[i][j] = -1;
				}
			}
		}

		// 치즈 한번에 녹이기
		for (int i = 0; i < melt_c.size(); i++) {
			board[melt_c[i].x][melt_c[i].y] = 0;
			chs_cnt--;
		}

	}
	cout << time;
}
