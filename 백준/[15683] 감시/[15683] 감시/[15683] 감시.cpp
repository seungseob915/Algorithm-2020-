// [15683] 감시.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct CCTV {
	int idx, x, y, dir;
}C;
typedef struct Q_CCTV {	//큐에 넣을때만 사용할 cctv 구조체
	int x, y, dir;
}q_c;

int N, M, ans=987654321;
vector<C> cctv;
int board[9][9];
int total, blk = 0;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

void go(int now) {
	int no = cctv[now].idx;
	int pattern = cctv[now].dir;
	pair<int, int> n_loc = { cctv[now].x, cctv[now].y };

	//시작위치랑, 방향만 큐에넣으면된다.
	queue<q_c> q;

	// 번호별로
	if (no == 1) {
		q.push({ n_loc.first, n_loc.second, pattern });
	}
	else if (no == 2) {
		if (pattern == 0) {
			q.push({ n_loc.first, n_loc.second, 1 });
			q.push({ n_loc.first, n_loc.second, 3 });
		}
		else if (pattern == 1) {
			q.push({ n_loc.first, n_loc.second, 2 });
			q.push({ n_loc.first, n_loc.second, 0 });
		}
	}
	else if (no == 3) {
		if (pattern == 0) {
			q.push({ n_loc.first, n_loc.second, 0 });
			q.push({ n_loc.first, n_loc.second, 1 });
		}
		else if (pattern == 1) {
			q.push({ n_loc.first, n_loc.second, 1 });
			q.push({ n_loc.first, n_loc.second, 2 });
		}
		else if (pattern == 2) {
			q.push({ n_loc.first, n_loc.second, 2 });
			q.push({ n_loc.first, n_loc.second, 3 });
		}
		else if (pattern == 3) {
			q.push({ n_loc.first, n_loc.second, 3 });
			q.push({ n_loc.first, n_loc.second, 0 });
		}
	}
	else if (no == 4) {
		if (pattern == 0) {
			q.push({ n_loc.first, n_loc.second, 0 });
			q.push({ n_loc.first, n_loc.second, 1 });
			q.push({ n_loc.first, n_loc.second, 2 });

		}
		else if (pattern == 1) {
			q.push({ n_loc.first, n_loc.second, 1 });
			q.push({ n_loc.first, n_loc.second, 2 });
			q.push({ n_loc.first, n_loc.second, 3 });
		}
		else if (pattern == 2) {
			q.push({ n_loc.first, n_loc.second, 2 });
			q.push({ n_loc.first, n_loc.second, 3 });
			q.push({ n_loc.first, n_loc.second, 0 });
		}
		else if (pattern == 3) {
			q.push({ n_loc.first, n_loc.second, 3 });
			q.push({ n_loc.first, n_loc.second, 0 });
			q.push({ n_loc.first, n_loc.second, 1 });
		}
	}
	else {
		q.push({ n_loc.first, n_loc.second, 0 });
		q.push({ n_loc.first, n_loc.second, 1 });
		q.push({ n_loc.first, n_loc.second, 2 });
		q.push({ n_loc.first, n_loc.second, 3 });
	}

	while (!q.empty()) {
		q_c nq=q.front();
		q.pop();
		q_c next = { nq.x+dx[nq.dir], nq.y+dy[nq.dir], nq.dir };

		if (next.x<0 || next.x>N - 1 || next.y < 0 || next.y>M - 1) continue;
		if (board[next.x][next.y] == 6) continue;
		if (board[next.x][next.y] >= 1 && board[next.x][next.y] <= 5) {
			q.push(next);
			continue;
		}
		q.push(next);
		board[next.x][next.y] = -1;
	}
}

void dfs(int now, int finish, int dir) {
	if (now == finish) {
		int t_ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (board[i][j] == 0)
					t_ans++;
			}
		}
		ans = min(t_ans, ans);
		return;
	}

	//방향 설정
	int t_dir = cctv[now].dir;
	cctv[now].dir = dir;
	//미리 색칠해서 백트래킹하자
	int t_board[9][9];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			t_board[i][j] = board[i][j];
		}
	}

	go(now);	//방향에 대해 시작

	for (int i = 0; i < 4; i++) {
		if (now+1 < finish && cctv[now+1].idx == 5 && i > 0) 	continue;
		if (now + 1 < finish && cctv[now+1].idx == 2 && i > 1) continue;
		dfs(now + 1, finish, i);
	}

	cctv[now].dir= t_dir;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			board[i][j] = t_board[i][j];
		}
	}
}

int main()
{
	cin >> N >> M;
	total = N * M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] >= 1 && board[i][j] <= 5)
				cctv.push_back({ board[i][j], i, j, -1 });
			else if (board[i][j] == 6)
				blk++;
		}
	}

	int depth=cctv.size();
	if (depth == 0) {
		cout << total - blk;
		return 0;
	}

	for (int i = 0; i < 4; i++) {
		if (cctv[0].idx == 5 && i > 0) 	continue;
		if (cctv[0].idx == 2 && i > 1) continue;
		dfs(0, depth, i);
	}
	cout << ans;
}
