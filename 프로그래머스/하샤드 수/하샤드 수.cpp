// 하샤드 수.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool solution(int x) {
    bool answer = true;

    string s = to_string(x);
    
    int div = 0;

    for (int i = 0; i < s.size(); i++) {
        div+=s[i]-'0';
    }

    if (x % div == 0)
        return answer=true;
    
    return answer = false;
}

int main()
{
}