#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>

using namespace std;

/*
새로운 게임2
말이 4개 이상 쌓이는 턴은 몇번째?
*/

typedef struct {
	int x, y;
	int dir;
}Point;

int N, K, turn;
int map[13][13];
int dx[4] = { 0, 0, -1, 1 };	// 0 →, 1 ←, 2 ↑, 3 ↓ (반대방향: 1, 
int dy[4] = { 1, -1, 0, 0 };
Point list[11];					// 말 리스트
stack<int> stacks[13][13];		// 말 쌓인 모습 (말 번호)
bool isEnd;


int changeDir(int dir) {
	if (dir == 0) return 1;
	else if (dir == 1) return 0;
	else if (dir == 2) return 3;
	else return 2;
}

void move(int n, Point point) {
	int x = point.x;
	int y = point.y;
	int dir = point.dir;

	// 다음 위치 갱신
	int nx = x + dx[dir];
	int ny = y + dy[dir];

	// 1. 범위밖/파란색
	if (nx <= 0 || nx > N || ny <= 0 || ny > N || map[nx][ny] == 2) {
		// 이동방향 반대
		dir = changeDir(dir);
		list[n].dir = dir;

		// 반대 방향도 막히지 않으면 한 칸 이동		
		int nnx = x + dx[dir];
		int nny = y + dy[dir];
		if ((nnx > 0 && nnx <= N) && (nny > 0 && nny <= N) && map[nnx][nny] != 2) {
			move(n, { x, y, dir });
		}
	}

	// 2. 빨간색
	else if (map[nx][ny] == 1) {
		// 쌓인 말 이동 (순서 반대로 되도록)
		while (stacks[x][y].top() != n) {
			int cur = stacks[x][y].top();
			stacks[nx][ny].push(cur);
			list[cur].x = nx;
			list[cur].y = ny;
			stacks[x][y].pop();

			if (stacks[nx][ny].size() >= 4) {
				isEnd = true;
				return;
			}
		}

		// 현재 말 이동
		stacks[nx][ny].push(n);
		list[n].x = nx;
		list[n].y = ny;
		stacks[x][y].pop();
		if (stacks[nx][ny].size() >= 4) {
			isEnd = true;
			return;
		}
	}

	// 3. 흰색
	else if (map[nx][ny] == 0) {
		// 쌓인 말 걷어내기 (순서 유지 위해)
		vector<int> tmp;
		while (stacks[x][y].top() != n) {
			tmp.push_back(stacks[x][y].top());
			stacks[x][y].pop();
		}
		stacks[x][y].pop();

		// 현재 말 이동
		stacks[nx][ny].push(n);
		list[n].x = nx;
		list[n].y = ny;
		if (stacks[nx][ny].size() >= 4) {
			isEnd = true;
			return;
		}

		// 쌓인 말 이동 (역순으로)
		int size = tmp.size();
		for (int i = size - 1; i >= 0; i--) {
			int cur = tmp[i];
			stacks[nx][ny].push(cur);
			list[cur].x = nx;
			list[cur].y = ny;
			if (stacks[nx][ny].size() >= 4) {
				isEnd = true;
				return;
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 1; i <= K; i++) {
		int r, c, dir;
		cin >> r >> c >> dir;
		list[i] = { r, c, dir - 1 };	// i번째 말은 (r,c)에 dir방향으로 위치
		stacks[r][c].push(i);			// (r,c)에 i번째 말 위치
	}

	// 게임 시작
	while (turn <= 1000) {
		turn++;

		// 0번째 말부터 이동
		for (int i = 1; i <= K; i++) {
			move(i, list[i]);
			if (isEnd) break;
		}

		// 게임 종료 조건 충족
		if (isEnd) break;
	}

	if (!isEnd) turn = -1;
	cout << turn;
}
