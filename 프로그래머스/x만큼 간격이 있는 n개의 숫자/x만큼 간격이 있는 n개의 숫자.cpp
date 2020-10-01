// x만큼 간격이 있는 n개의 숫자.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;

    long long temp=x;
    for (int i = 1; i <= n; i++) {
        answer.push_back(temp);
        temp += x;
    }

    return answer;
}

int main()
{
}