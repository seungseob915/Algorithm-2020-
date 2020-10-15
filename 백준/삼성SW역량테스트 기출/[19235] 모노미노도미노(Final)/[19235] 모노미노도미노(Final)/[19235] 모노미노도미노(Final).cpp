#include <iostream>
#include <memory.h>
using namespace std;

typedef struct Order{
	int t, x, y;
}O;

int board1[6][4] = {};
int board2[4][6] = {};
bool chk1[6] = {};
bool chk2[6] = {};
int N, ans = 0;
O o[10001];

void BlockDown1() {
	for (int i = 2; i < 6; i++) {
		if (chk1[i]) {
			for (int j = 0; j < 4; j++)
				board1[i][j] = 0;
		}
	}

	//1칸씩 내려보자
	for (int i = 4; i >= 0; i--) {
		for (int j = 0; j < 4; j++) {
			if (board1[i][j] != 0) {
				//ㅡ일때
				if ((j != 3) && (board1[i][j] == board1[i][j + 1])) {
					int nx = i + 1;
					for (int k = i + 1; k <= 5; k++) {
						//밑이 다른 블록일 때
						if ((board1[k][j] != 0) || (board1[k][j + 1] != 0)) {
							nx = k - 1;
							break;
						}
						nx = k;
					}
					if (nx == i) {
						j++;
						continue;	//같은 위치이면
					}
					board1[nx][j] = board1[i][j];
					board1[nx][j + 1] = board1[i][j];
					board1[i][j] = 0;
					board1[i][j + 1] = 0;
					j++;
				}

				else {
					int nx = i + 1;
					for (int k = i + 1; k <= 5; k++) {
						//밑이 다른 블록일 때
						if (board1[k][j] != 0) {
							nx = k - 1;
							break;
						}
						nx = k;
					}
					if (nx == i) continue;	//같은 위치이면
					board1[nx][j] = board1[i][j];
					board1[i][j] = 0;
				}
			}
		}
	}
}

