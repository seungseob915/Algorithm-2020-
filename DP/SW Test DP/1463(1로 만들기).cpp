// SW Test DP.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int d[1000001];

int calc(int x) {
    if (x == 1)
        return 0;
    if (d[x] > 0)       //메모이제이션
        return d[x];
    d[x] = calc(x - 1) + 1;

    if (x % 3 == 0) {
        int temp = calc(x / 3) + 1;
        if (d[x] > temp)
            d[x] = temp;
    }
    if (x % 2 == 0) {
        int temp = calc(x / 2) + 1;
        if (d[x] > temp)
            d[x] = temp;
    }
    return d[x];
}

int main()
{
    int n;

    scanf("%d", &n);

    printf("%d\n", calc(n));

    return 0;
}


