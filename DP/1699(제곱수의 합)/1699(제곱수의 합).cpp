// 1699(제곱수의 합).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;


int main()
{
    cin>>n;
    vector<int> d(n+1);       //제곱합의 최솟값

    for (int i = 1; i <= n; i++) {
        d[i] = i;       //초기값: 본인 자신
        for (int j = 1; j * j <= i; j++) {
            if(d[i]>d[i-j*j]+1)
                d[i] = d[i-j*j]+1;       //초기값: 본인 자신
        }
    }
    cout << d[n];
}