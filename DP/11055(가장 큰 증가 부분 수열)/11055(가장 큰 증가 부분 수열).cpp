// 11055(가장 큰 증가 부분 수열).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int main()
{
    cin >> n;

    vector <int> a(n+1);
    vector <int> d(n+1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++) {
        d[i] = a[i];
        for (int j = 1; j < i; j++) {
            if (a[i] > a[j] && d[i] < d[j] + a[i])
                d[i] = d[j] + a[i];
        }
    }

    int ans = *max_element(d.begin(), d.end());

    cout << ans;
    return 0;        
}

