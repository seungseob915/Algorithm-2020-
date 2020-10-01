// [1261] 알고스팟.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

int N, M, ans = 987654321;
int board[101][101];
int b_cnt[101][101];
bool chk[101][101];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

void dfs(int x, int y, int wall) {
	//현재 블럭갯수가 최소보다 많을때 return
	if (wall >= b_cnt[x][y])
		return;
	else
		b_cnt[x][y] = wall;

	// depth가 다됐을때
	if (x == N && y == M) {
		ans = min(ans, wall);
		return;
	}

	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];

		//경계범위
		if (nx<1 || nx>N || ny<1 || ny>M) continue;
		if (chk[nx][ny]) continue;
		chk[nx][ny] = true;
		dfs(nx, ny, wall+(board[nx][ny]==1 ? 1:0));
		chk[nx][ny] = false;
	}
}


int main()
{
	cin >> M >> N;
	

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf_s("%1d", &board[i][j]);
			b_cnt[i][j] = 987654321;
		}
	}
	chk[1][1] = true;
	dfs(1, 1, 0);

	cout << b_cnt[N][M];
}
