// 2105(모의_디저트카페).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int t, n;
int ans;
int map[21][21];

int simulate() {
    int ret=-1;

    for (int x = 0; x < n - 2; x++) {
        for (int y = 1; y < n - 1; y++) {
            for (int d1 = 1; x + d1 <= n - 2 && y - d1 >= 0; d1++) {
                for (int d2 = 1; x + d1 + d2 <= n - 1 && y + d2 <= n - 1; d2++)  {
                    vector <int> dessert;
                    bool check = true;
                    int temp=0;

                    // 경계선 벡터에 저장
                    for (int i = 0; i <= d1; i++) {
                        dessert.push_back(map[x + i][y - i]);
                        dessert.push_back(map[x + i + d2][y - i + d2]);
                    }

                    // 중복되는 꼭지점 제거를 위해 i 범위 조정
                    for (int i = 1; i < d2; i++) {
                        dessert.push_back(map[x + i][y + i]);
                        dessert.push_back(map[x + i + d1][y + i - d1]);
                    }

                    // 중복된 수가 있다면 false
                    for (int i = 0; i < dessert.size(); i++) {
                        for (int j = i+1; j < dessert.size(); j++) {
                            //중복된게 있다면
                            if (dessert[i] == dessert[j]) {
                                check = false;
                            }
                        }
                    }

                    // 탐색 후 중복된게 없다면
                    if (check == true) {
                        temp = dessert.size();
                        ret = max(ret, temp);
                    }
                }
            }
        }
    }
    return ret;
}

int main()
{   
    cin >> t;   //testcase
    int ctt = 1;
    while (t--) {
        cin >> n;

        memset(map, 0, sizeof(map));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> map[i][j];

        ans = simulate();
        cout << "#"<<ctt<<" "<< ans << "\n";
        ctt++;
    }
}
