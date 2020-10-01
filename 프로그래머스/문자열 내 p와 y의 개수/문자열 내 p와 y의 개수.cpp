// 문자열 내 p와 y의 개수.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int length = s.size();
    int p = 0;
    int y = 0;
    int gap = 'A' - 'a';
    
    for (int i = 0; i < length; i++) {
        //소문자로 변환
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] -= gap;

        if (s[i] == 'p')
            p++;
        else if (s[i] == 'y')
            y++;
    }

    if (p != y)
        answer = false;
    else
        answer = true;
    return answer;
}

int main()
{
}