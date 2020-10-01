// 13458(시험 감독).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

long long int n, b, c, m[1000001], s[1000001], ans[1000001];


int main()
{
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cin >> b >> c;  // 주: b명 감시, 부: c명 감시
    
    for (int i = 0; i < n; i++) {
        m[i] = 1;
        s[i] = 0;
        a[i]=a[i]-b;
        if (a[i]<= 0) {
            ans[i] = m[i] + s[i];
            continue;
        }
        else {
            long long int temp1 = a[i] / c;
            long long int temp2 = a[i] % c;
            if (temp2 > 0)
                temp1 += 1;
            s[i] = temp1;
            ans[i] = m[i] + s[i];
        }    
    }
    long long int final=0;
    for (int i = 0; i < n; i++)
        final += ans[i];

    cout << final << '\n';

    return 0;
}
