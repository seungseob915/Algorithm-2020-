// [17136] 색종이 붙이기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

int ans = 987654321, total = 0;
int board[11][11];  //다 붙였으면 2
int paper[6];  //색종이 사용 갯수
vector<pair<int,int>> one;

// 처리한 갯수
int simulate(int idx, int size) {
    int x = one[idx].first;
    int y = one[idx].second;
    
    int n_finish = 0;

    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (i < 1 || i>10 || j < 1 || j>10) return -1;
            if (board[i][j] != 1) return -1;
            if (board[i][j] == 2) return -1;
            board[i][j] = 2;
            n_finish++;
        }
    }
    return n_finish;
}

void dfs(int idx, int finish, int cnt) {
    // 다 붙였으면    
    if (finish == total) {
        ans = min(ans, cnt);
        return;
    }
    if (board[one[idx].first][one[idx].second] == 2)
        dfs(idx + 1, finish, cnt);

    else {
        int t_board[11][11];
        memcpy(t_board, board, sizeof(board));
        
        for (int k = 1; k <= 5; k++) {
            if (paper[k] == 5) continue;    //색종이가 5개면
            
            int t = simulate(idx, k);   //색종이 붙이자
            
            //붙일 수 없으면
            if (t == -1) {
                //원래것으로 백업
                memcpy(board, t_board, sizeof(t_board));
                continue;
            }

            paper[k]++;
            dfs(idx + 1, finish + t, cnt+1);
            paper[k]--;

            //백업이 필요합니다.
            memcpy(board, t_board, sizeof(t_board));
        }
    }
}

int main()
{
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            cin >> board[i][j];   

            if (board[i][j] == 1)
                one.push_back({ i,j });
        }
    }
    
    total = one.size();

    dfs(0, 0, 0);  // one[0]부터, 0개 처리함, 몇개붙였는지

    if (ans == 987654321)
        ans = -1;

    cout << ans;
}