void BlockDown2() {
	for (int i = 2; i < 6; i++) {
		if (chk2[i]) {
			for (int j = 0; j < 4; j++)
				board2[j][i] = 0;
		}
	}

	//1칸씩 내려보자
	for (int i = 4; i >= 0; i--) {
		for (int j = 0; j < 4; j++) {
			if (board2[j][i] != 0) {
				//l일때
				if ((j != 3) && (board2[j][i] == board2[j + 1][i])) {
					int nx = i + 1;
					for (int k = i + 1; k <= 5; k++) {
						//밑이 다른 블록일 때
						if ((board2[j][k] != 0) || (board2[j + 1][k] != 0)) {
							nx = k - 1;
							break;
						}
						nx = k;
					}
					if (nx == i) {
						j++;
						continue;	//같은 위치이면
					}
					board2[j][nx] = board2[j][i];
					board2[j + 1][nx] = board2[j][i];
					board2[j][i] = 0;
					board2[j + 1][i] = 0;
					j++;
				}

				else {
					int nx = i + 1;
					for (int k = i + 1; k <= 5; k++) {
						//밑이 다른 블록일 때
						if (board2[j][k] != 0) {
							nx = k - 1;
							break;
						}
						nx = k;
					}
					if (nx == i) continue;	//같은 위치이면
					board2[j][nx] = board2[j][i];
					board2[j][i] = 0;
				}
			}
		}
	}
}

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> o[i].t >> o[i].x >> o[i].y;
	}

	int cnt = 1;

	while (cnt <= N) {
		int x = o[cnt].x;
		int y = o[cnt].y;
		int t = o[cnt].t;

		//@#@#@#@#@#@#@#@##@#@##@# 아래 보드 위에서부터
		for (int i = 2; i <= 6; i++) {
			// ㅡ 일때
			if (t == 2) {
				if (i == 6) {
					board1[5][y] = cnt;
					board1[5][y + 1] = cnt;
					break;
				}
				if (board1[i][y] != 0 || board1[i][y + 1] != 0) {
					board1[i - 1][y] = cnt;
					board1[i - 1][y + 1] = cnt;
					break;
				}
			}
			else {
				if (i == 6) {
					if (t == 3) {
						board1[5][y] = cnt;
						board1[4][y] = cnt;
					}
					else {
						board1[5][y] = cnt;
					}
					break;
				}
				if (board1[i][y] != 0) {
					if (t == 3) {
						board1[i - 1][y] = cnt;
						board1[i - 2][y] = cnt;
					}
					else {
						board1[i - 1][y] = cnt;
					}
					break;
				}
			}
		}

		//블록 내리자
		while (1) {
			while (1) {
				bool go = false;

				memset(chk1, false, sizeof(chk1));

				for (int i = 2; i < 6; i++) {
					if (board1[i][0] != 0 && board1[i][1] != 0 && board1[i][2] != 0 && board1[i][3] != 0) {
						chk1[i] = true;
						ans++;
						go = true;
					}
				}

				//블록제거 및 내려야됨 다시 처음부터
				if (go) {
					BlockDown1();
				}
				else {
					break;
				}
			}

			//다 제거했으면 0~1행사이에 숫자가 있는지 확인한다. 다시 겹치는거 있는지 확인
			memset(chk1, false, sizeof(chk1));

			int tcnt = 0;
			for (int i = 0; i < 2; i++) {
				if (board1[i][0] != 0 || board1[i][1] != 0 || board1[i][2] != 0 || board1[i][3] != 0)
					tcnt++;
			}
			if (tcnt == 0)
				break;
			else if (tcnt == 1) {
				chk1[5] = true;
				BlockDown1();
			}
			else {
				chk1[5] = true;
				chk1[4] = true;
				BlockDown1();
			}
		}

		//@#@#@#@#@#@#@#@##@#@##@# 옆 보드 위에서부터
		for (int i = 2; i <= 6; i++) {
			// ㅣ 일때
			if (t == 3) {
				if (i == 6) {
					board2[x][5] = cnt;
					board2[x + 1][5] = cnt;
					break;
				}
				if (board2[x][i] != 0 || board2[x + 1][i] != 0) {
					board2[x][i - 1] = cnt;
					board2[x + 1][i - 1] = cnt;
					break;
				}
			}
			else {
				if (i == 6) {
					if (t == 2) {
						board2[x][5] = cnt;
						board2[x][4] = cnt;
					}
					else {
						board2[x][5] = cnt;
					}
					break;
				}
				if (board2[x][i] != 0) {
					if (t == 2) {
						board2[x][i - 1] = cnt;
						board2[x][i - 2] = cnt;
					}
					else {
						board2[x][i - 1] = cnt;
					}
					break;
				}
			}
		}

		//블록 내리자
		while (1) {
			while (1) {
				bool go = false;

				memset(chk2, false, sizeof(chk2));

				for (int i = 2; i < 6; i++) {
					if (board2[0][i] > 0 && board2[1][i] > 0 && board2[2][i] > 0 && board2[3][i] != 0) {
						chk2[i] = true;
						ans++;
						go = true;
					}
				}

				//블록제거 및 내려야됨 다시 처음부터
				if (go) {
					BlockDown2();
				}
				else {
					break;
				}
			}

			//다 제거했으면 0~1행사이에 숫자가 있는지 확인한다. 다시 겹치는거 있는지 확인
			memset(chk2, false, sizeof(chk2));

			int tcnt = 0;
			for (int i = 0; i < 2; i++) {
				if (board2[0][i] > 0 || board2[1][i] > 0 || board2[2][i] > 0 || board2[3][i] > 0)
					tcnt++;
			}
			if (tcnt == 0)
				break;
			else if (tcnt == 1) {
				chk2[5] = true;
				BlockDown2();
			}
			else {
				chk2[5] = true;
				chk2[4] = true;
				BlockDown2();
			}
		}
		cnt++;
	}

	int b_cnt = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			if (board1[i][j] > 0) b_cnt++;
			if (board2[j][i] > 0) b_cnt++;
		}
	}

	cout << ans << endl;
	cout << b_cnt << endl;
}