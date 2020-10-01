// 핸드폰 번호 가리기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>

using namespace std;

string solution(string phone_number) {

    int length = phone_number.size()-1;

    int cnt = 0;
    
    while (cnt++) {
        if (cnt == length-2)
            return phone_number;
        phone_number[cnt - 1] = '*';
    }
}


int main()
{
}
