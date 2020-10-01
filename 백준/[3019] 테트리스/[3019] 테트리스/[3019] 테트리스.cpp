// [3019] 테트리스.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int C, P, ans = 0;
bool board[101][101];

int main()
{
    cin >> C >> P;
    for (int i = 1; i <= C; i++) {
        int temp;
        cin >> temp;
        
        int start = 100;
        
        while (temp--) {
            board[start][i] = true;
            start--;
        }
    }



    if (P == 1) {
        int suc = 2;

        //긴 막대
        for (int k = 0; k < 4; k++) {
            if (board[x - k][y]) {
                suc--;
                break;
            }
        }

        for (int k = 0; k < 4; k++) {
            if (board[x][y+k]) {
                suc--;
                break;
            }
        }

        ans += suc;
    }

    else if (P == 2) {

    }
}
