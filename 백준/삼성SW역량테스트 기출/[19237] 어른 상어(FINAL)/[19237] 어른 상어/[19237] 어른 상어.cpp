// [19237] 어른 상어.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

typedef struct Shark {
	int x, y, dir;
	bool dead;
}S;

int N, M, K;
pair<int, int> board[21][21] = {};
S s[401] = {};
int dir[401][5][5] = {};
int dx[] = { 0,-1,1,0,0 };
int dy[] = { 0,0,0,-1,1 };

int main()
{
	cin >> N>>M>>K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j].first;
			if (board[i][j].first != 0) {
				s[board[i][j].first].x = i;
				s[board[i][j].first].y = j;
				s[board[i][j].first].dead = false;
				board[i][j].second = K;
				continue;
			}
			board[i][j].second = 0;
		}
	}
	for (int i = 1; i <= M; i++)
		cin >> s[i].dir;

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int k = 1; k <= 4; k++) {
				cin >> dir[i][j][k];
			}
		}
	}

	int t = 0;

	while (t <= 1000) {
		bool finish = true;
		for (int i = 2; i <= M; i++) {
			if (s[i].dead==false) {
				finish = false;
				break;
			}
		}

		if (finish) break;

		for (int i = 1; i <= M; i++) {
			if (s[i].dead) continue;

			int x = s[i].x;
			int y = s[i].y;
			int d = s[i].dir;
			
			bool flag = false;
			for (int k = 1; k <= 4; k++) {
				int nd = dir[i][d][k];
				int nx = x + dx[nd];
				int ny = y + dy[nd];
				if (nx<1 || nx>N || ny<1 || ny>N) continue;
				if (board[nx][ny].first != 0) continue;
				// 이번턴에 상어만나는것(이미 번호낮은놈이 점령했을때)
				if (board[nx][ny].second == K + 1) {
					s[i].dead = true;
					flag = true;
					break;
				}
				s[i].x = nx;
				s[i].y = ny;
				s[i].dir = nd;
				//board[nx][ny].first = i;	//번호는 나중에 최종적으로 매기자
				board[nx][ny].second = K+1;
				flag = true;
				break;
			}
			//자신의 냄새가 있던칸으로
			if (!flag) {
				for (int k = 1; k <= 4; k++) {
					int nd = dir[i][d][k];
					int nx = x + dx[nd];
					int ny = y + dy[nd];
					if (nx<1 || nx>N || ny<1 || ny>N) continue;
					if (board[nx][ny].first == i) {
						s[i].x = nx;
						s[i].y = ny;
						s[i].dir = nd;
						board[nx][ny].second = K + 1;
						break;
					}
				}
			}
		}

		for (int i = 1; i <= M; i++) {
			if (s[i].dead)continue;
			board[s[i].x][s[i].y].first = i;
		}

		//냄새 줄이기
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (board[i][j].first == 0) continue;
				board[i][j].second--;
				if (board[i][j].second == 0) board[i][j].first = 0;
			}
		}
		t++;
	}

	if (t == 1001) t = -1;
	cout << t;
}
