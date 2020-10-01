// [14499] 주사위 굴리기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

typedef struct Dice {
    int x, y;
}D;

int N, M, X, Y, K;
D now_loc;
int d_num[6];  //주사위 면
int board[21][21];
int dx[] = {0, 0,0,-1,1 };
int dy[] = {0, 1,-1,0,0 };

void simulate(int dir) {
    //먼저 갈수 있는곳인지부터 체크
    D next = { now_loc.x + dx[dir], now_loc.y + dy[dir] };

    if (next.x<0 || next.x>N - 1 || next.y<0 || next.y>M - 1)
        return;

    now_loc = next;

    if (dir == 1) {
        int temp = d_num[2];
        d_num[2] = d_num[0];
        d_num[0] = d_num[1];
        d_num[1] = d_num[5];
        d_num[5] = temp;
    }
    else if (dir == 2) {
        int temp = d_num[1];
        d_num[1] = d_num[0];
        d_num[0] = d_num[2];
        d_num[2] = d_num[5];
        d_num[5] = temp;
    }
    else if (dir == 3) {
        int temp = d_num[3];
        d_num[3] = d_num[0];
        d_num[0] = d_num[4];
        d_num[4] = d_num[5];
        d_num[5] = temp;
    }
    else {
        int temp = d_num[5];
        d_num[5] = d_num[4];
        d_num[4] = d_num[0];
        d_num[0] = d_num[3];
        d_num[3] = temp;
    }

    if (board[now_loc.x][now_loc.y] == 0)
        board[now_loc.x][now_loc.y] = d_num[5];
    
    else {
        d_num[5] = board[now_loc.x][now_loc.y];
        board[now_loc.x][now_loc.y] = 0;
    }

    cout << d_num[0]<<endl;   //갈수 있을때는 윗면 출력한다
}

int main()
{
    cin >> N >> M >> X >> Y >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    now_loc = { X, Y };

    for (int i = 0; i < K; i++) {
        int order;
        cin >> order;

        simulate(order);
    }

    return 0;
}