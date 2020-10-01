// 17142(연구소 3).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
int a[52][52];
int check[52][52];
vector<pair<int, int>> virus;       //virus의 좌표
vector<int> v_permu;                //활성화 바이러스 index
int ans = 987654321;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1 ,0 };

//활성화 바이러스 퍼지기 시작
void bfs() {
    
    //큐 생성
    queue<pair<int, int>> q;

    //최초 활성화 바이러스 큐 삽입
    for (int i = 0; i < v_permu.size(); i++) {
        if (v_permu[i]) {
            q.push(virus[i]);
            check[virus[i].first][virus[i].second] = 0;
        }
    }

    while (!q.empty()) {
        pair<int, int> temp = q.front();
        q.pop();

        // 4방향 전개
        for (int i = 0; i < 4; i++) {
            int ni = temp.first + dx[i];
            int nj = temp.second + dy[i];

            //다음 방향이 범위를 초과할 때
            if (ni < 0 || ni >= n || nj < 0 || nj >= n)
                continue;

            //이미 방문 했을 때
            if (check[ni][nj] != -1)
                continue;

            // 다음 방향이 벽일 경우
            if (a[ni][nj] = 1)
                continue;

            q.push(make_pair(ni, nj));
            check[ni][nj] = check[temp.first][temp.second] + 1;
        }
    }
}


int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            check[i][j] == -1;
            if (a[i][j] == 2) {
                virus.push_back(make_pair(i, j));
                v_permu.push_back(0);
            }
        }
    

    // 바이러스 m개 뽑는 순열 구하기
    for (int i = 0; i < m; i++)
        v_permu.pop_back();

    for (int i = 0; i < m; i++)
        v_permu.push_back(1);

    sort(v_permu.begin(), v_permu.end());

    // 활성화 바이러스 순열로 돌리기
    do {
        bool find = false;
        int time = 0;
        
        bfs();

        // 최초 배열로 원상태
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (time < check[i][j] && a[i][j] == 0)
                    time = check[i][j];

                if (check[i][j] == -1 && a[i][j] != 1) {
                    find = true;
                }
                check[i][j] = -1;
            }
        }
            if (find == false)
                if (time < ans)
                    ans = time;

    } while (next_permutation(v_permu.begin(), v_permu.end()));

    if (ans == 987654321)
        cout << -1;
    else
        cout << ans;
    return 0;
}
