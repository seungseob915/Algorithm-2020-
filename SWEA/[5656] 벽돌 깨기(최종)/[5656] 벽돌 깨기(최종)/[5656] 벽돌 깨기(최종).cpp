// [5656] 벽돌 깨기(최종).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

typedef struct Block {
	int x, y, size;
}B;
int N, H, W, T, Tcnt = 1, ans = 0;
int board[17][13];
bool chk[17][13] = {};
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void Init() {
	memset(board, 0, sizeof(board));
	memset(chk, false, sizeof(chk));
	ans = 0;
}

int simulate(int col) {
	int row = -1;
	int ret = 0;

	for (int i = 1; i <= H; i++) {
		if (board[i][col] != 0) {
			row = i;
			break;
		}
	}

	// 떨어뜨렸는데 벽돌없을때는?
	if (row == -1)
		return ret;
	
	queue<B> q;

	q.push({ row, col, board[row][col] - 1 });
	chk[row][col] = true;

	while (!q.empty()) {
		B now = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {
			for (int d = 1; d <= now.size; d++) {
				int nx = now.x + dx[k] * d;
				int ny = now.y + dy[k] * d;

				if (nx<1 || nx>H || ny<1 || ny>W) continue;
				if (chk[nx][ny]) continue;
				if (board[nx][ny] > 1) {
					q.push({ nx, ny, board[nx][ny] - 1 });
				}
				chk[nx][ny] = true;
			}
		}
	}

	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			if (chk[i][j]) {
				if (board[i][j] != 0)
					ret++;
				board[i][j] = 0;
				chk[i][j] = false;
			}
		}
	}

	for (int j = 1; j <= W; j++) {
		for (int i = H; i >= 2; i--) {
			if (board[i][j] == 0) {
				for (int k = i - 1; k >= 1; k--) {
					if (board[k][j] != 0) {
						board[i][j] = board[k][j];
						board[k][j] = 0;
						break;
					}
				}
			}
		}
	}
	return ret;
}

void dfs(int depth, int score) {
	if (depth == N) {
		ans = max(ans, score);
		return;
	}

	int t_board[17][13];
	memcpy(t_board, board, sizeof(board));

	for (int i = 1; i <= W; i++) {
		int s = simulate(i);
		dfs(depth + 1, score + s);
		memcpy(board, t_board, sizeof(t_board));
	}
}

int main()
{
	cin >> T;

	while (T--) {
		Init();

		cin >> N >> W >> H;
		int total = 0;
		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) {
				cin >> board[i][j];
				if (board[i][j] > 0)
					total++;
			}
		}

		dfs(0, 0);

		cout << "#" << Tcnt++ << ' ' <<  total-ans << endl;
	}
}
