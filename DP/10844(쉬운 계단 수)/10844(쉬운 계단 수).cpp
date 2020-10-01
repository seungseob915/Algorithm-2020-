// 10844(쉬운 계단 수).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int n;
int arr[101][10];

int main()
{
    cin >> n;

    for (int i = 1; i < 10; i++)
        arr[1][i] = 1;

    for(int i=2; i<=n; i++)
        for (int j = 0; j <= 9; j++) {
            if (j - 1 >= 0)
                arr[i][j] += arr[i - 1][j - 1];
            if (j + 1 <= 9)
                arr[i][j] += arr[i - 1][j + 1];
            arr[i][j] %= 1000000000;
        }
    long long int ans = 0;
    for (int i = 0; i <= 9; i++)
        ans += arr[n][i];
    ans %= 1000000000;

    cout << ans << "\n";
    return 0;

}
