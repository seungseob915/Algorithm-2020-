// 15988(1, 2, 3 더하기 3).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 메모이제이션 기법은 stack overflow가 발생해서 시간초과가 발생함

#include <iostream>
using namespace std;

int n;
long long int d[1000001];

int main()
{
    cin >> n;
    d[0] = 1;
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    for (int i = 4; i < 1000001; i++) {
        d[i] =(d[i - 3] + d[i - 2] + d[i - 1]) % 1000000009;
        
    }

    while (n--) {
        int temp;
        cin >> temp;
        cout<<d[temp]<<"\n";
    }
}