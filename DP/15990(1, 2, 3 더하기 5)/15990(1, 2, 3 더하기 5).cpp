// 15990(1, 2, 3 더하기 5).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#// 15988(1, 2, 3 더하기 3).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 메모이제이션 기법은 stack overflow가 발생해서 시간초과가 발생함

#include <iostream>
using namespace std;

int n;
long long int d[1000001][4];

int main()
{
    cin >> n;
    for (int i = 1; i < 1000001; i++) {
        if (i - 1 >= 0) {
            d[i][1] = d[i - 1][2] + d[i - 1][3];
            if (i == 1)
                d[i][1] = 1;
        }

        if (i - 2 >= 0) {
            d[i][2] = d[i - 2][1] + d[i - 2][3];
            if (i == 2)
                d[i][2] = 1;
        }
        if (i - 3 >= 0) {
            d[i][3] = d[i - 3][1] + d[i - 3][2];
            if (i == 3)
                d[i][3] = 1;
        }
        d[i][1] %= 1000000009;
        d[i][2] %= 1000000009;
        d[i][3] %= 1000000009;
    }

    while (n--) {
        int temp;
        cin >> temp;
        cout << (d[temp][1]+d[temp][2]+d[temp][3])% 1000000009 << "\n";
    }
}

