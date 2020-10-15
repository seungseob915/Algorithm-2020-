// [17143] 낚시왕.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <memory.h>
using namespace std;

typedef struct Shark {
	int x, y, s, d, z;
}S;

int R, C, M;
int board[101][101] = {};
int chk[101][101] = {};
int dx[] = { 0,-1,1,0,0 };
int dy[] = { 0,0,0,1,-1 };
S s[10001] = {};

int main()
{
	cin >> R >> C >> M;

	for (int i = 1; i <= M; i++) {
		cin >> s[i].x >> s[i].y >> s[i].s >> s[i].d >> s[i].z;
		board[s[i].x][s[i].y] = i;
	}

	int land = 1;
	int ans = 0;

	while (land <= C) {

		//물고기잡기
		for (int i = 1; i <= R; i++) {
			if (board[i][land] != 0) {
				if (s[board[i][land]].z == 0) continue;
				ans += s[board[i][land]].z;
				s[board[i][land]].z = 0;
				board[i][land] = 0;
				break;
			}
		}

		memset(chk, 0, sizeof(chk));

		//물고기 이동
		for (int i = 1; i <= M; i++) {
			if (s[i].z == 0) continue;

			int x = s[i].x;
			int y = s[i].y;
			int d = s[i].d;
			int sd = s[i].s;

			if (d == 1 || d == 2) {
				int t = (x - 1) * 2 + (R - x) * 2;
				sd %= t;
			}
			else {
				int t = (y - 1) * 2 + (C - y) * 2;
				sd %= t;
			}

			for (int k = 1; k <= sd; k++) {
				int nx = x + dx[d];
				int ny = y + dy[d];
				
				if (nx<1 || nx>R || ny<1 || ny>C) {
					if (d % 2 == 0) d--;
					else d++;

					nx += dx[d] * 2;
					ny += dy[d] * 2;
				}
				x = nx;
				y = ny;
			}
			s[i].x = x;
			s[i].y = y;
			s[i].d = d;

			if (chk[x][y] != 0) {
				if (s[chk[x][y]].z > s[i].z) {
					s[i].z = 0;
				}
				else {
					s[chk[x][y]].z = 0;
					chk[x][y] = i;
				}
			}
			else {
				chk[x][y] = i;
			}
		}
		memcpy(board, chk, sizeof(chk));
		land++;
	}
	cout << ans;
}
