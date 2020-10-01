// [모의 SW 역량테스트] 활주로 건설.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <math.h>
using namespace std;

int board[21][21];
int N, X, cnt=0, T, Tcnt=1;

void simulate1(int h) {
    int check[21] = {};

    // 가로 탐색
    for (int j = 1; j <= N-1; j++) {
        if (abs(board[h][j] - board[h][j+1]) >= 2) {
            return;
        }
        // 차이가 1 날 때 
        if (board[h][j] - board[h][j + 1] == 1) {
            for (int i = 0; i < X; i++) {
                if (j + 1 + i > N) {
                    return;
                }
                if (check[j + 1 + i] == 1) {
                    return;
                }
                if (board[h][j + 1 + i] != board[h][j + 1]) {
                    return;
                }
                check[j + 1 + i] = 1;
            }
        }
        //차이가 -1 날 때
        else if (board[h][j] - board[h][j + 1] == -1) {
            for (int i = 0; i < X; i++) {
                if (j - i < 1)
                    return;
                if (check[j - i] == 1)
                    return;
                if (board[h][j - i] != board[h][j]) {
                    return;
                }
                check[j - i]=1;
            }
        }
    }
    cnt++;
}

void simulate2(int w) {
    int check[21] = {};

    // 가로 탐색
    for (int j = 1; j <= N - 1; j++) {
        if (abs(board[j][w] - board[j+1][w]) >= 2) {
            return;
        }
        // 차이가 1 날 때 
        if (board[j][w] - board[j+1][w] == 1) {
            for (int i = 0; i < X; i++) {
                if (j + 1 + i > N) {
                    return;
                }
                if (check[j + 1 + i] == 1) {
                    return;
                }
                if (board[j+1+i][w] != board[j+1][w]) {
                    return;
                }
                check[j + 1 + i] = 1;
            }
        }
        //차이가 -1 날 때
        else if (board[j][w] - board[j+1][w] == -1) {
            for (int i = 0; i < X; i++) {
                if (j - i < 1)
                    return;
                if (check[j - i] == 1)
                    return;
                if (board[j-i][w] != board[j][w]) {
                    return;
                }
                check[j - i] = 1;
            }
        }
    }
    cnt++;
}

int main()
{
    cin >> T;

    while (T--) {
        cin >> N >> X;

        cnt = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                cin >> board[i][j];
            }
        }

        //가로만 검사해보자
        for (int i = 1; i <= N; i++) {
            simulate1(i);
        }

        //세로만 검사해보자
        for (int i = 1; i <= N; i++) {
            simulate2(i);
        }

        cout << "#"<<Tcnt<<" "<<cnt<<endl;
        Tcnt++;
    }
}