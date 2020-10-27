// [1780] 종이의 개수.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;

int N;
int ans[3] = { 0, };

vector<vector<int> > board;

void find(int x, int y, int length) {
    if (length == 1) {
        ans[board[x][y]+1]++;
        return;
    }

    bool flag = true;
    int chk = board[x][y];
    for (int i = x; i < x + length; i++) {
        for (int j = y; j < y + length; j++) {
            if (chk != board[i][j]) {
                flag = false;
                break;
            }
        }
    }

    if (flag) ans[chk + 1]++;
    else {
        int nlen = length / 3;
        find(x, y, nlen);
        find(x+nlen, y, nlen);
        find(x+(2*nlen), y, nlen);
        find(x, y+nlen, nlen);
        find(x+nlen, y+nlen, nlen);
        find(x+(2*nlen), y+nlen, nlen);
        find(x, y+(2*nlen), nlen);
        find(x+nlen, y+(2*nlen), nlen);
        find(x+(2*nlen), y+(2*nlen), nlen);
    }
}

int main()
{
    cin >> N;
    board.resize(N, vector<int>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    find(0, 0, N);
    for (int i = 0; i < 3; i++) cout << ans[i] << endl;
}