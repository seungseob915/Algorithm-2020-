// [17472] 다리 만들기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct Bridge {
	int n1, n2, dis;
}B;

bool cmp(B a, B b) {
	return a.dis < b.dis;
}

int N, M, i_cnt = 0, brg_cnt = 0, ans = 987654321;
int board[101][101];
int bridge[7][7];
int list[7];
bool check[101][101];
vector <pair<int, int>> permu;

int dx[] = { -1, 0 ,1, 0 };
int dy[] = { 0, 1 ,0, -1 };

int getParent(int set[], int n) {
	if (set[n] == n) return n;
	else return set[n] = getParent(set, set[n]);
}

void unionParent(int set[], int n1, int n2) {
	n1 = getParent(set, n1);
	n2 = getParent(set, n2);
	if (n1 < n2) set[n2] = n1;
	else set[n1] = n2;
}

bool find(int set[], int a, int b) {
	a = getParent(set, a);
	b = getParent(set, b);
	if (a == b) return true;
	else return false;
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
	vector<B> b;

	for (int i = 1; i <= i_cnt; i++) {
		for (int j = i+1; j <= i_cnt; j++) {
			if (bridge[i][j] > 0)
				b.push_back({ i, j, bridge[i][j] });
		}
	}
	// 길이 기준으로 정렬하여 스패닝 트리 만들어보자
	sort(b.begin(), b.end(), cmp);

	ans = 0;
	int set[7] = {};
	
	for (int i = 1; i <= i_cnt; i++) {
		set[i] = i;
	}

	for (int i = 0; i < b.size(); i++) {
		if (!find(set, b[i].n1, b[i].n2)) {
			ans += b[i].dis;
			unionParent(set, b[i].n1, b[i].n2);
		}
	}

	bool flag = true;
	int oneParent = getParent(set, 1);

	for (int i = 2; i <= i_cnt; i++) {
		if (oneParent != getParent(set, i)) {
			flag = false;
			break;
		}
	}

	if (!flag) ans = -1;
	cout << ans;
}