// 3055(탈출).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <tuple>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
using namespace std;

int water[50][50];
int time[50][50];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int main()
{
    int n, m;
    cin >> n >> m;
    vector <string> thing(n);

    for (int i = 0; i < n; i++)
        cin >> thing[i];

    memset(water, -1, sizeof(water));

    queue <pair<int, int>> q;
    int sx, sy, ex, ey;

    for(int i=0; i<n; i++)
        for (int j = 0; j < m; j++) {
            if (thing[i][j] == '*') {
                q.push(make_pair(i, j));
                water[i][j] = 0;
            }
            else if (thing[i][j] == 'S') {       //비버 위치
                sx = i;
                sy = j;
            }
            else if (thing[i][j] == 'D') {       //목적지
                ex = i;
                ey = j;
            }
        }
    while (!q.empty()) {    //물 차있는것 부터 먼저 BFS
        int x, y;
        tie(x, y) = q.front(); 
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            if (water[nx][ny] != -1)
                continue;
            if (thing[nx][ny] == 'X')
                continue;
            if (thing[nx][ny] == 'D')
                continue;
            water[nx][ny] = water[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }
    memset(time, -1, sizeof(time));
    q.push(make_pair(sx, sy));
    time[sx][sy] = 0;
    while (!q.empty()) {        //고슴도치 길 BFS
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) 
                continue;
            if (time[nx][ny] != -1)
                continue;
            if (thing[nx][ny] == 'X')
                continue;
            if (water[nx][ny] != -1 && time[x][y] + 1 >= water[nx][ny])
                continue;
            time[nx][ny] = time[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }
    if (time[ex][ey] == -1)
        cout << "KAKTUS\n";
    else
        cout << time[ex][ey] << "\n";
    return 0;
}