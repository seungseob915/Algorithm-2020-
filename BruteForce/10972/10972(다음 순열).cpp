// 10972.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, num, prov = 0;
    cin >> n;

    vector<int> vec(n);

    for (int i = 0; i < n; i++) {
        cin >> num;
        vec[i] = num;
    }

    next_permutation(vec.begin(), vec.end());

     for (int i = 0; i < n; i++)
         if (vec[i] == i + 1)
             prov += 1;

    if (prov == n) {
         cout << -1;
         return 0;
     }

     for (int i = 0; i < n; i++) {
         cout << vec[i]<<' ';        
     }
    
     return 0;
}
