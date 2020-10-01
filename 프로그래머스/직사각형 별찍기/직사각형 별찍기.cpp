// 직사각형 별찍기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int main(void) {
    int n,m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cout << "*";
        }
        cout << "\n";
    }
}