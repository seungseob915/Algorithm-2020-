// 1912(연속합).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
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
    vector<int> d(n);   //n에서의 최대 합

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        d[i] = a[i];
    }

    for (int i = 0; i < n; i++) {
        if (i == 0)
            continue;
        if (d[i] < d[i - 1] + a[i])
            d[i] = d[i - 1] + a[i];
        else
            d[i] = a[i];
    }
    
    int ans = *max_element(d.begin(), d.end());
    cout << ans;

    return 0;
}
