// 3190(뱀).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <cstring>
#include <utility>
using namespace std;

int a[100][100];        //보드
bool apple[100][100];   //사과 먹은 여부
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int main()
{
    int n, k, l;
    cin >> n;
    
    memset(a, -1, sizeof(a));      // 보드를 -1(빈칸)로 초기화

    //사과 위치 (-2)
    cin >> k;
    for (int i = 0; i < k; i++) {
        pair<int, int> temp;
        cin >> temp.first>>temp.second;
        apple[temp.first-1][temp.second-1] = true;       
    }

    //뱀의 최초 머리 위치
    int x = 0;
    int y = 0;
    int dir = 0;       // 최초 방향 오른쪽
    int length = 1;
    int time = 0;
    a[x][y] = 0;
   
    cin >> l;
    pair <int, char> p;

    for (int i = 0; i <= l; i++) {
        p.first = n * n + 1;
        p.second = 'L';
        if(i<l)
            cin >> p.first >> p.second;

        while (time < p.first) {
            //한턴 시작
            time += 1;

            x = x + dx[dir];
            y = y + dy[dir];

            //예외 처리(게임이 바로 끝날때:벽에 부딪힐때)
            if (x<0 || x>=n || y<0 || y>=n) {
                cout << time << "\n";
                return 0;
            }

            // 다음칸에 사과가 있을때
            if (apple[x][y] == true) {
                length += 1;
                apple[x][y] = false;
            }

            //예외 처리(게임이 바로 끝날때: 자기 몸에 부딪힐때)
            if (a[x][y] != -1 && time - a[x][y] <= length) {
                cout << time << "\n";
                return 0;
            }
            a[x][y] = time;
        }
        // 해당 시간 이후 방향전환 해야하는지 확인
        if (p.second == 'L') {
            dir = (dir + 3) % 4;
        }
        if (p.second == 'D') {
            dir = (dir + 1) % 4;
        }
    }
    return 0;
}
 

