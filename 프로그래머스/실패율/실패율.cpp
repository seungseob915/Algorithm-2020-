// 실패율.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// cmp함수 정의때문에 틀렸음

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, float>& a, const pair<int, float>& b) {
    // 확률이 같으면 스테이지번호가 작은것부터
    if (a.second > b.second)
        return true;
    else if (a.second == b.second)
        return a.first < b.first;
    else
        return false;
}

vector<int> solution(int N, vector<int> stages) {

    map<int, float> result;
    int total = stages.size();

    // 스테이지 별 현재 명수 확인, 다 깨면 N+1이므로 벡터 크기 1증가
    vector<int> now(N + 2);
    for (int i = 0; i < stages.size(); i++) {
        now[stages[i]] += 1;
    }

    //map을 이용한 key와 확률 매치
    for (int i = 1; i < N + 1; i++) {
        if (total != 0) {
            result[i] = (float)now[i] / (float)total;
            total -= now[i];
        }
        else
            result[i] = 0;
    }

    // 맵을 벡터로 복사(정렬하기 위하여)
    vector<pair<int, float>> temp(result.begin(), result.end());

    //내림차순 정렬
    sort(temp.begin(), temp.end(), cmp);

    // 정답출력
    vector<int> answer;

    for (int i = 0; i < temp.size(); i++) {
        answer.push_back(temp[i].first);
    }

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }

    return answer;
}

int main()
{
    int N;
    vector<int> stages;

    cin >> N;

    int tem;
    cin >> tem;

    for (int i = 0; i < tem; i++) {
        int temp;
        cin >> temp;
        stages.push_back(temp);
    }

    solution(N, stages);
}
