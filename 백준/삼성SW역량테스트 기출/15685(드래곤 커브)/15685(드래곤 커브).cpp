// 15685(드래곤 커브).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;

int n; 
bool map[101][101];

typedef struct {
    int x, y, d, g;
}dragon;



int main()
{
    cin >> n;   //드래곤 갯수

    vector<dragon> dg;


    //드래곤에 대한 정보 삽입
    for (int i = 0; i < n; i++) {
        int tempx, tempy, tempd, tempg;
        cin >> tempx >> tempy >> tempd >> tempg;
        dg.push_back({ tempx, tempy, tempd, tempg });
    }

    while(n--){
    
        int c = dg[n].x;
        int r = dg[n].y;
        int dir = dg[n].d;
        int gen = dg[n].g;

        map[r][c] = true;

        vector<int> dirmemo;

        int nowgen = 0; //현재 세대
        dirmemo.push_back(dir); //0세대의 방향 삽입

        //끝세대 까지의 방향을 찾자
        while (nowgen != gen) {
            nowgen++;
            int length = dirmemo.size();
            //새로운 세대의 뱡항 삽입
            for (int i = length - 1; i >= 0; i--) {
                dirmemo.push_back((dirmemo[i] + 1) % 4);
            }
        }
        int nowc = c;
        int nowr = r;

        //좌표를 찍어라
        for (int i = 0; i < dirmemo.size(); i++) {
            int nextc=0, nextr=0;
            if (dirmemo[i] == 0) {
                nextc = nowc + 1;
                nextr = nowr;

            }
            else if (dirmemo[i] == 1) {
                nextc = nowc;
                nextr = nowr - 1;
            }
            else if (dirmemo[i] == 2) {
                nextc = nowc - 1;
                nextr = nowr;
            }
            else if (dirmemo[i] == 3) {
                nextc = nowc;
                nextr = nowr + 1;
            }
            map[nextr][nextc] = true;
            nowc = nextc;
            nowr = nextr;
        }
    }

    int ans = 0;
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++) {
            if (map[i][j] == true && map[i][j + 1] == true && map[i + 1][j] == true && map[i + 1][j + 1] == true)
                ans += 1;
        }

    cout << ans << "\n";
    return 0;

}