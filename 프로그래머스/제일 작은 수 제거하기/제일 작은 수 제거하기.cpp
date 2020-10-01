// 제일 작은 수 제거하기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;

    int length = arr.size();
    
    if (length == 1) {
        answer.push_back(-1);
        return answer;
    }

    int min = *min_element(arr.begin(), arr.end());

    for (int i = 0; i < length; i++) {
        if (arr[i] == min)
            continue;
        
        answer.push_back(arr[i]);
    }
    return answer;
}

int main()
{
}
