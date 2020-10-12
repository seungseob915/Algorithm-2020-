// [17472] 다리만들기2(retry).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
using namespace std;

int N, M, cnt = 1;
int board[11][11];
bool chk[11][11];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

int main()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (chk[i][j]) continue;
			if (board[i][j] == 1) {
				queue <pair<int, int>> q;
				q.push({ i,j });
				chk[i][j] = true;
				board[i][j] = cnt;

				while (!q.empty()) {
					pair<int,int> now=q.front();
					q.pop();

					for (int k = 0; k < 4; k++) {
						int nx = now.first + dx[k];
						int ny = now.second + dy[k];

						if (nx<1 || nx>N || ny<1 || ny>M)continue;
						if (board[nx][ny] == 0) continue;
						if (chk[nx][ny]) continue;

						q.push({ nx,ny });
						chk[nx][ny] = true;
						board[nx][ny] = cnt;
;					}
				}
				cnt++;
			}
		}
	}
	

}
