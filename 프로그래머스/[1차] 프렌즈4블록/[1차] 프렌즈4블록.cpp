// [1차] 프렌즈4블록.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
/*
R: 라이언
M: 무지
A: 어피치
F: 프로도
N: 네오
T: 튜브
J: 제이지
C: 콘
빈칸: 0

판 a[m+1][n+1]
배치정보: board (string)

-사라지는 것
1. 그냥 모든 기준점 x,y 다 탐색
2. x,y 기준으로 똑같으면 check true 처리
3. 다 탐색하고 맨 마지막에 한번에 삭제

-세로로 내리는 것(밑으로 땡기는 함수)
void down_block(int y){
for(int i=m; i>=1; i--)
if(a[i][y]==0)
    for(int j=i-1; j>=1; j--)
        if(a[j][y]!=0)
            a[i][y]=a[j][y];
            a[j][y]=0;
            break;
}
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int m, n, cnt=0;
int dx[] = { 0, 0, 1, 1 }; //본인위치 아래 우 대각
int dy[] = { 0, 1, 0, 1 };
vector <string> board;
vector <string> copy_board;
bool check[31][31];


// 같은것들 check 함수 true 처리
void find(int i, int j) {
    char temp= board[i][j];

    if (temp == 0)
        return;

    // 2x2가 다 같다면
    if (board[i + 1][j] == temp && board[i + 1][j + 1] == temp && board[i][j + 1] == temp) {
        for (int k = 0; k < 4; k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];
            
            // 지워버리겠다고 체크
            check[nx][ny] = true;
        }
    }
    return;
}


void down_block(int y) {
    for (int i = m-1; i > 0; i--) {
        if (board[i][y] == 0) {
            for(int j=i-1; j>=0; j--)
                if (board[j][y] != 0) {
                    board[i][y] = board[j][y];
                    board[j][y] = 0;
                    break;
                }
        }
    }
    return;
}


int main()
{
    cin >> m >> n;

    
    memset(check, false, sizeof(check));

    //보드 정보 입력
    for (int i = 0; i < m; i++) {
        string temp;
        cin >> temp;
        board.push_back(temp);
        copy_board.push_back(temp);
    }

    while (true) {

        //사라지는 대상 탐색
        for (int i = 0; i <= m - 2; i++)
            for (int j = 0; j <= n - 2; j++) {
                find(i, j);
            }


        //사라지는 대상 삭제
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (check[i][j] == true) {
                    board[i][j] = 0;
                    check[i][j] = false;
                    cnt++;
                }
            }

        //밑으로 땡기기(가로만 탐색)
        for (int i = 0; i < n; i++)
            down_block(i);
       
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                cout << board[i][j] << " ";
            cout << "\n";
        }
        cout << "\n";


     if (copy_board == board)
            break;
        else
            copy_board = board;

    }
    //정답 출력
    cout << cnt;

    return 0;
}
