// [9663] N-Queen.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <memory.h>

using namespace std;

int N, ans = 0;
int board[16][16];	//0: 비어있다. 1: 오면안된다. 2: 누가 서있다.
int dx[] = { -1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,1,1,1,0,-1,-1,-1 };

bool move(int x, int y) {
	bool ret = true;

	for (int k = 0; k < 8; k++) {
		int ndir = k;
		int nx = x;
		int ny = y;

		while (1) {
			nx += dx[k];
			ny += dy[k];
			//만약 경계범위 벗어나면
			if (nx<1 || nx>N || ny<1 || ny>N)
				break;
			//만약 다른 체스가 서 있다면?
			if (board[nx][ny] == 2) {
				ret = false;
				break;
			}
			else if (board[nx][ny] == 0)
				board[nx][ny] = 1;
		}
		if (!ret) return false;
	}
	return ret;
}

void dfs(int depth, int finish) {
	if (depth == finish) {
		ans++;
		return;
	}

	for (int i = 1; i <= N; i++) {
		//만약 보드에 1 or 2이면 continue
		if (board[depth + 1][i] == 1 || board[depth + 1][i] == 2)
			continue;

		int t_board[16][16] = {};
		memcpy(t_board, board, sizeof(board));
		board[depth + 1][i] = 2;
		if (move(depth + 1, i)) {
			dfs(depth + 1, finish);
		}
		memcpy(board, t_board, sizeof(t_board));
	}
}

int main()
{
	cin >> N;

	//처음꺼 위치선정 및 체크 후 다시 제외
	for (int i = 1; i <= N; i++) {
		int t_board[16][16] = {};
		memcpy(t_board, board, sizeof(board));
		board[1][i] = 2;
		if (move(1, i))
			dfs(1, N);
		memcpy(board, t_board, sizeof(t_board));
	}
	cout << ans;
}
