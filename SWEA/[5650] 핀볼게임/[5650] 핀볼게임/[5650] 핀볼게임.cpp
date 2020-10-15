// [5650] 핀볼게임.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

typedef struct Pinball {
	int x, y, dir;
}P;

int T, Tcnt = 1, N, ans=0;
pair<int, int> WH[11][2];	//화이트홀	<쌍으로 인한 생성>
P p;
int board[102][102];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

void Init() {
	memset(board, 0, sizeof(board));
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 2; j++) {
			WH[i][j].first = 0;
			WH[i][j].second = 0;
		}
	}
	p = { 0,0,0 };
	ans = 0;
}

void simulate(int sx, int sy, int dir) {
	p = { sx, sy, dir };
	int score = 0;

	//게임시작...
	while (1) {
		// 다음위치
		int nx = p.x + dx[p.dir];
		int ny = p.y + dy[p.dir];
		
		// 벽에 부딪힐때 점수 1점
		if (nx<1 || nx>N || ny<1 || ny>N) {
			score++;
			//방향전환
			if (p.dir % 2 == 0)	p.dir++;
			else p.dir--;
		}

		// 블랙홀이면 게임종료
		else if (board[nx][ny] == -1) break;

		// 시작위치여도 게임종료
		else if (nx == sx && ny == sy) break;
		
		//화이트홀일떄
		else if (board[nx][ny] >= 6 && board[nx][ny] <= 10) {
			int wnum = board[nx][ny];

			if (WH[wnum][0].first == nx && WH[wnum][0].second == ny) {
				nx = WH[wnum][1].first;
				ny = WH[wnum][1].second;
			}
			else {
				nx = WH[wnum][0].first;
				ny = WH[wnum][0].second;
			}
		}

		//벽돌일때
		else if (board[nx][ny]>=1 && board[nx][ny] <= 5) {
			if (board[nx][ny] == 1) {
				if (p.dir == 0 || p.dir == 2) {
					//방향전환
					if (p.dir % 2 == 0)	p.dir++;
					else p.dir--;
				}
				else if (p.dir == 3) {
					p.dir = 0;
				}
				else {
					p.dir = 2;
				}
			}
			else if (board[nx][ny] == 2) {
				if (p.dir == 2 || p.dir == 1) {
					//방향전환
					if (p.dir % 2 == 0)	p.dir++;
					else p.dir--;
				}
				else if (p.dir == 0) {
					p.dir = 2;
				}
				else {
					p.dir = 1;
				}
			}
			else if (board[nx][ny] == 3) {
				if (p.dir == 1 || p.dir == 3) {
					//방향전환
					if (p.dir % 2 == 0)	p.dir++;
					else p.dir--;
				}
				else if (p.dir == 2) {
					p.dir = 1;
				}
				else {
					p.dir = 3;
				}
			}
			else if (board[nx][ny] == 4) {
				if (p.dir == 0 || p.dir == 3) {
					//방향전환
					if (p.dir % 2 == 0)	p.dir++;
					else p.dir--;
				}
				else if (p.dir == 2) {
					p.dir = 0;
;				}
				else {
					p.dir = 3;
				}
			}
			else{
				//방향전환
				if (p.dir % 2 == 0)	p.dir++;
				else p.dir--;
			}
			score++;
		}

		p.x = nx;
		p.y = ny;
	}

	ans = max(ans, score);
}

int main()
{
	cin >> T;

	while (T--) {
		Init();

		cin >> N;

		int w_cnt = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> board[i][j];

				if (board[i][j] >= 6 && board[i][j] <= 10) {
					if(WH[board[i][j]][0].first!=0 || WH[board[i][j]][0].second != 0)
						WH[board[i][j]][1] = make_pair(i, j);
					else
						WH[board[i][j]][0] = make_pair(i, j);
				}
			}
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				for (int k = 0; k < 4; k++) {
					if (board[i][j] == 0)
						simulate(i, j, k);
				}
			}
		}
		cout << "#" << Tcnt++ << ' ' << ans << endl;
	}
}