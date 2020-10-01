// SW TEST BruteForce.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

int main()
{
    int ie, is, im, e = 1, s = 1, m = 1, year = 1;
    cin >> ie >> is >> im;

    while (true) {
        if (ie == e && is == s && im == m) 
            break;
        
        e++;
        s++;
        m++;

        if (e == 16)
            e = 1;
        if (s == 29)
            s = 1;
        if (m == 20)
            m = 1;
        
        year++;
    }
    cout << year;
}

