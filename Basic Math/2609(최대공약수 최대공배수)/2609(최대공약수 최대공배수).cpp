// 2609(최대공약수 최대공배수).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// https://www.acmicpc.net/problem/2609

#include <iostream>

using namespace std;

int GCD(int, int);

int main(){
    int a, b, result1, result2;
    cin >> a >> b;
    result1 = GCD(a, b);
    result2 = a * b / result1;
    cout << result1<<'\n'<<result2;

    return 0;
}

// 최대공약수(유클리드호제법 이용)
int GCD(int x, int y) { 
    if (y == 0)
        return x;
    else
        return GCD(y, x % y);
}