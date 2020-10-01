// [���� SW �����׽�Ʈ] ���� ����.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//

#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;
int N, W, H, T, Tcnt = 1, ans = 987654321;
int board[16][13];
int tboard[16][13];
int check[16][13];
int order[13] = {};

int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };

typedef struct bkdol {
	int x, y, s;
}bd;

queue <pair<int, int>> wq;


// 4�������� ������
void remove(pair<int, int> b, int dir, int now, bd f) {
	//����
	if (b.first<1 || b.first> H || b.second < 1 || b.second >W) {
		return;
	}

	if (f.s < now) {
		return;
	}

	//2�̻��� ���� ������ 
	if (tboard[b.first][b.second] > 1 && check[b.first][b.second] == 0) {
		wq.push({ b.first, b.second });
	}
	check[b.first][b.second] = 1;
	remove(make_pair(b.first + dx[dir], b.second + dy[dir]), dir, now + 1, f);
}


void fire(int start, int tboard[][13]) {
	// 1~N������ ����
	memset(check, 0, sizeof(check));

	// 1��°������ ����
	int now = order[start];

	//���� ���� ���� �˻�
	for (int i = 1; i <= H; i++) {
		// ���� ���� �� ã����
		if (tboard[i][now] >= 1) {
			wq.push({ i, now });
			break;
		}
	}

	// start��° ���� ��
	while (!wq.empty()) {
		pair<int, int> n = wq.front();
		check[n.first][n.second] = 1;
		wq.pop();

		//4���� check
		for (int j = 0; j < 4; j++) {
			remove(n, j, 1, { n.first, n.second, tboard[n.first][n.second] });
		}
	}

	// ������������
	for (int ii = 1; ii <= H; ii++) {
		for (int jj = 1; jj <= W; jj++) {
			if (check[ii][jj] == 1) {
				tboard[ii][jj] = 0;
			}
		}
	}

	// ������
	for (int ww = 1; ww <= W; ww++) {
		for (int ii = H; ii >= 1; ii--) {
			if (tboard[ii][ww] == 0) {
				for (int jj = ii - 1; jj >= 1; jj--) {
					if (tboard[jj][ww] != 0) {
						tboard[ii][ww] = tboard[jj][ww];
						tboard[jj][ww] = 0;
						break;
					}
				}
			}
		}
	}
}


//���� ����
void dfs(int now, int finish, int nboard[][13]) {
	if (now == finish + 1) {
		int cnt = 0;
		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) {
				if (nboard[i][j] == 1) {
					cnt++;
				}
			}
		}
		ans = min(ans, cnt);
		return;
	}

	int tboard[16][13];
	memcpy(tboard, nboard, sizeof(nboard));

	for (int i = 1; i <= W; i++) {
		fire(i, tboard);

		for (int x = 1; x <= H; x++) {
			for (int y = 1; y <= W; y++) {
				cout << tboard[x][y];
			}
			cout << endl;
		}
		cout << endl;
		dfs(now + 1, finish, tboard);
	}
}

int main()
{
	cin >> T;

	while (T--) {
		cin >> N >> W >> H;

		ans = 987654321;

		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) {
				cin >> board[i][j];
			}
		}

		dfs(1, N, board);

		cout << "#" << Tcnt++ << " " << ans << endl;
	}
}