// [2805] 나무 자르기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int N;
long long M;
long long tree[1000001];

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++) cin >> tree[i];

    //최대 높이 범위 설정 후 이분탐색
    int lo = 0;
    int hi = 1000000000;

    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;

        long long sum = 0;
        for (int i = 1; i <= N; i++) {
            if (tree[i] > mid) sum += (tree[i] - mid);
        }

        if (sum >= M) {
            lo = mid;
        }
        else {
            hi = mid;
        }
    }
    cout << lo;
}
