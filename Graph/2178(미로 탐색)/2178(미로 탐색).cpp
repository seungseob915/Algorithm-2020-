// 2178(미로 탐색).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
using namespace std;

int n, m;
int map[100][100];
bool check[100][100];	
int dist[100][100];
int dx[] = { 0, -1, 1, 0 };
int dy[] = { -1, 0, 0, 1 };

void bfs(int, int);

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%1d", &map[i][j]);

	dist[0][0] = 1;

	bfs(0, 0);

	printf("%d", dist[n-1][m-1]);

}

void bfs(int y, int x) {
	queue <pair<int, int>> q;
	q.push(make_pair(y, x));
	check[y][x] = true;
	
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny>=0 && nx>=0 && ny<n && nx<m)
				if (map[ny][nx] == 1 && check[ny][nx] == false) {
					q.push(make_pair(ny, nx));
					check[ny][nx] = true;
					dist[ny][nx] = dist[y][x] + 1;
				}
;		}
	}
}
