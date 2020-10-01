// 1934(최소공배수).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

int GCD(int, int);
int lcm[1001], gcd[1001];

int main()
{
    int T, A, B;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> A >> B;
        gcd[i] = GCD(A, B);
        lcm[i] = A * B / gcd[i];
    }

    for (int i = 0; i < T; i++)
        cout << lcm[i]<<"\n";

}

int GCD(int x, int y) {
    if (y == 0)
        return x;
    else
        return GCD(y, x % y);
}
