// 7576(토마토).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// queue에 넣는 순서를 먼저 잘 고려해야함

#include <iostream>
#include <memory.h>
#include <queue>

using namespace std;

int m, n;
int map[1000][1000];
int check[1000][1000];		
int dx[] = { 0, -1, 1, 0 };
int dy[] = { -1, 0, 0, 1 };

void bfs(int, int);

int main()
{
	queue <pair<int, int>> q;

	scanf("%d %d", &m, &n);
	memset(check, -1, sizeof(check));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) {
				q.push(make_pair(i, j));
				check[i][j] = 0;
			}
		}
	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < m && ny < n)
				if (map[ny][nx] == 0 && check[ny][nx] == -1) {
					check[ny][nx] = check[y][x] + 1;
					q.push(make_pair(ny, nx));
				}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (ans < check[i][j])
				ans = check[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (check[i][j] == -1 && map[i][j] == 0)
				ans = -1;
			

	printf("%d\n", ans);

	return 0;
}

