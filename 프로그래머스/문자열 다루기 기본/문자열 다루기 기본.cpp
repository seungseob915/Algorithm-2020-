// 문자열 다루기 기본.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>

using namespace std;

bool solution(string s) {
    bool answer = true;

    int length = s.size();

    answer = (length == 4 || length == 6) ? true : false;

    for (int i = 0; i < length; i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            answer = false;
    }
    return answer;
}

int main()
{
 
}