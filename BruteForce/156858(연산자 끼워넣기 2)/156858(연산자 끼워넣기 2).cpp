// 156858(연산자 끼워넣기 2).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 최대 최소값 페어방식으로 출력하는 함수 정의
pair<int, int> calc(vector<int>& a, int index, int cur, int plus, int minus, int mul, int div) {
    int n = a.size();
    if (index == n)
        return make_pair(cur, cur);

    vector<pair<int, int>> res;
    if (plus > 0) {
        res.push_back(calc(a, index + 1, cur + a[index], plus - 1, minus, mul, div));
    }
    if (minus > 0) {
        res.push_back(calc(a, index + 1, cur - a[index], plus, minus - 1, mul, div));
    }
    if (mul > 0) {
        res.push_back(calc(a, index + 1, cur * a[index], plus, minus, mul - 1, div));
    }
    if (div > 0) {
        res.push_back(calc(a, index + 1, cur / a[index], plus, minus, mul, div - 1));
    }
    auto ans = res[0];
    for (auto p : res) {
        if (ans.first < p.first) {
            ans.first = p.first;
        }
        if (ans.second > p.second) {
            ans.second = p.second;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int plus, minus, mul, div;
    cin >>  plus >> minus >> mul >> div;
    auto p = calc(a, 1, a[0], plus, minus, mul, div);
    cout << p.first << '\n';
    cout << p.second << '\n';
    return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
