// 이상한 문자 만들기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
using namespace std;

string solution(string s) {
    string answer = "";
    int cnt = 1;
    int gap = 'a' - 'A';

    for (int i = 0; i < s.size(); i++) {
        //공백이면
        if (s[i] == ' ') {
            answer.append(" ");
            cnt=1;
            continue;
        }

        //홀수이면
        if (cnt % 2 != 0) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                answer += s[i];
            }
            else
                answer += s[i] - gap;
        }
        //짝수이면
        else {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                answer += s[i]+gap;
            }
            else
                answer += s[i];
        }
        cnt++;
    }
    return answer;
}

int main()
{
    
}

