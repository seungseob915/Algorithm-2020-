// 서울에서 김서방 찾기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include<string>
#include <vector>
using namespace std;

string solution(vector<string> seoul) {
    string answer = "김서방은 ";

    int length = seoul.size();
    int locate;

    for (int i = 0; i < length; i++) {
        if (seoul[i] == "Kim") {
            answer += to_string(i);
            answer+="에 있다";
            return answer;
        }
    }
}

int main()
{
 
}