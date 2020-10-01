// 6064(카잉 달력).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int t;  //testcase

int main()
{
    cin >> t;
    while (t--) {
        int m, n, x, y;
        bool find = false;
        cin >> m >> n >> x >> y;
        
        int cnt = x;

        for (cnt = x; cnt < (m * n); cnt += m) {
            int yy = cnt % n;
            if (yy == 0)
                yy = n;
            if (yy == y) {
                cout << cnt << "\n";
                find = true;
                break;
            }
        }
        if(find==false)
            cout << -1 << "\n";
    }
}
