// 캐슬 디펜스.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, d;
int ans = 0;
int enemy_num = 0;
int enemy_kill = 0;
int map[16][16];
bool goongsoo[16];

//궁수로부터의 최소 적 거리 >> 해당 적 좌표 output
pair<int,int> distance(int x, int y, int map[16][16]) {
    int dis = 987654321;
    int rx=-1;
    int ry=-1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 1) {
                int nx = abs(n - i);
                int ny = abs(y - j);
                int t_dis = nx + ny;

                //거리가 사격거리보다 작으면
                if (t_dis <= d) {
                    if (t_dis == dis && j<ry) {
                        rx = i;
                        ry = j;
                    }
                    else if (t_dis < dis) {
                        rx = i;
                        ry = j;
                        dis = t_dis;
                    }
                }
            }
        }
    }
    return make_pair(rx, ry);
}

//적 제거 수 계산
int simulate(bool goongsoo[]) {
    enemy_kill = 0;

    int t_map[16][16];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            t_map[i][j] = map[i][j];
        }
    }

    int tr = n;
    // 모든 적이 없어질때까지
    while (tr--) {
        vector <pair<int, int>> tv;

        for (int i = 0; i < m; i++) {
            if (goongsoo[i] == true) {
                pair<int, int> t = distance(n, i, t_map);
                if (t.first == -1)
                    continue;
                tv.push_back(t);
            }
        }
            
        tv.erase(unique(tv.begin(), tv.end()), tv.end());
        enemy_kill+=tv.size();

        if (enemy_kill == enemy_num) {
            return enemy_kill;
        }
        for(int i=0; i<tv.size(); i++){
            t_map[tv[i].first][tv[i].second] = 0;
        }

        //적이 이동하는 패턴
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                //적이 성으로 접근하는경우
                if (t_map[i][j] == 1) {
                    if (i == n - 1) {
                        t_map[n - 1][j] = 0;
                        //return enemy_kill;
                    }
                    else {
                        //1이면 아래로 이동
                        t_map[i + 1][j] = 1;
                        t_map[i][j] = 0;
                    }
                }
            }
        }
    }
    return enemy_kill;
}

//우선 궁수 위치(순열)부터 구하자
void dfs(int start, int cnt) {
    if (cnt == 3) {
        ans=max(ans, simulate(goongsoo));
        return;
    }

    for (int i = start; i < m; i++) {
        goongsoo[i] = true;

        dfs(i + 1, cnt + 1);

        goongsoo[i] = false;
    }
}


int main(){
    cin >> n >> m>>d;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1) {
                enemy_num++;
            }
        }
    }
    dfs(0, 0);

    cout << ans;
}