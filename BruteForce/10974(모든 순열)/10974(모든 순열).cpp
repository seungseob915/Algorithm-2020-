// 10974(모든 순열).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//int factorial(int);

int main() {
    int n, in, count;
    cin >> n;
    vector<int> vec(n);

   // count = factorial(n);

    for (int i = 0; i < n; i++) {
        vec[i] = i + 1;
        cout << vec[i] << " ";
    }
    cout << "\n";

    while (next_permutation(vec.begin(), vec.end())) {
        for (int j = 0; j < n; j++)
            cout << vec[j] << " ";
        cout << "\n";
    }
}
 /*   for (int i = 1; i < count; i++) {
        next_permutation(vec.begin(), vec.end());
        for (int j = 0; j < n; j++)
            cout << vec[j]<<" ";
        cout << "\n";
    }
    return 0;
}

int factorial(int n) {
    if (n == 1)
        return 1;

    return n * factorial(n - 1);
}
*/