// 14499(주사위 굴리기).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, x, y, k, dir;

    cin >> n >> m >> x >> y >> k;
    
    vector <vector<int>> a(n, vector<int>(m));      // 지도에 쓰인 숫자
    int d[6] = { 0, };

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];          
        }
    
    for (int i = 0; i < k; i++) {
        cin >> dir;
        
        //동쪽
        if (dir == 1) {
            if (y + 1 >= m)
                continue;
            else {
                y += 1;

                swap(d[1], d[4]);
                swap(d[1], d[3]);
                swap(d[1], d[5]);
            }
        }
        //서쪽
        else if (dir == 2) {
            if (y - 1 < 0)
                continue;
            else {
                y -= 1;
                swap(d[1], d[4]);
                swap(d[4], d[5]);
                swap(d[4], d[3]);
            }
        }
        //북쪽
        else if (dir == 3) {
            if (x - 1 < 0)
                continue;
            else {
                x -= 1;
                swap(d[0], d[1]);
                swap(d[1], d[2]);
                swap(d[2], d[3]);
            }
        }
        //남쪽
        else if (dir == 4) {
            if (x + 1 >= n)
                continue;
            else {
                x += 1;
                swap(d[0], d[1]);
                swap(d[0], d[2]);
                swap(d[0], d[3]);
            }
        }
        if (a[x][y] == 0) {
            a[x][y] = d[3];
        }
        else {
            d[3] = a[x][y];
            a[x][y] = 0;
        }
        cout << d[1] << '\n';
    }
    return 0;
}
