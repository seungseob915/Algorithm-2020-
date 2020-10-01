// 10819(차이를 최대로).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Hap(vector<int> &vec);

int main()
{
    int n, compare, temp;
    cin >> n;
    vector<int> vec(n);

    for (int i = 0; i < n; i++)
        cin >> vec[i];

    sort(vec.begin(), vec.end());

    compare=Hap(vec);

    while (next_permutation(vec.begin(), vec.end())) {
        temp = Hap(vec);
        compare = max(compare, temp);
    }
    cout << compare;
    return 0;    
}

int Hap(vector<int> &vec) {
    int sum = 0;
    for (int i = 0; i < vec.size()-1; i++)
        sum += abs(vec[i] - vec[i + 1]);
    return sum;
}
