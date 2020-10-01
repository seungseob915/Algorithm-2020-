// 모의고사.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int a[5] = { 1,2,3,4,5 };
int b[8] = { 2,1,2,3,2,4,2,5 };
int c[10] = { 3,3,1,1,2,2,4,4,5,5 };

int ac=0;
int bc=0;
int cc=0;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
    if (a.second > b.second)
        return true;
    else if (a.second == b.second)
        return a.first < b.first;
    else
        return false;
}
  

vector<int> solution(vector<int> answers) {

    int sol_size = answers.size();
    vector<int> answer;

    for (int i = 0; i < sol_size; i++) {
        if (answers[i] == a[i%5])
            ac++;
        if (answers[i] == b[i%8])
            bc++;
        if (answers[i] == c[i%10])
            cc++;
    }

    //동점인경우 (제일 첫번째거, 2번째꺼 같은지 비교, 3번째꺼까지 같은지 비교)
    map <int, int> m;
    m[1] = ac;
    m[2] = bc;
    m[3] = cc;

    vector<pair<int, int>> temp(m.begin(), m.end());
    sort(temp.begin(), temp.end(), cmp);

    for (int i = 0; i < 3; i++) {
        if (temp[i].second == temp[0].second) {
            answer.push_back(temp[i].first);
        }
    }
    return answer;
}

int main()
{
 
}
