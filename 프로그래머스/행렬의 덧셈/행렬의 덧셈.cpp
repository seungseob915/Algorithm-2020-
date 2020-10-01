// 행렬의 덧셈.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;

    int length_1 = arr1.size();
    int length_2 = arr1[0].size();

    for (int i = 0; i < length_1; i++) {
        vector<int> temp;
        for (int j = 0; j < length_2; j++) {
            temp.push_back(arr1[i][j] + arr2[i][j]);
        }
        answer.push_back(temp); 
    }
    return answer;
}

int main()
{
}
