// 정수 제곱근 판별.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <utility>

using namespace std;

long long solution(long long n) {
    long long answer = 0;

    for (long long i = 1; i * i <= n; i++) {
        if (n / i == i && n % i == 0)
            return answer = (i + 1) * (i + 1);
    }
    return answer = -1;
}

int main()
{
    long long n;
    cin >> n;

    cout << solution(n);
}