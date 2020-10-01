// 2206(벽 부수고 이동하기).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int map[1001][1001];
int dist[1001][1001][2];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%1d", &map[i][j]);

	queue <tuple<int, int, int>> q;
	dist[0][0][0] = 1;
	q.push(make_tuple(0, 0, 0));
	while (!q.empty()) {
		int x, y, z;
		tie(x, y, z) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
				if (map[nx][ny] == 0 && dist[nx][ny][z] == 0) {
					dist[nx][ny][z] = dist[x][y][z] + 1;
					q.push(make_tuple(nx, ny, z));
					;
				}
				if (z == 0 && map[nx][ny] == 1 && dist[nx][ny][z + 1] == 0) {
					dist[nx][ny][z + 1] = dist[x][y][z] + 1;
					q.push(make_tuple(nx, ny, z + 1));
				}
			}
		}

	}
	if (dist[n - 1][m - 1][0] != 0 && dist[n - 1][m - 1][1] != 0) {
		printf("%d", min(dist[n - 1][m - 1][0], dist[n - 1][m - 1][1]));
	}
	else if (dist[n - 1][m - 1][0] != 0) {
		printf("%d", dist[n - 1][m - 1][0]);
	}
	else if (dist[n - 1][m - 1][1] != 0) {
		printf("%d", dist[n - 1][m - 1][1]);
	}
	else
		printf("-1");

	printf("\n");
	return 0;
}