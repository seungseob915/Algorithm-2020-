// 두 정수 사이의 합.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;


long long solution(int a, int b) {
    long long answer = 0;

    if (a == b) {
        return a;
    }

    if (a < b) {
        for (int i = a; i <= b; i++) {
            answer += i;
        }
    }
    else {
        for (int i = b; i <= a; i++) {
            answer += i;
        }
    }
    return answer;
}


int main()
{
    int a, b;

    cin >> a >> b;
    long long ans = solution(a, b);
    cout << ans;
}
