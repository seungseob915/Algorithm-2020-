// [1194] 달이 차오른다, 가자.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <memory.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct Location {
	int x, y, key;
}loc;

int finish = 987654321;
int N, M;
char board[51][51] = {};
int check[51][51][64] = {};
loc minsik;
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

int main()
{
	cin >> N >> M;
	
	memset(check, -1, sizeof(check));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> board[i][j];
			if (board[i][j] == '0') {
				minsik = { i, j, 0 };
			}
		}
	}

	queue <loc> q;
	q.push(minsik);
	check[minsik.x][minsik.y][minsik.key] = 0;

	while (!q.empty()) {
		loc now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			loc next = { now.x + dx[i], now.y + dy[i], now.key };

			//범위를 벗어났을때
			if (next.x<1 || next.x>N || next.y<1 || next.y>M) continue;
			// 이미 방문했을때
			if (check[next.x][next.y][next.key] != -1)	continue;
			// 벽일때
			if (board[next.x][next.y] == '#') continue;
			//출구일때
			else if (board[next.x][next.y] == '1') {
				finish = min(finish, check[now.x][now.y][now.key] + 1);
				check[next.x][next.y][next.key] = check[now.x][now.y][now.key] + 1;
				break;
			}
			// 문일때
			else if (board[next.x][next.y] >= 'A' && board[next.x][next.y] <= 'F') {
				int temp = board[next.x][next.y] - 65;
				// 키가 없으면
				if ((now.key & (1 << temp)) != (1 << temp)) {
					continue;
				}
			}
			//키가 있다면
			else if (board[next.x][next.y] >= 'a' && board[next.x][next.y] <= 'f') {
				int key_temp;
				key_temp = board[next.x][next.y] - 97;
				if ((now.key & (1 << key_temp)) != (1 << key_temp)) {
					next.key = now.key | (1 << key_temp);
				}
			}
			q.push(next);
			check[next.x][next.y][next.key] = check[now.x][now.y][now.key] + 1;
		}
	}

	if (finish == 987654321)
		finish = -1;

	cout << finish;
}

//// [1194] 달이 차오른다, 가자.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
////
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//typedef struct Location {
//	int x, y;
//}loc;
//
//int finish = 987654321;
//int N, M;
//char board[51][51];
//bool check[51][51][64] = {};
//loc minsik;
//int dx[] = { 0, 0, -1, 1 };
//int dy[] = { -1, 1, 0, 0 };
//
//void dfs(int depth, loc now, int key) {
//	//범위를 벗어났을때
//	if (now.x<1 || now.x>N || now.y<1 || now.y>M) {
//		return;
//	}
//	// 이미 방문했을때
//	if (check[now.x][now.y][key] == true) {
//		return;
//	}
//	//출구일때
//	if (board[now.x][now.y] == '1') {
//		finish = min(finish, depth);
//		return;
//	}
//	// 벽일때
//	if (board[now.x][now.y] == '#') {
//		return;
//	}
//	// 문일때
//	if (board[now.x][now.y] >= 'A' && board[now.x][now.y] <= 'F') {
//		int temp = board[now.x][now.y] - 65;
//		// 키가 없으면
//		if ((key & (1<<temp)) != (1 << temp)) {
//			return;
//		}
//	}
//
//	bool key_ex = false;
//	int key_temp;
//	int new_key;
//
//	//키가 있다면
//	if (board[now.x][now.y] >= 'a' && board[now.x][now.y] <= 'f') {
//		key_temp = board[now.x][now.y] - 97;
//		if ((key&(1<<key_temp))!=(1<<key_temp)) {
//			key = key | (1 << key_temp);
//			key_ex = true;
//		}
//	}
//
//	check[now.x][now.y][key] = true;
//
//	for (int i = 0; i < 4; i++) {
//		loc next = { now.x + dx[i], now.y + dy[i] };
//		//cout << depth << endl;
//		dfs(depth + 1, next, key);
//	}
//	check[now.x][now.y][key] = false;
//}
//
//int main()
//{
//	cin >> N >> M;
//
//
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= M; j++) {
//			cin >> board[i][j];
//			if (board[i][j] == '0') {
//				minsik = { i, j };
//			}
//		}
//	}
//
//	dfs(0, minsik, 0);
//
//	if (finish == 987654321)
//		finish = -1;
//
//	cout << finish;
