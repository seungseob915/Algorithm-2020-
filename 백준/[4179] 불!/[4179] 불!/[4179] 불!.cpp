// [4179] 불!.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
using namespace std;

typedef struct Jihun {
	int x, y;
}J;

int board[1001][1001];	// 빈칸: -1, 벽돌:-2,
int chk[1001][1001];
int R, C, time = 987654321;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

queue<pair<int, int>> q;
queue<pair<int, int>> jh;

int main()
{
	cin >> R >> C;

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			chk[i][j] = -1;	//메모리 초기화

			char temp;
			cin >> temp;
			if (temp == '#')
				board[i][j] = -2;
			else if (temp == '.')
				board[i][j] = -1;
			else if (temp == 'J') {
				board[i][j] = -1;
				jh.push({ i, j });
				chk[i][j] = 0;	// 1부터 시작하자 (사실은 0초임)
			}
			else {
				board[i][j] = 0;
				q.push({ i, j });
			}
		}
	}

	//불 내자 FIRE
	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = now.first + dx[k];
			int ny = now.second + dy[k];

			if (nx<1 || nx> R || ny<1 || ny>C) continue;
			if (board[nx][ny] == -1) {
				q.push({ nx, ny });
				board[nx][ny] = board[now.first][now.second] + 1;
			}
		}
	}

	bool finish = false;

	while (!jh.empty()) {
		if (finish) break;

		pair<int, int> now = jh.front();
		jh.pop();
	
		for (int k = 0; k < 4; k++) {
			int nx = now.first + dx[k];
			int ny = now.second + dy[k];

			//탈출 성공
			if (nx<1 || nx> R || ny<1 || ny>C) {
				time = chk[now.first][now.second] + 1;
				finish = true;
				break;
			}
			if (chk[nx][ny] != -1) continue;
			if (board[nx][ny] == -2) continue;
			if (board[nx][ny] >= 0 && (chk[now.first][now.second] + 1 >= board[nx][ny])) continue;

			jh.push({ nx, ny });
			chk[nx][ny] = chk[now.first][now.second] + 1;
		}
	}

	if (time == 987654321) {
		cout << "IMPOSSIBLE";
		return 0;
	}
	cout << time;
}
