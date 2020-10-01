// 14503(로봇 청소기).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int cnt = 0;
int a[50][50];


void clean(int x, int y, int dir) {
    while (true) {
        if (a[x][y] == 0) {
            a[x][y] = 2;
            cnt++;
        }

        if (a[x + 1][y] != 0 && a[x - 1][y] && a[x][y - 1] != 0 && a[x][y + 1] != 0) {
            if (a[x - dx[dir]][y - dy[dir]] == 1)
                return;
            else {
                x -= dx[dir];
                y -= dy[dir];
            }
        }
        else {
            dir = (dir + 3) % 4;
            if (a[x + dx[dir]][y + dy[dir]] == 0) {
                x += dx[dir];
                y += dy[dir];
            }
        }
    }
}


int main()
{
    int n, m, r, c, dir;
    cin >> n >> m;
    
    cin >> r >> c >> dir;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    clean(r, c, dir);
            
    cout << cnt << "\n";
    return 0;
}
