// 17142(연구소 3_마지막).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

int n, m, ans, cnt;
int map[51][51];
int temp[51][51];

vector<pair<int, int>> virus;
vector<pair<int, int>> livevirus;
bool selected[10];

int dx[] = { 0, 0 ,-1, 1 };
int dy[] = { -1, 1 ,0, 0 };


//바이러스 퍼뜨리기
int bfs() {

    queue <pair<int, int>> q;

    //바이러스 맵에 활성화바이러스 표시
    for (int i = 0; i < m; i++) {
        int tx = livevirus[i].first;
        int ty = livevirus[i].second;
        temp[tx][ty] = 0;
        q.push(make_pair(tx, ty));
    }

    int temp_cnt = 0;   // 이번 지도에서 바이러스가 된 빈칸의 갯수
    int  max_val = 0;   // 빈칸이 바이러스가 된 가장 오래걸린 시간

    while (!q.empty()) {
        pair<int, int> t = q.front();
        int x = t.first;
        int y = t.second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            //경계범위 초과
            if (nx >= n || ny >= n || nx < 0 || ny < 0)
                continue;
            // 
            if (temp[nx][ny] != 0)
                continue;
            // 빈칸이거나 비활성 바이러스일 떄
            if (map[nx][ny] == 0 || map[nx][ny] == 2) {
                temp[nx][ny] = temp[nx][ny] + 1;

                if (map[nx][ny] == 0) {
                    temp_cnt++;

                    if (temp[nx][ny] > max_val)
                        max_val = temp[nx][ny];
                }

                q.push(make_pair(nx, ny));
            }
        }
    }
    if (cnt != temp_cnt)
        return -1;

    return max_val;
}

//m개 바이러스 조합
void dfs(int depth, int start) {
    if (depth == m) {
        livevirus.clear();
        memset(temp, 0, sizeof(temp));

        for (int i = 0; i < virus.size(); i++) {
            if (selected[i] == true) {
                livevirus.push_back(virus[i]);
            }
        }

        //퍼트리자
        int ret = bfs();
        if (ret != -1 && ret < ans)
            ans = ret;

        return;
    }
    else {
        for (int i = start; i < virus.size(); i++) {
            if (selected[i] == true)
                continue;
            selected[i] = true;

            dfs(depth + 1, i + 1);  //dfs 재귀
            selected[i] = false;
        }
    }
}

int main()
{
    cin >> n >> m;

    for(int i=0; i<n; i++)
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            //바이러스 좌표 저장
            if (map[i][j] == 2) {
                virus.push_back(make_pair(i, j));
;            }
            else if (map[i][j] == 0) {
                cnt++;  //빈칸 갯수 측정
            }
        }
    
    if (cnt == 0) {
        cout << 0 << "\n";
        return 0;
    }
    else {
        ans = INF;

        //m개의 바이러스 선정(dfs)
        dfs(0, 0);

        if (ans == INF) {
            cout << -1 << "\n";
        }
        else {
            cout << ans << "\n";
        }
    }
    return 0;
}
