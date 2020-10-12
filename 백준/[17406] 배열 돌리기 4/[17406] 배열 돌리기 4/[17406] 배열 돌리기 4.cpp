// [17406] 배열 돌리기 4.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

typedef struct Order {
    int r, c, s;
}order;
int board[51][51];
order o[7] = {};
bool chk[7];
int N, M, K, ans=987654321;

void rotate(int no) {
    order now_ord = o[no];

    int center_x = now_ord.r;
    int center_y = now_ord.c;
    int layer = now_ord.s;
    int row_size = 1;   //가로세로 길이

    // 층(layer) 만큼
    for (int l = 1; l <= layer; l++) {
        center_x = center_x - 1;
        center_y = center_y - 1;
        row_size += 2;

        // (x,y) 지점 임시저장
        int temp = board[center_x][center_y];
        int nx = center_x;
        int ny = center_y;

        for (int k = 4; k >= 1; k--) {
            if (k == 4) {
                for (int i = 1; i < row_size; i++) {
                    board[nx][ny] = board[nx+1][ny];
                    nx++;
                }
            }
            else if (k == 3) {
                for (int i = 1; i < row_size; i++) {
                    board[nx][ny] = board[nx][ny+1];
                    ny++;
                }
            }
            else if (k == 2) {
                for (int i = 1; i < row_size; i++) {
                    board[nx][ny] = board[nx-1][ny];
                    nx--;
                }
            }
            else {
                for (int i = 1; i < row_size; i++) {
                    board[nx][ny] = board[nx][ny-1];
                    ny--;
                }
            }
        }
        board[center_x][center_y+1] = temp;
    }
}

void dfs(int depth) {
    if (depth == K) {
        int ret = 987654321;

        for (int i = 1; i <= N; i++) {
            int sum = 0;
            for (int j = 1; j <= M; j++) {
                sum += board[i][j];
            }
            ret = min(ret, sum);
        }
        
        ans = min(ret, ans);
        return;
    }

    int t_board[51][51];
    memcpy(t_board, board, sizeof(board));

    for (int i = 1; i <= K; i++) {
        if (chk[i]) continue;

        rotate(i);
        chk[i] = true;
        dfs(depth + 1);
        chk[i] = false;
        memcpy(board, t_board, sizeof(t_board));
    }
}

int main()
{
    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 1; i <= K; i++)
        cin >> o[i].r >> o[i].c >> o[i].s;

    dfs(0);

    cout << ans;
}