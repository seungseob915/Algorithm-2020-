// [15684] 사다리 조작.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>

using namespace std;

int board[32][11];
int N, M, H, ans=987654321;

bool simulate() {
	bool ret = true;

	for (int start = 1; start <= N; start++) {
		pair<int, int> now = { 0, start };

		while (1) {
			if (now.first == H + 1) {
				if (now.second != start)
					ret = false;
				break;
			}

			//1칸 내려가자
			now.first++;
			
			//오른쪽 연결 되어있으면
			if (board[now.first][now.second] == 1) {
				now.second++;
			}
			//왼쪽 연결되어 있으면
			else if (board[now.first][now.second] == 2) {
				now.second--;
			}
		}
		if (ret == false)
			return ret;
	}
	return ret;
}

void dfs(int depth, int x) {
	if (depth >= ans) {
		return;
	}

	if (depth == 3) {
		if (simulate())
			ans = 3;
		return;
	}

	//할때마다 검사해보자
	if (simulate()) {
		ans = min(ans, depth);
		return;
	}

	// 설치
	for (int i = x; i <= H; i++) {
		for (int j = 1; j <= N - 1; j++) {
			// 이미 설치되어있으면
			if (board[i][j] == 1 || board[i][j] == 2 || board[i][j+1]==1 || board[i][j+1]==2)
				continue;

			board[i][j] = 1;
			board[i][j + 1] = 2;
			//설치할수 있으면
			dfs(depth + 1, i);
			board[i][j] = 0;
			board[i][j + 1] = 0;
		}
	}
}

int main()
{
	cin >> N >> M >> H;

	for (int i = 0; i < M; i++) {
		pair<int, int> temp;
		cin >> temp.first >> temp.second;

		board[temp.first][temp.second] = 1;
		board[temp.first][temp.second+1] = 2;
	}

	// 설치
	dfs(0, 1);

	if (ans == 987654321)
		ans = -1;

	cout << ans;
}
