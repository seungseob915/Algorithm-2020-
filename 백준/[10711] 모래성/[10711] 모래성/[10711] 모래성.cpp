// [10711] 모래성.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// size가 커지면 커질수록 모래갯수가 적어질수 있다

#include <iostream>
#include <queue>
#include<string>
#include <vector>
using namespace std;

int H, W, time = 0;
int board[1001][1001];
int stk[1001][1001];
bool chk[1001][1001];

queue<pair<int, int>> s;
int dx[] = { -1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,1,1,1,0,-1,-1,-1 };

int main()
{
	cin >> H >> W;

	for (int i = 1; i <= H; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < W; j++) {
			if (temp[j] == '.') {
				s.push({ i,j + 1 });
				chk[i][j + 1] = true;
				board[i][j + 1] = 0;
			}
			else {
				board[i][j + 1] = temp[j] - '0';
			}
		}
	}

	

	queue<pair<int, int>> del;

	while (!s.empty()) {
		int x = s.front().first;
		int y = s.front().second;
		s.pop();

		for (int k = 0; k < 8; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx<1 || nx>H || ny<1 || ny>W) continue;
			if (chk[nx][ny]) continue;
			if (board[nx][ny] > 0) stk[nx][ny]++;
			if (stk[nx][ny] >= board[nx][ny]) {
				del.push({ nx, ny });
				chk[nx][ny] = true;
			}
		}

		if (s.empty() && del.size() != 0) {
			time++;

			s = del;
			while (!del.empty())
				del.pop();
		}
	}
	cout << time;
}