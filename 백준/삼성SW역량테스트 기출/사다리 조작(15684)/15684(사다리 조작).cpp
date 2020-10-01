// 사다리 조작(15684).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 순열을 다중 for문 을 이용해 해결(완탐)

#include <iostream>
#include<vector>
using namespace std;

int n, m, h;
int map[31][31];   //가로선 삽입 여부 >>0: 가로없음 1: 우측연결, 2: 좌측연결

int start(int c) {
    // 시뮬레이션( i점에서 시작했을 때, i로 오는지?)
    
    for (int r = 0; r <= h+1; r++) {
        if (map[r][c] == 1)    //좌측으로 길있을때
            c = c + 1;
        else if (map[r][c] == 2)
            c = c - 1;
    }
    return c;
}

//모든 c축의 수가 사다리를 타고내려왔을 때 그대로 나오는지?
bool go() {
    for (int j = 1; j <= n; j++) {
       int temp = start(j);
       if (temp != j)
           return false;
    }
    return true;
}

int main()
{
    cin >> n >> m >> h;     //n: 세로선 개수, h: 가로선 개수

    for (int i = 0; i <= h + 1; i++)  // 가로선 갯수
        for (int j = 1; j <= n; j++)    //세로선 갯수
            map[i][j] = 0;

    for (int i = 0; i < m; i++) {
        int tempx, tempy;
        cin >> tempx >> tempy;
        map[tempx][tempy] = 1;
        map[tempx][tempy + 1] = 2;
    }


    // 임의 3개의 사다리 설치를 위한 순열 만들기
    vector<pair<int, int>> add;
    for (int i = 1; i <= h; i++)  // 가로선 갯수
        for (int j = 1; j <= n-1; j++) {   //세로선 갯수
            if (map[i][j] != 0)
                continue;
            if (map[i][j + 1] != 0)
                continue;
            add.push_back(make_pair(i, j));
        }



    int ans = -1;

    if (go()) {
        cout << 0 << "\n";
        return 0;
    }

    //1개인 경우
    for (int i = 0; i < add.size(); i++) {
        int tempx = add[i].first;
        int tempy = add[i].second;
        if (map[tempx][tempy] != 0 || map[tempx][tempy + 1] != 0)
            continue;
        map[tempx][tempy] = 1;
        map[tempx][tempy+1] = 2;

        if (go()) {
            if (ans == -1 || ans > 1)
                ans = 1;
        }

        //2개인경우(2중포문)
        for (int j = i + 1; j < add.size(); j++) {
            int tempx2 = add[j].first;
            int tempy2 = add[j].second;
            if (map[tempx2][tempy2] != 0 || map[tempx2][tempy2 + 1] != 0)
                continue;
            map[tempx2][tempy2] = 1;
            map[tempx2][tempy2+1] = 2;

            if (go()) {
                if (ans == -1 || ans > 2)
                    ans = 2;
            }

            //3개인경우(3중포문)
            for (int k = j + 1; k < add.size(); k++) {
                int tempx3 = add[k].first;
                int tempy3 = add[k].second;
                if (map[tempx3][tempy3] != 0 || map[tempx3][tempy3 + 1] != 0)
                    continue;
                map[tempx3][tempy3] = 1;
                map[tempx3][tempy3+1] = 2;

                if (go()) {
                    if (ans == -1 || ans > 3)
                        ans = 3;
                }
                map[tempx3][tempy3] = 0;
                map[tempx3][tempy3 + 1] = 0; 
            }
            map[tempx2][tempy2] = 0;
            map[tempx2][tempy2 + 1] = 0;
        }
        map[tempx][tempy] = 0;
        map[tempx][tempy + 1] = 0;
    }


    cout << ans << "\n";
    return 0;
}
