// 가운데 글자 가져오기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>

using namespace std;

string solution(string s) {
    string answer = "";

    int length = s.size();
    int point = length / 2;
    
    //짝수라면
    if (length % 2 == 0) {
        answer.push_back(s[point - 1]);
        answer.push_back(s[point]);
    }
    //홀수라면
    else {
        answer = s[point];
    }

    return answer;
}

int main()
{
    cout << solution;
}
