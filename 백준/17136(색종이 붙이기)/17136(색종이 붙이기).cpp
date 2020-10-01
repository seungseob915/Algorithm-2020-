// 17136(색종이 붙이기).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>

using namespace std;

int board[11][11];	//보드판
bool check[11][11];	//체크배열

int color_p[6] = { 0, 5, 5, 5, 5, 5 };	//색종이 갯수

int need = 0;	// 1의 갯수
int t_need = 0;

int ans = -1;	// 정답
int t_ans;	// 정답

bool puzzle(int i, int j, int k) {
	bool run = false;

	if (k == 1) {
		if (color_p[k] == 0)
			return false;

		check[i][j] = true;
		t_need++;
		color_p[k]--;
		run = true;
	}
	else if (k == 2) {
		if (i + 1 < 10 && j + 1 < 10 ) {
			for (int t = 0; t < 2; t++) {
				for (int u = 0; u < 2; u++) {
					if (board[i + t][j + u] == 0 || check[i + t][j + u] == true || color_p[k] == 0)
						return false;
				}
			}
			for (int t = 0; t < 2; t++) {
				for (int u = 0; u < 2; u++) {
					check[i + t][j + u] = true;
					t_need++;
				}
			}
			color_p[k]--;
			run = true;
		}
	}
	else if (k == 3) {
		if (i + 2 < 10 && j + 2 < 10) {
			for (int t = 0; t < 3; t++) {
				for (int u = 0; u < 3; u++) {
					if (board[i + t][j + u] == 0 || check[i + t][j + u] == true || color_p[k] == 0)
						return false;
				}
			}
			for (int t = 0; t < 3; t++) {
				for (int u = 0; u < 3; u++) {
					check[i + t][j + u] = true;
					t_need++;
				}
			}
			color_p[k]--;
			run = true;
		}
	}
	else if (k == 4) {
		if (i + 3 < 10 && j + 3 < 10) {
			for (int t = 0; t < 4; t++) {
				for (int u = 0; u < 4; u++) {
					if (board[i + t][j + u] == 0 || check[i + t][j + u] == true || color_p[k] == 0)
						return false;
				}
			}
			for (int t = 0; t < 4; t++) {
				for (int u = 0; u < 4; u++) {
					check[i + t][j + u] = true;
					t_need++;
				}
			}
			color_p[k]--;
			run = true;
		}
	}
	else{
		if (i + 4 < 10 && j + 4 < 10) {
			for (int t = 0; t < 5; t++) {
				for (int u = 0; u < 5; u++) {
					if (board[i + t][j + u] == 0 || check[i + t][j + u] == true || color_p[k] == 0)
						return false;
				}
			}
			for (int t = 0; t < 5; t++) {
				for (int u = 0; u < 5; u++) {
					check[i + t][j + u] = true;
					t_need++;
				}
			}
			color_p[k]--;
			run = true;
		}
	}
	return run;
}


void cycle(int x, int y, int tt_need) {
	// 다 덮었을때 종료
	if (tt_need == need) {
		if (ans != -1 && t_ans!=-1)
				ans = min(ans, t_ans);
		else if(ans==-1 && t_ans!=-1)
				ans = t_ans;
		return;
	}

	for (int i = x; i < 10; i++) {
		for (int j = y; j < 10; j++) {
			if (board[i][j] == 1 && check[i][j]==false) {
				for (int k = 1; k < 6; k++) {
					if (puzzle(i, j, k)) {
						cycle(i, j + k, k);
						b_cycle(i, j + k, k);
					}

					else {
						t_ans = -1;
						return;
					}
				}
			}
		}
	}
}


int main()
{
	//10x10 보드
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> board[i][j];
			
			if (board[i][j] == 1)
				need++;
		}
	}
	
	cycle(, );

	cout << ans;
}
