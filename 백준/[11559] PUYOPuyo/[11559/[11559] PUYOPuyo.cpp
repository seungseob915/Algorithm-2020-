﻿#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

typedef struct Location {
    int x, y;
}loc;

char board[13][7];
int check[13][7];
loc wait[100];
int n = 12, m = 6, ans = 0, w_size=0;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void simulate() {

    while (1) {
        if (w_size == 0)   //끝나면
            break;

        bool pop = false;
        int c = 0;
        int del[100];
        memset(check, -1, sizeof(check));

        // 좌표부터 탐색
        for (int i = 0; i < w_size; i++) {
            int depth = 1;
            queue <loc> q;
            if (check[wait[i].x][wait[i].y] != -1)
                continue;
            q.push(wait[i]);
            char std = board[wait[i].x][wait[i].y];
            check[wait[i].x][wait[i].y] = c;

            while (!q.empty()) {
                loc now = q.front();
                q.pop();

                for (int k = 0; k < 4; k++) {
                    loc next = { now.x + dx[k], now.y + dy[k] };

                    if (next.x > 11 || next.x < 0 || next.y >5 || next.y < 0)   continue;
                    if (board[next.x][next.y] != std)  continue;
                    if (check[next.x][next.y] != -1)    continue;

                    q.push(next);
                    check[next.x][next.y] = check[now.x][now.y];
                    depth++;
                }
            }
            if (depth >= 4) {
                pop = true;
                del[c]=c;
            }
            c++;
        }

        // 하나라도 터졌으면 ans++, 터진게 있으면 내려야겠지
        if (pop) {
            ans++;

            for (int x = 0; x < n; x++) {
                for (int y = 0; y < m; y++) {
                    for (int k = 0; k < c; k++) {
                        if (check[x][y] == c) {
                            board[x][y] = '.';
                            break;
                        }
                    }
                }
            }

            // 내리자
            for (int y = 0; y < m; y++) {
                for (int x = n - 1; x >= 0; x--) {
                    if (board[x][y] == '.') {
                        for (int k = x - 1; k >= 0; k--) {
                            if (board[k][y] != '.') {
                                board[x][y] = board[k][y];
                                board[k][y] = board[x][y];
                                break;
                            }
                        }
                    }
                }
            }

            w_size = 0;

            for (int x = 0; x < n; x++) {
                for (int y = 0; y < m; y++) {
                    if (board[x][y] != '.') {
                        wait[w_size]={ x,y };
                        w_size++;
                    }
                }
            }
        }

    }
}

int main()
{
    w_size = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] != '.') {
                wait[w_size]={ i, j };
                w_size++;
            }
        }
    }

    simulate();

    cout << ans;

    return 0;
}
