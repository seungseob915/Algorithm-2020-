// 크레인 인형뽑기 게임.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
/*

#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;
int row;
int col;

vector <vector<int>> map(5, vector<int> (5));
vector <int> moves(8);

// 크레인이 잡아서 놓는곳
vector <int> contain;


//크레인을 옮기는 함수
void moveC(int coln) {
    cout << "3단계 시작" << "\n";
    for (int i = 0; i < row; i++) {
        cout << "4단계 시작" << "\n";
        //인형을 찾으면
        if (map[i][coln] != 0) {
            contain.push_back(map[i][coln]);    //컨테이너에 넣고
            map[i][coln] = 0;

            int vsize=contain.size();
            cout << "5단계 시작" << "\n";

            //vsize가 2이상일때
            if (vsize > 1) {
                //만약 컨테이너 마지막 인형 2개가 연속되면 지우고 카운트
                if (contain[vsize - 1] == contain[vsize - 2]) {
                    contain.pop_back();
                    contain.pop_back();
                    cnt += 2;
                }
            }

            break;
        }
    }
}

void solution(vector<vector<int>> board, vector<int> moves) {
    //행갯수, 열갯수
    row = board.size();
    col = board[0].size();

    cout << "1단계" << "\n";

    //moves의 갯수만큼 크레인을 옮기자
    for (int i = 0; i < moves.size(); i++) {
        int now = moves[i]-1;
        cout << "2단계 시작" << "\n";
        moveC(now);
    }
}


int main()
{

    cout << "보드입력" <<"\n";

    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            cin >> map[i][j];

    cout << "moves 입력" << "\n";

    for (int i = 0; i < 8; i++)
        cin >> moves[i];

    solution(map, moves);

    cout << cnt;
    
    return 0;
}

*/

#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;
int row;
int col;

// 크레인이 잡아서 놓는곳
vector <int> contain;


//크레인을 옮기는 함수
void moveC(int coln, vector<vector<int>> &board, vector<int> &moves) {
    for (int i = 0; i < row; i++) {
        //인형을 찾으면
        if (board[i][coln] != 0) {
            contain.push_back(board[i][coln]);    //컨테이너에 넣고
            board[i][coln] = 0;

            int vsize = contain.size();

            //vsize가 2이상일때
            if (vsize > 1) {
                //만약 컨테이너 마지막 인형 2개가 연속되면 지우고 카운트
                if (contain[vsize - 1] == contain[vsize - 2]) {
                    contain.pop_back();
                    contain.pop_back();
                    cnt += 2;
                }
            }
            break;
        }
    }
}

int solution(vector<vector<int>> board, vector<int> moves) {
    //행갯수, 열갯수
    row = board.size();
    col = board[0].size();


    //moves의 갯수만큼 크레인을 옮기자
    for (int i = 0; i < moves.size(); i++) {
        int now = moves[i] - 1;
        moveC(now, board, moves);
    }

    return cnt;
}