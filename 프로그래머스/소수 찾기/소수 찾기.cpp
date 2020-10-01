// 소수 찾기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
/*

#include <iostream>

using namespace std;

bool isSosu(int c) {
    bool sosu = true;
    //숫자 n이 소수인지 판별
    for (int i = 2; i * i <= c; i++) {
        if (c % i == 0) {
            sosu = false;
            break;
        }
    }
    return sosu;
}

int solution(int n) {
    int answer = 0;

    for (int i = 2; i <= n; i++) {
        bool sosu = isSosu(i);
        if (sosu)
            answer++;
    }
    return answer;
}

int main()
{
 
}

*/


// 소수 찾기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;


int solution(int n) {
    int answer = 0;

    vector <bool> s(n+1, true);

    for (int i = 2; i * i <= n; i++) {
        if (s[i] == true) {
            for (int j = i * i; j <= n; j += i) {
                s[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (s[i] == true) {
            answer++;
        }
    }
    return answer;
}

int main()
{
    int r=solution(10);
    cout << r;
}