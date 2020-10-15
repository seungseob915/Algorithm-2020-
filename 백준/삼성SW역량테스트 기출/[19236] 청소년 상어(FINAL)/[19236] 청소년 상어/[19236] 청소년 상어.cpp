// [19236] 청소년 상어.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Fish {
    int x, y, dir;
    bool dead;
}F;

typedef struct Shark {
    int x, y, dir;
}S;

int ans = 0;
int board[5][5] = {};
F f[17] = {};
S s = {};
int dx[] = {0, -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = {0, 0, -1, -1, -1, 0, 1, 1, 1 };

void moveFish() {

    for (int i = 1; i <= 16; i++) {
        if (f[i].dead) continue;

        int x = f[i].x;
        int y = f[i].y;
        int dir = f[i].dir;

        // 다 돌았는데도 이동 못하면 그대로 false
        int cnt = 8;

        //방향 8번 가자(현방향부터 시작)
        while (cnt--) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 1 || nx>4 || ny < 1 || ny>4) {}
            else if (board[nx][ny] == -1) {}
            //물고기일때
            else if (board[nx][ny] >= 1 && board[nx][ny] <= 16) {
                int temp = board[nx][ny];
                board[nx][ny] = i;
                f[i].x = nx;
                f[i].y = ny;
                f[i].dir = dir;

                board[x][y] = temp;
                f[temp].x = x;
                f[temp].y = y;
                break;
            }
            //빈칸일때
            else if (board[nx][ny] == 0) {
                board[nx][ny] = i;
                f[i].x = nx;
                f[i].y = ny;
                f[i].dir = dir;

                board[x][y] = 0;
                break;
            }
            dir++;
            if (dir == 9) dir = 1;
        }
    }
}

//상어 갈 위치 선정
void dfs(int score) {
    //물고기 먼저 이동
    moveFish();

    //물고기정보 초기화
    F tf[17];
    for (int i = 1; i <= 16; i++) {
        tf[i].x = f[i].x;
        tf[i].y = f[i].y;
        tf[i].dir = f[i].dir;
        tf[i].dead = f[i].dead;
    }
    //상어정보 초기화
    S t_s;
    t_s = s;
    //보드정보 초기화
    int t_board[5][5];
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            t_board[i][j] = board[i][j];
        }
    }

    //상어가 갈수 있는 칸
    for (int k = 1; k <= 3; k++) {
        int x = s.x;
        int y = s.y;
        int nx = s.x + dx[s.dir] * k;
        int ny = s.y + dy[s.dir] * k;

        if (nx < 1 || nx>4 || ny < 1 || ny>4) continue;
        if (board[nx][ny] < 1) continue;

        s.x = nx;
        s.y = ny;
        s.dir = f[board[nx][ny]].dir;
        f[board[nx][ny]].dead = true;
        int ts = board[nx][ny];
        board[x][y] = 0;
        board[nx][ny] = -1;

        dfs(score + ts);

        for (int i = 1; i <= 16; i++) {
            f[i].x = tf[i].x;
            f[i].y = tf[i].y;
            f[i].dir = tf[i].dir;
            f[i].dead = tf[i].dead;
        }
        s = t_s;
        for (int i = 1; i <= 4; i++) {
            for (int j = 1; j <= 4; j++) {
                board[i][j] = t_board[i][j];
            }
        }
    }
    ans = max(ans, score);
}

int main()
{
    //상어 초기화
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            cin >> board[i][j];
            cin >> f[board[i][j]].dir;
            f[board[i][j]].x = i;
            f[board[i][j]].y = j;
            f[board[i][j]].dead = false;
       }
    }

    //처음 상어위치 (1,1)로 들어옴
    int score = 0;
    s.x = 1;
    s.y = 1;
    s.dir = f[board[1][1]].dir;
    f[board[1][1]].dead = true;
    score += board[1][1];
    board[1][1]=-1;

    // 시작하자
    dfs(score);

    cout << ans;
}