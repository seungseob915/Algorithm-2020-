// 16194(카드 구매하기 2).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <int> num(n + 1);
    vector <int> d(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        d[i] = 1000 * 10000;
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            d[i] = min(d[i], d[i - j] + num[j]);

    cout << d[n] << "\n";

    return 0;
}