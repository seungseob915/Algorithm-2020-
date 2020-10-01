// 문자열 내 마음대로 정렬하기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int nn;

bool cmp(string a, string b) {
    if (a[nn] == b[nn]) {
        return a < b;
    }
    else
        return a[nn]<b[nn];
}

vector<string> solution(vector<string> strings, int n) {
    int length = strings.size();
    nn = n;

    sort(strings.begin(), strings.end(), cmp);

    return strings;
}

int main()
{
    vector<string> strings(3);
    int n;

    for (int i = 0; i < 3; i++) {
        string temp;
        cin >> temp;
        strings.push_back(temp);
    }
        
    cin >> n;

    solution(strings, n);
}

