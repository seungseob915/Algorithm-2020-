﻿// 수박수박수박수박수박수.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>

using namespace std;

string solution(int n) {
    string answer = "";

    string s = "수박";
    for (int i = 0; i < n; i++) {
        if (i % 2==0) {
            answer += "수";
        }
        else {
            answer += "박";
        }
    }

    return answer;
}

int main()
{

}

