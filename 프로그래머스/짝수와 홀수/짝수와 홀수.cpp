// 짝수와 홀수.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>

using namespace std;

string solution(int num) {
    string answer = "";

    if (num % 2 == 0)
        return answer += "Even";

    else
        return answer += "Odd";
}

int main()
{
}
