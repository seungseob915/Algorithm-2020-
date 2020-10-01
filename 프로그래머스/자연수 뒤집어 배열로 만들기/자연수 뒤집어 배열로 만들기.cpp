// 자연수 뒤집어 배열로 만들기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include<string>
#include <vector>
using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;

    string s = to_string(n);

    for (int i = s.size()-1; i >= 0; i--) {
        answer.push_back(s[i] - '0');
    }
    return answer;
}

int main()
{
    
}
