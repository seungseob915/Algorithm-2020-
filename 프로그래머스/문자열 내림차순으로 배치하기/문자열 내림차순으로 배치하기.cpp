// 문자열 내림차순으로 배치하기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(char a, char b) {
    return a > b;
}
string solution(string s) {
    string answer = "";
    string temp1 = "";  //소문자
    string temp2 = "";  //대문자

    for (int i = 0; i < s.size(); i++) {
        //소문자면
        if (s[i] >= 'a' && s[i] <= 'z') {
            temp1.push_back(s[i]);
        }
        else
            temp2.push_back(s[i]);
    }

    sort(temp1.begin(), temp1.end(),cmp);
    sort(temp2.begin(), temp2.end(), cmp);

    answer = temp1 + temp2;

    return answer;
}

int main()
{
 
}