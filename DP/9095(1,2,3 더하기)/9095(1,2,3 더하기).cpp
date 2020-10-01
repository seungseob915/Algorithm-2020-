// 9095(1,2,3 더하기).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int n;
int d[12];
int go(int);

int main()
{   
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        cout << go(temp) << "\n";
    }    
}

int go(int x) {
    if (x == 1)
        return 1;
    if (x == 2)
        return 2;
    if (x == 3)
        return 4;

    if (d[x] > 0)       //메모이제이션
        return d[x];
    
    return d[x] = go(x - 3) + go(x - 2) + go(x - 1);
}
