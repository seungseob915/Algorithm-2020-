// [17281] 야구공.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
using namespace std;

int N, ans = 0;
int player[10][51];
int order[10];  //타순
bool chk[10];   //선수가 선택됐는지 여부

int play() {
	int nxt_player = 1;
	int score = 0;

	//1이닝 부터 N이닝 까지
	for (int i = 1; i <= N; i++) {
		//타순
		int out = 3;
		int base[4] = {};

		while (out) {
			//out이면
			if (player[order[nxt_player]][i] == 0) out--;
			else if (player[order[nxt_player]][i] == 1) {
				for (int i = 3; i >= 1; i--) {
					if (i == 3 && base[i] == 1) {
						score++;
						base[3] = 0;
						continue;
					}
					if (base[i] == 1) {
						base[i+1] = 1;
						base[i] = 0;
					}
				}
				base[1] = 1;
			}
			else if (player[order[nxt_player]][i] == 2) {
				for (int i = 3; i >= 1; i--) {
					if (base[i]==1 && (i==3 || i==2)) {
						score++;
						base[i] = 0;
						continue;
					}
					if (base[i] == 1) {
						base[i + 2] = 1;
						base[i] = 0;
					}
				}
				base[2] = 1;
			}
			else if (player[order[nxt_player]][i] == 3) {
				for (int i = 3; i >= 1; i--) {
					if (base[i] == 1) {
						score++;
						base[i] = 0;
					}
				}
				base[3] = 1;
			}
			else {
				for (int i = 3; i >= 1; i--) {
					if (base[i] == 1) {
						score++;
						base[i] = 0;
					}
				}
				score++;
			}

			nxt_player++;
			if (nxt_player == 10)
				nxt_player = 1;
		}
	}
	return score;
}

void dfs(int depth) {
	if (depth == 10) {
		ans = max(ans, play());
		return;
	}
	if (depth == 4) {
		dfs(depth + 1);
	}
	else {
		for (int i = 2; i <= 9; i++) {
			if (chk[i]) continue;

			order[depth] = i;
			chk[i] = true;

			dfs(depth + 1);

			order[depth] = 0;
			chk[i] = false;
		}
	}
}

int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> player[j][i];
		}
	}

	order[4] = 1;
	chk[1] = true;

	dfs(1);

	cout << ans;
}