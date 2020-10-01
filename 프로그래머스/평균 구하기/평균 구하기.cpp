// 평균 구하기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;

    int length = arr.size();

    for (int i = 0; i < length; i++) {
        answer += arr[i];
    }

    return answer/length;
}

int main()
{
}
