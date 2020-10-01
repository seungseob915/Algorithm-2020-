// 14502(연구소).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;

int n, m;
int a[10][10];
int b[10][10];


int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

void go(int x, int y) {     //바이러스 확산(좌표 x,y)
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < n && ny < m && nx >= 0 && ny >= 0) {
            if (b[nx][ny] == 0) {
                b[nx][ny] = 2;
                go(nx, ny);
            }
        }
    }
}

void backup() {     //a행렬 백업
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            b[i][j] = a[i][j];
        }
    return;
}

int find() {     //0의 갯수 탐색
    backup();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (b[i][j] == 2)
                go(i, j);
    int cnt = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (b[i][j] == 0)
                cnt += 1;
    return cnt;
}


int main()
{
    cin >> n >> m;

    vector <pair <int, int>> xy;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 0)
                xy.push_back(make_pair(i, j));
        }
    int ans = -1;
    for (int i = 0; i < xy.size(); i++)
        for (int j = 0; j < xy.size(); j++)
            for (int k = 0; k < xy.size(); k++){
                if (xy[i].first == xy[j].first && xy[i].second == xy[j].second)
                    continue;
                if (xy[i].first == xy[k].first && xy[i].second == xy[k].second)
                    continue;
                if (xy[k].first == xy[j].first && xy[k].second == xy[j].second)
                    continue;

                a[xy[i].first][xy[i].second] = 1;
                a[xy[j].first][xy[j].second] = 1;
                a[xy[k].first][xy[k].second] = 1;
              
                int temp = find();
                if (ans < temp)
                    ans = temp;

                a[xy[i].first][xy[i].second] = 0;
                a[xy[j].first][xy[j].second] = 0;
                a[xy[k].first][xy[k].second] = 0;
            }
    cout << ans << "\n";
    return 0;
}
