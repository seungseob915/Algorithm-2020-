// 17142(연구소3).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include<cstring>

using namespace std;

int n, m, room=0;
int map[51][51];
int copymap[51][51];        // 0: 활성, -1: 빈칸, -2: 벽돌, -3: 비활성
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
int ans=-1;


int main()
{
    cin >> n >> m;      //m:활성화 바이러스 갯수

    vector<pair<int, int>> virus;
    vector<int> permu;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) {   //바이러스를 찾으면
                virus.push_back(make_pair(i, j));
                permu.push_back(0);
            }
            else if(map[i][j]==0)
                room=room+1;
        }

    
    // 순열 생성
    for (int i = 0; i < m; i++)
        permu[i] = 1;

    sort(permu.begin(), permu.end());


    do {
        // copymap 초기화
        memset(copymap, -1, sizeof(copymap));       // 빈칸 : -1;

        int t_room=0;  //빈방 수 (비활성화 마지막 남이있을때 비교하기 위한 조치)
        
        queue <pair<int, int>> q;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (map[i][j] == 1)
                {
                    copymap[i][j] = -2; //임시 맵에 벽돌 생성
                }
            }

        //활성화 바이러스 선정 후 큐 삽입
        for (int i = 0; i < permu.size(); i++) {
            if (permu[i] == 1) { // 순열 1이면 활성화
                q.push(virus[i]);
                copymap[virus[i].first][virus[i].second] = 0;
            }
            else if (permu[i] == 0) {
                copymap[virus[i].first][virus[i].second] = -3;
            }
        }
        

        //bfs 시작
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                                                   
                //범위를 벗어날때
                if (nx >= n || nx < 0 || ny >= n || ny < 0)
                    continue;
                // 이미 방문 했을 때
                if (copymap[nx][ny] >= 0)
                    continue;
                //벽돌일 때
                if (copymap[nx][ny] == -2)
                    continue;

                if(copymap[nx][ny]==-1)
                    t_room++;  //빈칸에 바이러스를 채울 때마다 room--, 비활성 바이러스는 미포함

                if (t_room == room && copymap[nx][ny] == -3)
                    break;

                q.push(make_pair(nx, ny));
                copymap[nx][ny] = copymap[x][y] + 1;
              
            }
        }

        int temp=-50;
        if (t_room == room) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    temp = max(temp, copymap[i][j]);
                }
            }
        }
        else
            temp = -1;
        
        if (temp == -1 && ans == -1) {
            ans = -1;
        }
        else if (ans != -1 && temp != -1) {
            ans = min(temp, ans);
        }
        else if (ans == -1 && temp != -1) {
            ans = temp;
        }
        else if (ans != -1 && temp == -1) {
            ans = ans;
        }

    } while (next_permutation(permu.begin(), permu.end()));
    
    cout << ans;
    return 0;
}