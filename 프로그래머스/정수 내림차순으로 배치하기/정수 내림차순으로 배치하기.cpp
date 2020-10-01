// 정수 내림차순으로 배치하기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(char& a, char& b) {
    return a > b;
}

long long solution(long long n) {
    long long answer = 0;

    string s = to_string(n);

    sort(s.begin(), s.end(), cmp);

    answer = atol(s.c_str());

    return answer;
}


int main()
{
    long long n;
    cin >> n;

    long long a=solution(n);

    cout << a;
}
