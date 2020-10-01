// [3184] 양.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int R, C, wolf = 0, sheep = 0;
char board[251][251];
bool check[251][251];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

int main()
{
	cin >> R >> C;

	vector<pair<int, int>> ws;

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'v' || board[i][j] == 'o')
				ws.push_back({ i, j });
		}
	}

	for (int i = 0; i < ws.size(); i++) {
		pair<int, int> n = ws[i];
		if (check[n.first][n.second])	continue;

		int t_wolf = 0, t_sheep = 0;
		if (board[n.first][n.second] == 'o') t_sheep++;
		if (board[n.first][n.second] == 'v') t_wolf++;
		queue <pair<int, int>> q;
		q.push(n);
		check[n.first][n.second] = true;

		while (!q.empty()) {
			pair<int, int> now = q.front();
			q.pop();

			for (int k = 0; k < 4; k++) {
				pair<int, int>  next = { now.first + dx[k], now.second + dy[k] };
				if (next.first<1 || next.first>R || next.second<1 || next.second>C) continue;
				if (check[next.first][next.second]) continue;
				if (board[next.first][next.second] == '#') continue;
				if (board[next.first][next.second] == 'o') t_sheep++;
				if (board[next.first][next.second] == 'v') t_wolf++;
				q.push(next);
				check[next.first][next.second] = true;
			}
		}
		if (t_wolf >= t_sheep)
			wolf += t_wolf;
		else
			sheep += t_sheep;
	}
	cout << sheep << ' ' << wolf;
}