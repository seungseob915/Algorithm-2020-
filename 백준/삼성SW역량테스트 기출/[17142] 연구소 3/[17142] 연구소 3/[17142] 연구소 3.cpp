// [17142] 연구소 3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include <vector>
#include<algorithm>

using namespace std;

int blk = 0, virus_cnt=0, N, M, time = 987654321;
int board[51][51];
int chk[51][51];
vector <pair<int, int>> virus;
deque <pair<int ,int>> act;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

int simulate() {
    int t_chk[51][51];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            t_chk[i][j] = chk[i][j];
        }
    }

    int t_blk = blk;        //빈칸 갯수: 다못채울수도있으니까? 그때는 false 리턴
    int t_time = -1;
    deque <pair<int, int>> t_act = act;

    while (!t_act.empty()) {
        int x = t_act.front().first;
        int y = t_act.front().second;
        t_act.pop_front();

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx<1 || nx>N || ny<1 || ny>N) continue;
            if (t_chk[nx][ny] == -3) continue;
            if (t_chk[nx][ny] >= 0) continue;
            if (t_chk[nx][ny] == -1) {
                t_act.push_back({ nx, ny });
                t_chk[nx][ny] = t_chk[x][y] + 1;
            }
            if (t_chk[nx][ny] == -2) {
                t_act.push_back({ nx, ny });
                t_chk[nx][ny] = t_chk[x][y] + 1;
                t_blk--;
                //빈칸이 다 사라졌으면
                if (t_blk == 0) {
                    t_time = t_chk[nx][ny];
                }
            }
        }
    }
    // 빈칸이 제거됐으면
    if (t_blk == 0) {
        return t_time;
    }
    else {
        return -1;
    }
}

void dfs(int depth, int idx) {
    if (depth == M) {
        int t_time = simulate();
        if(t_time!=-1)
            time=min(time, t_time);
        return;
    }

    for (int i = idx + 1; i < virus_cnt; i++) {
        act.push_back({virus[i].first, virus[i].second});
        chk[virus[i].first][virus[i].second] = 0;
        dfs(depth + 1, i);
        chk[virus[i].first][virus[i].second] = -1;
        act.pop_back();
    }
}

int main()
{
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) {
                virus.push_back({ i, j });
                chk[i][j] = -1;
            }
            else if (board[i][j] == 0) {
                blk++;
                chk[i][j] = -2;
            }
            else {
                chk[i][j] = -3;
            }
        }
    }

    virus_cnt = virus.size();
           
    if (blk == 0) {
        time = 0;
    }

    //조합 만들자
    dfs(0, -1);

    if (time == 987654321)
        time = -1;

    cout << time;
}
