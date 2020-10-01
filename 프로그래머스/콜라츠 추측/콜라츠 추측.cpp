// 콜라츠 추측.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    long long temp = num;
    int cnt = 0;
    
    while (temp!=1) {

        //짝수면
        if (temp % 2 == 0) {
            temp /= 2;
        }

        //홀수면
        else {
            temp *= 3;
            temp++;
        }
        cnt++;
    }

    if (cnt >= 500)
        return -1;

    return cnt;
}

int main()
{
}