// 16235(나무 재테크.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[10][10];  //땅 양분
int d[10][10];  //저장되어있는 양분
int p[10][10];  //새로 태어나는 나무
vector<int> tree[10][10];   //칸별 나무 나이 저장
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            d[i][j] = 5;    //최초 양분:5
        }

    //나무 갯수만큼 나이 저장
    while (m--) {
        int x, y, age;
        cin >> x >> y >> age;
        tree[x - 1][y - 1].push_back(age);
    }

    while (k--) {
        memset(p, 0, sizeof(p));
        for(int i=0; i<n; i++)
            for (int j = 0; j < n; j++) {
                vector<int> temp;   //임시 저장
                //어린 나무부터 양분 주기
                sort(tree[i][j].begin(), tree[i][j].end());
                int dead = 0;
                for (int x : tree[i][j]) {
                    if (x <= d[i][j]) {
                        d[i][j] -= x;   //나무 양분주기
                        temp.push_back(x + 1);
                        if ((x + 1) % 5 == 0) {
                            for (int k = 0; k < 8; k++) {
                                int nx = i + dx[k];
                                int ny = j + dy[k];
                                if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                                    p[nx][ny] += 1;
                                }
                            }
                        }
                    }
                    else {
                        dead += x / 2;
                    }
                }
                tree[i][j] = temp;
                d[i][j] += dead;        //여름
                d[i][j] += a[i][j];     //겨울
            }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < p[i][j]; k++)
                    tree[i][j].push_back(1);    //인접한 8개 칸에 나이 1인 나무 생성
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans += (int)tree[i][j].size();

    cout << ans << "\n";
    return 0;

}
