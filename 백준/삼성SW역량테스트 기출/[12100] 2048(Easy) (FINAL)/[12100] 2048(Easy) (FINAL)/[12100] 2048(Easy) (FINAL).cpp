// [12100] 2048(Easy) (FINAL).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

int N, ans=0;
int board[21][21] = {};
bool chk[21][21] = {};

void simulate(int k) {
	memset(chk, false, sizeof(chk));

	//위
	if (k == 1) {
		//밑에칸부터 올라간다잉
		for (int i = 2; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (board[i][j] == 0) continue;
				
				int row = i;	//시작지점

				for (int r = i - 1; r >= 1; r--) {
					if (board[r][j] != 0) {
						//숫자가 같으면(chk처리해줘야된다)
						if (chk[r][j]==false && (board[r][j] == board[i][j])) {
							board[r][j] *= 2;
							board[i][j] = 0;
							chk[r][j] = true;
						}
						else {
							if (row == r+1) break;
							board[r + 1][j] = board[i][j];
							board[i][j] = 0;
						}
						break;
					}
					if (r == 1) {
						board[1][j] = board[i][j];
						board[i][j] = 0;
					}
				}
			}
		}
	}
	//아래
	else if (k == 2) {
		//밑에칸부터 올라간다잉
		for (int i = N-1; i >= 1; i--) {
			for (int j = 1; j <= N; j++) {
				if (board[i][j] == 0) continue;

				int row = i;	//시작지점

				for (int r = i + 1; r <= N; r++) {
					if (board[r][j] != 0) {
						//숫자가 같으면(chk처리해줘야된다)
						if (chk[r][j] == false && (board[r][j] == board[i][j])) {
							board[r][j] *= 2;
							board[i][j] = 0;
							chk[r][j] = true;
						}
						else {
							if (row == r - 1) break;
							board[r - 1][j] = board[i][j];
							board[i][j] = 0;
						}
						break;
					}
					if (r == N) {
						board[N][j] = board[i][j];
						board[i][j] = 0;
					}
				}
			}
		}
	}
	//왼쪽
	else if (k == 3) {
		for (int j = 2; j <= N; j++) {
			for (int i = 1; i <= N; i++) {
				if (board[i][j] == 0) continue;

				int col = j;	//시작지점

				for (int c = j - 1; c >= 1; c--) {
					if (board[i][c] != 0) {
						//숫자가 같으면(chk처리해줘야된다)
						if (chk[i][c] == false && (board[i][c] == board[i][j])) {
							board[i][c] *= 2;
							board[i][j] = 0;
							chk[i][c] = true;
						}
						else {
							if (col == c + 1) break;
							board[i][c + 1] = board[i][j];
							board[i][j] = 0;
						}
						break;
					}
					if (c == 1) {
						board[i][1] = board[i][j];
						board[i][j] = 0;
					}
				}
			}
		}
	}
	else {
		for (int j = N-1; j >= 1; j--) {
			for (int i = 1; i <= N; i++) {
				if (board[i][j] == 0) continue;

				int col = j;	//시작지점

				for (int c = j + 1; c <= N; c++) {
					if (board[i][c] != 0) {
						//숫자가 같으면(chk처리해줘야된다)
						if (chk[i][c] == false && (board[i][c] == board[i][j])) {
							board[i][c] *= 2;
							board[i][j] = 0;
							chk[i][c] = true;
						}
						else {
							if (col == c - 1) break;
							board[i][c - 1] = board[i][j];
							board[i][j] = 0;
						}
						break;
					}
					if (c == N) {
						board[i][N] = board[i][j];
						board[i][j] = 0;
					}
				}
			}
		}
	}
}

void dfs(int depth) {
	if (depth == 5) {
		for(int i=1; i<=N; i++){
			for (int j = 1; j <= N; j++) {
				ans = max(ans, board[i][j]);
			}
		}
		return;
	}

	int t_board[21][21] = {};
	memcpy(t_board, board, sizeof(board));

	//방향설정
	for (int k = 1; k <= 4; k++) {
		simulate(k);
		dfs(depth + 1);
		memcpy(board, t_board, sizeof(t_board));
	}
}

int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
		}
	}
	
	dfs(0);

	cout << ans;
}
