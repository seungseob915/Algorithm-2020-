// [모의 SW 역량테스트] 핀볼 게임.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

typedef struct Pinball {
	int x, y, dir;
}P;
typedef struct WHall {
	int x, y;
}WH;

int board[101][101];
vector<WH> wh[11];
int N, T, Tcnt = 1, ans = 0;

int dx[] = { -1, 1, 0, 0 };	//상하좌우
int dy[] = { 0, 0, -1, 1 };

void Init() {
	ans = 0;
	memset(board, 0, sizeof(board));
	memset(wh, NULL, sizeof(wh));
}
int simulate(int r, int c, int d) {
	bool finish = false;
	int nowr = r, nowc = c, nowd = d;
	int nextr = r+dx[nowd], nextc = c+dy[nowd];
	int t_cnt = 0;
	
	if (nextr < 1 || nextr > N || nextc < 1 || nextc > N) {
		return 0;
	}

	// r,c 는 시작위치, 게임을 시작하지
	while (1) {
		nowr += dx[nowd];
		nowc += dy[nowd];

		//cout << "nowr: " << nowr << "nowc: " << nowc << "nowd: " << nowd << endl;

		//경계범위 초과시 (벽을 만났을때, 아무것도 없었을때)
		if (nowr < 1 || nowr > N || nowc < 1 || nowc > N) {
			t_cnt++;
			if (nowd % 2 == 0)
				nowd += 1;
			else
				nowd -= 1;
		}

		//블랙홀을 만나거나 원래위치에 돌아왔을때
		else if (board[nowr][nowc] == -1 || (nowr == r && nowc == c)) {
			break;
		}

		//웜홀을 만나면 반대편 웜홀로
		else if (board[nowr][nowc] >= 6) {
			int whx0 = wh[board[nowr][nowc]][0].x;
			int why0 = wh[board[nowr][nowc]][0].y;
			int whx1 = wh[board[nowr][nowc]][1].x;
			int why1 = wh[board[nowr][nowc]][1].y;

			if (whx0 == nowr && why0 == nowc) {
				nowr = whx1;
				nowc = why1;
			}
			else {
				nowr = whx0;
				nowc = why0;
			}
		}

		//정사각형을 만났을때
		else if (board[nowr][nowc] == 5) {
			if (nowd % 2 == 0)
				nowd += 1;
			else
				nowd -= 1;
			t_cnt++;
		}

		//삼각형을 만났을때
		else if(board[nowr][nowc] >= 1 && board[nowr][nowc] <=4){
			t_cnt++;
			bool re = true;

			if (board[nowr][nowc] == 1) {
				if (nowd == 1 || nowd == 2) {
					if (nowd == 1)
						nowd = 3;
					else
						nowd = 0;
					re = false;
				}
			}

			else if (board[nowr][nowc] == 2) {
				if (nowd == 0 || nowd == 2) {
					if (nowd == 0)
						nowd = 3;
					else
						nowd = 1;
					re = false;
				}
			}

			else if (board[nowr][nowc] == 3) {
				if (nowd == 0 || nowd == 3) {
					if (nowd == 0)
						nowd = 2;
					else
						nowd = 1;
					re = false;
				}
			}

			else{
				if (nowd == 3 || nowd == 1) {
					if (nowd == 3)
						nowd = 0;
					else
						nowd = 2;
					re = false;
				}
			}
			if (re) {
				if (nowd % 2 == 0)
					nowd += 1;
				else
					nowd -= 1;
			}

		}
	}
	return t_cnt;
}

int main()
{
	cin >> T;

	while (T--) {
		Init();

		cin >> N;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> board[i][j];
				if (board[i][j] >= 6) {
					wh[board[i][j]].push_back({ i, j });
				}
			}
		}
		int cnt = 0;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (board[i][j] == 0) {
					for (int k = 0; k < 4; k++) {
						ans = max(ans, simulate(i, j, k));
						//cout << cnt <<" "<<i<<" "<<j<< endl;
					}
				}
			}
		}
		cout << "#" <<Tcnt++<<" "<<ans<<endl;
	}
}

