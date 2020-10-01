// 11052(카드 구매하기).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int main()
{
    cin >> n;
    vector <int> num(n + 1);
    vector <int> d(n + 1);  // 최대 비용
    for (int i = 1; i <= n; i++)
        cin >> num[i];

    for(int i=1; i<=n; i++)
        for (int j = 1; j <= i; j++) {
            d[i] = max(d[i], num[j] + d[i - j]);
        }
    cout << d[n] << "\n";
    return 0;
}
