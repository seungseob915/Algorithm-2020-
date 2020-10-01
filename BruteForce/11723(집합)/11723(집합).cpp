// 11723(집합).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 비트마스크 사용 

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int m;
    cin >> m;

    int s=0, c;

    for (int i = 0; i <m; i++) {
        string cal;
        int n;
        cin >> cal;
        if (cal == "add") {
            cin >> n;
            s = s | (1 << n);
        }
        else if (cal == "remove") {
            cin >> n;
            s = s & ~(1 << n);
        }
        else if (cal == "check") {
            cin >> n;
            c = s & (1 << n);
            if (c == 0)
                cout << 0 << "\n";
            else
                cout << 1 << "\n";
        }
        else if (cal == "toggle") {
            cin >> n;
            s = s ^ (1 << n);
        }
        else if (cal == "all")
            s = (1 << 21) - 1;
        else if (cal == "empty")
            s = 0;
    }
    return 0;
}
