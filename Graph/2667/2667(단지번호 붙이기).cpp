// 2667.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int map[25][25];
int check[25][25];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int ans[25 * 25];
int cnt = 0;
int n;

void dfs(int, int, int);

int main()
{
    memset(check, 0, sizeof(check)); //0:미방문, 1이상 단지번호
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf("%1d", &map[i][j]);
        }
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (map[i][j] == 1 && check[i][j] == 0)
                dfs(i, j, ++cnt);

    printf("%d\n", cnt);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans[check[i][j]] += 1;

    sort(ans + 1, ans + cnt + 1);

    for (int i = 1; i <= cnt; i++) {
        printf("%d\n", ans[i]);
    }
    
    return 0;
}

void dfs(int x, int y, int cnt) {
        check[x][y] = cnt;       
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                if (map[nx][ny] == 1 && check[nx][ny] == 0)
                    dfs(nx, ny, cnt);
            }
    }
}