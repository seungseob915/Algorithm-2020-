// [15686] 치킨 배달.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>

using namespace std;

int N, M, ans = 987654321;
int h_cnt = 0, c_cnt = 0;
int board[51][51];
pair<int, int> home[101];
pair<int, int> chick[14];
bool chk[14];

int calc() {
	//최소거리 계산
	int t_ans = 0;

	for (int i = 1; i <= h_cnt; i++) {
		int t = 987654321;
		for (int j = 1; j <= c_cnt; j++) {
			if (!chk[j]) continue;
			int x=abs(home[i].first - chick[j].first);
			int y=abs(home[i].second - chick[j].second);
			
			t = min(t, x + y);
		}
		t_ans += t;
	}
	return t_ans;
}

void dfs(int depth, int idx) {
	if (depth == M) {
		ans=min(ans, calc());
		return;
	}

	for (int i = idx+1; i <= c_cnt; i++) {
		if (chk[i]) continue;
;		chk[i] = true;
		dfs(depth + 1, i);
		chk[i] = false;
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) {
				home[++h_cnt] = { i, j };
			}
			else if (board[i][j] == 2) {
				chick[++c_cnt] = { i,j };
			}
		}
	}

	dfs(0, 0);
	cout << ans;
}
