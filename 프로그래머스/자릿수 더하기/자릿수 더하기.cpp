// 자릿수 더하기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
using namespace std;

int solution(int n)
{
    int answer = 0;

    string s = to_string(n);

    cout << s;
    for (int i = 0; i < s.size(); i++) {
        answer += s[i] - '0';
    }

    return answer;
}

int main()
{

}
