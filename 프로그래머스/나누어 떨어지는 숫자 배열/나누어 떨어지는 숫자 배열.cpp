// 나누어 떨어지는 숫자 배열.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % divisor == 0) {
            answer.push_back(arr[i]);
        }
    }
    if (answer.empty()) {
        answer.push_back(-1);
    }
    sort(answer.begin(), answer.end());
    return answer;
}

int main()
{

}
