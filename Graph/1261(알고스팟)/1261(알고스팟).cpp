// 1261(알고스팟).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <deque>
#include <queue>
#include <cstring>

using namespace std;

int map[101][101];
int check[101][101];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            scanf("%1d", &map[i][j]);
            check[i][j] = -1;
        }

    deque <pair<int, int>> q;
    q.push_back(make_pair(0, 0));
    check[0][0] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop_front();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx>=0 && ny>=0 && nx<n && ny<m)
                if (check[nx][ny] == -1) {
                    if (map[nx][ny] == 0) {     //가중치 0
                        check[nx][ny] = check[x][y];
                        q.push_front(make_pair(nx, ny));
                    }
                    else {
                        check[nx][ny] = check[x][y] + 1;
                        q.push_back(make_pair(nx, ny));
                    }
                }
        }
    }
    printf("%d\n", check[n - 1][m - 1]);
    return 0;
}