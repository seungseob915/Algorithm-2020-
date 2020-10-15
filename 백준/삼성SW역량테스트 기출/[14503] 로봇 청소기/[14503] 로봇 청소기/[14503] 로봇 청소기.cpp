// [14503] 로봇 청소기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
using namespace std;

typedef struct Robot {
	int x, y, dir;
}R;
int board[50][50];
bool chk[50][50] = {};
int N, M, ans = 0;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
R r;

void simulate() {
	while (1) {
		//현재위치 청소
		ans++;
		chk[r.x][r.y] = true;

		int t = 4;

		bool go = false;
		//왼쪽방향을 기준으로 탐색
		while (t--) {
			r.dir--;
			if (r.dir == -1)
				r.dir = 3;

			int nx = r.x + dx[r.dir];
			int ny = r.y + dy[r.dir];

			//청소할 공간이 있으면
			if (chk[nx][ny] == false && board[nx][ny] == 0) {
				r.x = nx;
				r.y = ny;
				go = true;
				break;
			}
		}
		//갈곳이 없었다면
		if (!go) {
			if (board[r.x + dx[(r.dir + 2) % 4]][r.y + dy[(r.dir + 2) % 4]] == 1) {
				break;
			}
			r.x = r.x + dx[(r.dir + 2) % 4];
			r.y = r.y + dy[(r.dir + 2) % 4];
			ans--;
		}
	}
}

int main()
{
	cin >> N >> M;

	cin >> r.x >> r.y >> r.dir;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	simulate();

	cout << ans;
}
