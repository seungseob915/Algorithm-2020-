// [14502] 연구소.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, ans = 0;
int board[9][9];
bool visited[9][9];

vector<pair<int, int>> xy;
vector<pair<int, int>> start;
vector<int> xy_list;

int rx[4] = { 0, 0, 1, -1 };
int ry[4] = { -1, 1, 0, 0 };

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) {
				xy.push_back(make_pair(i, j));
			}
			else if (board[i][j] == 2) {
				start.push_back(make_pair(i, j));
			}
		}
	}

	for (int i = 0; i < xy.size(); i++) {
		if (i < 3) {
			xy_list.push_back(1);
		}
		else {
			xy_list.push_back(0);
		}
	}

	//벽을 세울수 있는 곳을 조합함
	do {
		//초기화
		int board_t[9][9];
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				board_t[i][j] = board[i][j];
			}
		}

		for (int i = 0; i < xy.size(); i++) {
			if (xy_list[i] == 1) {
				board_t[xy[i].first][xy[i].second] = 1;
			}
		}

		queue <pair<int, int>> q;

		for (int i = 0; i < start.size(); i++) {
			q.push(start[i]);
			//visited[start[i].first][start[i].second] = true;
		}

		while (!q.empty()) {
			pair<int,int> now = q.front();
			int nowx = now.first;
			int nowy = now.second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nextx = nowx + rx[i];
				int nexty = nowy + ry[i];

				if (nextx > n || nextx <1 || nexty>m || nexty < 1)
					continue;
				if (board_t[nextx][nexty] != 0)
					continue;
				q.push(make_pair(nextx, nexty));
				board_t[nextx][nexty] = 2;
				//visited[nextx][nexty]=true;
			}
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (board_t[i][j] == 0) {
					cnt++;
				}
			}
		}
		ans = max(ans, cnt);

	} while (prev_permutation(xy_list.begin(), xy_list.end()));

	cout << ans;
}

