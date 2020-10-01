// 11722(가장 긴 감소하는 부분 수열).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int main()
{
    cin >> n;
    vector<int> a(n);   //배열
    vector<int> d(n);   //길이 계산

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++) {
        d[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[i] < a[j] && d[i] < d[j] + 1)
                d[i] = d[j] + 1;
        }
    }
    int ans = *max_element(d.begin(), d.end());
    cout << ans;

    return 0;
}
