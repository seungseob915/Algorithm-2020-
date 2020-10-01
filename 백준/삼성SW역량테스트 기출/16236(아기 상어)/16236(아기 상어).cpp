// 16236(아기 상어).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>

using namespace std;

int dx[] = { 1, 0, 0, -1 };
int dy[] = { 0, 1, -1, 0 };

//상어와 가장 거리가 가까운 물고기의 위치를 찾는 bfs(최소거리)
tuple<int, int, int> bfs(tuple<int, int, int> shark, vector<vector<int>> &a) {
    int n = a.size();
    vector<tuple<int, int, int>> ans;
    vector<vector<int>> c(n, vector<int>(n, -1));   //거리
    
    int x, y, size;
    tie(x, y, size) = shark;

    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    c[x][y] = 0;    //거리값 초기화

    while (!q.empty()) {
        tie(x, y) = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < n && c[nx][ny] == -1) {
                bool ok = false;        //통과 가능여부
                bool eat = false;       //취식 가능여부

                if (a[nx][ny] == 0) {
                    ok = true;
                }
                else if (a[nx][ny] < size) {
                    ok = true;
                    eat = true;
                }
                else if (a[nx][ny] == size) {
                    ok = true;
                }
                if (ok) {
                    q.push(make_pair(nx, ny));
                    c[nx][ny] = c[x][y] + 1;
                    if (eat) {
                        ans.push_back(make_tuple(c[nx][ny], nx, ny));
                    }
                }
            }
        }
    }
    // 상어가 갈곳이 없으면
    if (ans.empty()) {
        return make_tuple(-1, -1, -1);
    }
    // 최소거리 먹은 경우 출력(시간이랑 동일 1칸 이동하는데 1초)
    sort(ans.begin(), ans.end());
    return ans[0];
}



int main()
{
    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(n));
    vector<tuple<int, int, int>> fish;
    tuple<int, int, int> shark;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 9) {   //아기 상어 정보저장
                shark = make_tuple(i, j, 2);
                a[i][j] = 0;
            }
        }
    int ans = 0;
    int size = 2;
    int exp = 0;
    while (true) {
        int nx, ny, dist;
        tie(dist, nx, ny) = bfs(shark, a);
        if (dist == -1)
            break;
        a[nx][ny] = 0;
        ans += dist;    //시간(1칸이동하는데 1초)
        exp += 1;
        if (size == exp) {
            size += 1;
            exp = 0;
        }
        shark = make_tuple(nx, ny, size);
    }
    cout << ans << '\n';
    return 0;
}
