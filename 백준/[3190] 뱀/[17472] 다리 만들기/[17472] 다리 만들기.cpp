// [17472] 다리 만들기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, i_cnt = 0, brg_cnt = 0, ans = 987654321;
int board[101][101];
int bridge[7][7];
int list[7];
bool check[101][101];
vector <pair<int, int>> permu;

int dx[] = { -1, 0 ,1, 0 };
int dy[] = { 0, 1 ,0, -1 };

int getParent(int n) {
	if (list[n] == n) return n;
	else return list[n]=getParent(list[n]);
}

void unionParent(int n1, int n2) {
	n1 = getParent(n1);
	n2 = getParent(n2);
	if (n1 < n2) list[n2] = n1;
	else list[n1] = n2;
}

int main()
{
	cin >> N >> M;

	vector<pair<int, int>> start;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1)
				start.push_back({ i, j });
		}
	}

	//섬 갯수 및 플러드필
	for (int i = 0; i < start.size(); i++) {
		queue<pair<int, int>> q;
		if (check[start[i].first][start[i].second])
			continue;

		i_cnt++;
		q.push(start[i]);
		check[start[i].first][start[i].second] = true;
		board[start[i].first][start[i].second] = i_cnt;

		while (!q.empty()) {
			pair<int, int> now = q.front();
			q.pop();

			for (int k = 0; k < 4; k++) {
				pair<int, int> next = { now.first + dx[k], now.second + dy[k] };

				if (next.first<1 || next.first > N || next.second<1 || next.second >M) continue;
				if (check[next.first][next.second])		continue;
				if (board[next.first][next.second] == 0)	continue;
				q.push(next);
				check[next.first][next.second] = true;
				board[next.first][next.second] = i_cnt;
			}
		}
	}
	brg_cnt = i_cnt - 1;	// 최소 다리 갯수

	//최소 다리 찾자
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (board[i][j] > 0) {
				//한방향으로
				for (int k = 0; k < 4; k++) {
					queue<pair<int, int>> q;
					int dir = k;
					int l = 0;
					q.push({ i, j });

					while (!q.empty()) {
						pair<int, int> now = q.front();
						q.pop();
						pair<int, int> next = { now.first + dx[dir], now.second + dy[dir] };
						l++;
						if (next.first<1 || next.first>N || next.second<1 || next.second>M)	break;
						if (board[next.first][next.second] == board[i][j])	break;
						if (board[next.first][next.second] != 0 && board[next.first][next.second] != board[i][j]) {
							if (l > 2) {
								if (bridge[board[i][j]][board[next.first][next.second]] != 0)
									bridge[board[i][j]][board[next.first][next.second]] = min(l - 1, bridge[board[i][j]][board[next.first][next.second]]);
								else
									bridge[board[i][j]][board[next.first][next.second]] = l - 1;
							}
							break;
						}
						q.push(next);
					}
				}
			}
		}
	}

	vector<int> order;

	//조합을 해주자(다리)
	for (int i = 0; i < i_cnt; i++) {
		if (i < 2)
			order.push_back(1);
		else
			order.push_back(0);
	}

	do {
		int temp[2];
		int temp_n = 0;
		for (int i = 0; i < i_cnt; i++) {
			if (order[i] == 1) {
				temp[temp_n] = i + 1;
				temp_n++;
			}
		}
		permu.push_back({ temp[0], temp[1] });

	} while (prev_permutation(order.begin(), order.end()));

	order.clear();

	//조합을 해주자(최소 다리 갯수만큼)
	for (int i = 0; i < permu.size(); i++) {
		if (i < brg_cnt)
			order.push_back(1);
		else
			order.push_back(0);
	}

	do {
		bool ok = true;

		
		vector<vector<int>> graph;
		int temp_ans = 0;

		for (int i = 0; i < permu.size(); i++) {
			if (order[i] == 1) {
				if (bridge[permu[i].first][permu[i].second] == 0)
					ok = false;
				else {
					graph.push_back({ permu[i].first, permu[i].second });
					temp_ans += bridge[permu[i].first][permu[i].second];
				}
			}
		}

		for (int i = 1; i <= i_cnt; i++)
			list[i] = i;
	
		for (int i = 0; i < graph.size(); i++) {
			unionParent(graph[i][0], graph[i][1]);
		}
		for (int i = graph.size()- 1; i >= 0; i--) {
			unionParent(graph[i][0], graph[i][1]);
		}

		for (int i = 1; i <= i_cnt; i++) {
			if (list[1] != list[i])
				ok = false;
		}

		if (ok) {
			ans = min(ans, temp_ans);
		}

	} while (prev_permutation(order.begin(), order.end()));

	if (ans == 987654321)
		ans = -1;

	cout << ans;
}