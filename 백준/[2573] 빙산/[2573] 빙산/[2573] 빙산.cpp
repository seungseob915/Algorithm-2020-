// [2573] 빙산.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct ICE {
	int x, y, size;
}I;

int N, M, time = 0, total_land=0;
int board[301][301];
vector<I> ice;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int main()
{
	cin >> N >> M;
	

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> board[i][j];

			if (board[i][j] > 0)
				ice.push_back({ i, j, board[i][j] });
		}
	}

	total_land = ice.size();

	while (1) {
		if (total_land == 0) {
			time = 0;
			break;
		}

		time++;

		vector<int> melt_wait;

		//얼음 녹는다
		for (int i = 0; i < ice.size(); i++) {
			if (ice[i].size == 0)
				continue;

			int nx = ice[i].x;
			int ny = ice[i].y;

			for (int k = 0; k < 4; k++) {
				// 물이면
				if (nx + dx[k]<1 || nx + dx[k]>N || ny + dy[k]<1 || ny + dy[k] >M)
					continue;
				if (board[nx + dx[k]][ny + dy[k]] == 0) {
					board[nx][ny]--;
					ice[i].size--;
				}
			}
			// 한번에 녹이려면 
			if (board[nx][ny] <= 0) {
				board[nx][ny] = -1;
				ice[i].size = 0;
				melt_wait.push_back(i);
				total_land--;
			}
		}

		//마지막에 한번에 0으로 처리
		for (int i = 0; i < melt_wait.size(); i++)
			board[ice[melt_wait[i]].x][ice[melt_wait[i]].y] = 0;

		
		//얼음 처리 다했으면 이제 섬 갯수 확인
		int nowland = 0;
		bool bfs_finish = false;
		for (int i = 0; i < ice.size(); i++) {

			if (ice[i].size != 0) {
				bfs_finish = true;
				bool chk[301][301] = {};
				int nowx = ice[i].x;
				int nowy = ice[i].y;

				queue<pair<int, int>> q;
				q.push({ nowx, nowy });
				chk[nowx][nowy] = true;
				nowland++;

				while (!q.empty()) {
					pair<int,int> nowq=q.front();
					q.pop();

					for (int k = 0; k < 4; k++) {
						int nxtx = nowq.first + dx[k];
						int nxty = nowq.second + dy[k];

						if (nxtx<1 || nxtx>N || nxty<1 || nxty>M)
							continue;
						if (board[nxtx][nxty] == 0)
							continue;
						if (chk[nxtx][nxty])
							continue;
						q.push({ nxtx, nxty });
						chk[nxtx][nxty] = true;
						nowland++;
					}
				}
			}
			if(bfs_finish)
				break;
		}

		if (nowland != total_land)
			break;
	}
	cout << time;
}
