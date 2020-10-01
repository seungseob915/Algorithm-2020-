// [1194] 달이 차오른다, 가자.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Location {
	int x, y;
}loc;

int finish = 987654321;
int N, M;
char board[51][51];
bool check[51][51][64] = {};
loc minsik;
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

void dfs(int depth, loc now, int key) {
	//범위를 벗어났을때
	if (now.x<1 || now.x>N || now.y<1 || now.y>M) {
		return;
	}
	// 이미 방문했을때
	if (check[now.x][now.y][key] == true) {
		return;
	}
	//출구일때
	if (board[now.x][now.y] == '1') {
		finish = min(finish, depth);
		return;
	}
	// 벽일때
	if (board[now.x][now.y] == '#') {
		return;
	}
	// 문일때
	if (board[now.x][now.y] >= 'A' && board[now.x][now.y] <= 'F') {
		int temp = board[now.x][now.y] - 65;
		// 키가 없으면
		if ((key & (1<<temp)) != (1 << temp)) {
			return;
		}
	}

	bool key_ex = false;
	int key_temp;
	int new_key;

	//키가 있다면
	if (board[now.x][now.y] >= 'a' && board[now.x][now.y] <= 'f') {
		key_temp = board[now.x][now.y] - 97;
		if ((key&(1<<key_temp))!=(1<<key_temp)) {
			key = key | (1 << key_temp);
			key_ex = true;
		}
	}

	check[now.x][now.y][key] = true;

	for (int i = 0; i < 4; i++) {
		loc next = { now.x + dx[i], now.y + dy[i] };
		//cout << depth << endl;
		dfs(depth + 1, next, key);
	}
	check[now.x][now.y][key] = false;
}

int main()
{
	cin >> N >> M;


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> board[i][j];
			if (board[i][j] == '0') {
				minsik = { i, j };
			}
		}
	}

	dfs(0, minsik, 0);

	if (finish == 987654321)
		finish = -1;

	cout << finish;
}

/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Location {
	int x, y;
}loc;

int finish = 987654321;
int N, M;
char board[51][51];
int check[51][51] = {};
bool key_check[51][51] = {};
int key[7] = {};	// A~F -> 0~6까지
loc minsik;
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

void dfs(int depth, loc now) {
	//범위를 벗어났을때
	if (now.x<1 || now.x>N || now.y<1 || now.y>M) {
		return;
	}
	// 이미 방문했을때
	if (check[now.x][now.y] == 4) {
		return;
	}
	//출구일때
	if (board[now.x][now.y]=='1') {
		finish = min(finish, depth);
		return;
	}
	// 벽일때
	if (board[now.x][now.y] == '#') {
		return;
	}
	// 문일때
	if (board[now.x][now.y] >= 'A' && board[now.x][now.y] <= 'F') {
		int temp = board[now.x][now.y] - 65;
		// 키가 없으면
		if (key[temp] == 0) {
			return;
		}
	}

	check[now.x][now.y]++;
	
	bool key_ex = false;
	int key_temp;
	//키가 있다면
	if (board[now.x][now.y] >= 'a' && board[now.x][now.y] <= 'f') {
		if (!key_check[now.x][now.y]) {
			key_temp = board[now.x][now.y] - 97;
			key[key_temp]++;
			key_ex = true;
		}
	}

	for (int i = 0; i < 4; i++) {
		loc next = { now.x+dx[i], now.y+dy[i] };
		//cout << depth << endl;
		dfs(depth + 1, next);
	}
	
	check[now.x][now.y]--;
	//키가 있었다면
	if (key_ex)
		key[key_temp]--;
}

int main()
{
	cin >> N >> M;
	
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> board[i][j];
			if (board[i][j] == '0') {
				minsik = { i, j };
			}
		}
	}

	dfs(0, minsik);

	if (finish == 987654321)
		finish = -1;

	cout << finish;
}

*/