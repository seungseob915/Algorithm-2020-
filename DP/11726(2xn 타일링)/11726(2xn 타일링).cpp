// 11726(2xn 타일링).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int d[1001];
int n;
int go(int);

int main()
{
    cin >> n;

    int ans = go(n);
   // ans %= 10007;

    cout << ans;
}

int go(int x) {
    if (x == 0 || x==1)
        return 1;
    if (d[x] > 0)       //메모이제이션
        return d[x];
    
    d[x] = go(x - 2) + go(x - 1);
    return d[x]%10007;
}
