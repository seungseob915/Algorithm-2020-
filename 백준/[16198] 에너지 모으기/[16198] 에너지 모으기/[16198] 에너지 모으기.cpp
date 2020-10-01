// [16198] 에너지 모으기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
using namespace std;

int N, ans = 0;
int board[11];
bool chk[11];

void dfs(int depth, int weight) {
	if (depth == N - 2) {
		ans = max(ans, weight);
		return;
	}

	for (int i = 2; i <= N - 1; i++) {
		if (chk[i]) continue;

		chk[i] = true;
		int uw=0, dw = 0;
		for (int k = i + 1; k <= N; k++) {
			if (chk[k])	continue;
			uw = board[k];
			break;
		}
		for (int k = i - 1; k >= 1; k--) {
			if (chk[k])	continue;
			dw = board[k];
			break;
		}
		dfs(depth + 1, weight + uw*dw);
		chk[i] = false;
	}
}


int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> board[i];
	}

	dfs(0, 0);

	cout << ans;
}
