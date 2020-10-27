// [2339] 석판 자르기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

int N, ans=0;
int board[21][21] = { 0, };

bool check(int fix, int start, int end, int dir) {
	if (dir == 0) {
		for (int i = start; i <= end; i++) {
			if (board[fix][i] == 2) return false;
		}
	}
	else {
		for (int i = start; i <= end; i++) {
			if (board[i][fix] == 2) return false;
		}
	}
	return true;
}

//dir=0 : ㅡ / dir=1 : l
int find(int sx, int sy, int ex, int ey, int dir) {
	int chk[3] = { 0, };
	for (int i = sx; i <= ex; i++) {
		for (int j = sy; j <= ey; j++) {
			chk[board[i][j]]++;
		}
	}

	if (chk[2] == 0) return 0;
	if (chk[2] == 1 && chk[1] == 0) return 1;

	int ret = 0;
	for (int i = sx; i <= ex; i++) {
		for (int j = sy; j <= ey; j++) {
			//결정체이면 분할해줘야함
			if (board[i][j] == 1) {
				if (dir == 0 && check(i, sy, ey, 0)==true) {
					ret += find(sx, sy, i - 1, ey, 1) * find(i+1, sy, ex, ey, 1);
				}
				else if(dir==1 && check(j, sx, ex, 1) == true){
					ret += find(sx, sy, ex, j-1, 0) * find(sx, j+1, ex, ey, 0);
				}
			}
		}
	}
	return ret;
}

int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
		}
	}

	ans = find(1, 1, N, N, 0) + find(1, 1, N, N, 1);
	if (ans == 0) ans = -1;
	cout << ans;
}