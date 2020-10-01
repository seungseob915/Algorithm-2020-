// 같은 숫자는 싫어.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    int length = arr.size();
    int now=arr[0];
    answer.push_back(arr[0]);

    for (int i = 1; i < length; i++) {
        //연속되면
        if (now == arr[i]) {
            continue;
        }
        //연속안되면
        else {
            now = arr[i];
            answer.push_back(arr[i]);
        }
    }

    return answer;
}

int main()
{
    
}
