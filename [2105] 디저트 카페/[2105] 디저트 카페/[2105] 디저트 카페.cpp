// [2105] 디저트 카페.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <memory.h>
using namespace std;

int T, N, ans=-1;
int board[21][21];
int t_board[21][21];
bool chk[101];

void init() {
	memset(board, 0, sizeof(board));
	memset(chk, false, sizeof(chk));
	ans = -1;
}

int main()
{
	cin >> T;
	int Tcnt = 1;

	while (T--) {
		init();
		
		cin >> N;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> board[i][j];
			}
		}

		for (int x = 1; x <= N - 2; x++) {
			for (int y = 2; y <= N - 1; y++) {
				for (int d1 = 1; y - d1 >= 1; d1++) {
					for (int d2 = 1; y + d2 <= N && x + d1 + d2 <= N; d2++) {
						memset(chk, false, sizeof(chk));

						bool go = true;
						int temp = 0;

						for (int i = 0; i <= d1; i++) {
							if (chk[board[x + i][y - i]]) {
								go = false;
								break;
							}
							chk[board[x + i][y - i]]=true;
							temp++;
						}

						for (int i = 1; i <= d2; i++) {
							if (go==false || chk[board[x + i][y + i]]==true) {
								go = false;
								break;
							}
							chk[board[x + i][y + i]] = true;
							temp++;
						}

						for (int i = 1; i <= d2; i++) {
							if (go == false || chk[board[x + d1 + i][y - d1 + i]]==true) {
								go = false;
								break;
							}
							chk[board[x + d1+ i][y -d1 + i]]=true;
							temp++;
						}

						for (int i = 1; i < d1; i++) {
							if (go == false || chk[board[x + d2 + i][y + d2 - i]] == true) {
								go = false;
								break;
							}
							chk[board[x + d2 + i][y + d2 - i]]=true;
							temp++;
						}
						if (!go) continue;

						if (ans < temp)
							ans = temp;
					}
				}
			}
		}
		cout << "#" << Tcnt++ << ' ' << ans << endl;
	}
}

