// 15650(N과M 2).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

int a[10];

void go(int, int, int, int);

int main()
{
    int n, m;
    cin >> n >> m;

    go(0, 1, n, m);

    return 0;
}

void go(int index, int start, int n, int m) {
    if (index == m) {
        for (int i = 0; i < m; i++)
            cout << a[i]<<" ";
        cout << '\n';
        return;
    }

    for (int j = start; j <= n; j++) {
        a[index] = j;
        go(index + 1, j+1, n, m);
        }
}