// 약수의 합.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;

int solution(int n) {
    int answer = 0;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i * i == n) {
                answer += i;
                continue;
            }
            answer += i;
            answer += (n/i);
        }
    }
    return answer;
}

int main()
{
 
}
