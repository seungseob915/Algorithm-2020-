// 6588(골드바흐의 추측).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// https://www.acmicpc.net/problem/6588
/* 에라토네스의 체를 사용해야 시간초과가 되지않음
#include <iostream>
#define SIZE 1000000
using namespace std;
bool primary(int);


int main()
{
    int n=-1, a = -1, b = -1, diff = 0;

    while (n != 0) {

        cin >> n;

        for (int i = 3; i <= n / 2; i += 2)
            if (primary(i) == true && primary(n - i) == true && n - 2 * i > diff) {
                a = i;
                b = n - i;
                diff = b - a;
            }
        if (a == -1 || b == -1)
            cout << "Goldbach's conjecture is wrong.\n";
        else
            cout << n << "=" << a << "+" << b<<'\n';
    }
}

bool primary(int n) {
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}
*/

#include <iostream>
#define SIZE 1000000
using namespace std;
void eratosthenes();
bool check[SIZE+1];


int main()
{
    cin.sync_with_stdio(false), cin.tie(nullptr);
    int n;
    eratosthenes();

    while (1) {

        cin >> n;
        if (n == 0)
            break;

        bool result = false;

        for (int i = 1; i <= n / 2; i += 2) {
            if (check[i] && check[n - i]) {
                cout << n << " = " << i << " + " << n-i << '\n';
                result = true;
                break;
            }            
        }
        if (!result)
            cout << "Goldbach's conjecture is wrong.\n";
    }
}

//에라토스테네스의 체(true:소수, false: 소수아님)
void eratosthenes() {
    fill(check, check + SIZE + 1, true);
    for (int i = 2; i * i <= SIZE; i++)
        if (check[i] == true)
            for (int j = i * i; j <= SIZE; j += i)
                check[j] = false;
    check[1] = false;
}