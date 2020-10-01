// [2422] 한윤정이 이탈리아에 가서 아이스크림을 사먹는데.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

bool chk[201][201];
int N, M, ans=0;

void dfs(int prev_no, int depth, int first) {
	if (depth == 3) {
		ans++;
		return;
	}

	for (int i = prev_no + 1; i <= N; i++) {
		if (chk[prev_no][i]) continue;
		if (chk[first][i]) continue;
		dfs(i, depth + 1, first);
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		pair<int, int> temp;
		cin >> temp.first >> temp.second;
		if (temp.first < temp.second)
			chk[temp.first][temp.second] = true;
		else
			chk[temp.second][temp.first] = true;
	}

	for (int i = 1; i <= N; i++) {
		dfs(i, 1, i);
	}

	cout << ans;
}
