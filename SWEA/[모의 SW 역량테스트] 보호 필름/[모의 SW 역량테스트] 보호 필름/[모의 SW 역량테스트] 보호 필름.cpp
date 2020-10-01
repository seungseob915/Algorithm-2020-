// [모의 SW 역량테스트] 보호 필름.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;

int board[14][21];
int order[14];
bool check[14];
bool finish[21] = {};
int D, W, K, T, Tcnt = 1, t_ans = false, ans = 987654321;

void Init() {
	memset(board, 0, sizeof(board));
	memset(order, -1, sizeof(order));
	t_ans = false;
	ans = 987654321;
}

// 완료시 true 반환해준다
bool simulate(int brd[][21]) {
	int k = 1;
	for (int i = 1; i <= W; i++) {
		for (int j = 1; j <= D; j++) {
			if (j + 1 <= D) {
				if (brd[j][i] == brd[j + 1][i]) {
					k = k + 1;
					if (k == K)
						break;
				}
				else
					k = 1;
			}
		}
		if (k != K)
			return false;
		else
			k = 1;
	}
	return true;
}

bool paint() {
	int tmap[14][21];
	memcpy(tmap, board, sizeof(board));

	for (int i = 1; i <= D; i++) {
		if (order[i] == -1) {
			continue;
		}

		for (int j = 1; j <= W; j++) {
			tmap[i][j] = order[i];
		}
	}

	bool result = simulate(tmap);

	return result;
}

void dfs(int now, int depth) {
	if (t_ans == true)
		return;
	if (now > depth) {
		if (paint())
			t_ans = true;
		return;
	}


	for (int i = 1; i <= D; i++) {
		if (check[i] == true)
			continue;
		for (int j = 0; j < 2; j++) {
			order[i] = j;
			check[i] = true;
			dfs(now + 1, depth);
			order[i] = -1;
			check[i] = false;
		}
	}
}


int main()
{
	cin >> T;

	while (T--) {
		Init();

		cin >> D >> W >> K;

		for (int i = 1; i <= D; i++) {
			for (int j = 1; j <= W; j++) {
				cin >> board[i][j];
			}
		}

		if (simulate(board)) {
			ans = 0;
		}

		else {
			for (int depth = 1; depth < K; depth++) {
				dfs(1, depth);
				if (t_ans) {
					ans = depth;
					break;
				}
			}
			if (!t_ans)
				ans = K;
		}

		cout << "#" << Tcnt++ << " " << ans << endl;
	}
}

