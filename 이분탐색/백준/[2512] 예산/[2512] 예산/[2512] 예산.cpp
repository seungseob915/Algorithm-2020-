// [2512] 예산.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
using namespace std;

int N, M, ans=0;
int need[10001] = { 0, };

int main()
{
	cin >> N;
	long long sum = 0;
	for (int i = 1; i <= N; i++) {
		cin >> need[i];
		sum += need[i];
	}
	cin >> M;
	if (M >= sum) ans = *max_element(need+1, need + N + 1);
	else {
		int lo = 1;
		int hi = M;

		while (lo + 1 < hi) {
			int mid = (lo + hi) / 2;

			long long tsum = 0;
			for (int i = 1; i <= N; i++) {
				if (need[i] > mid) tsum += mid;
				else tsum += need[i];
			}

			if (tsum > M) hi = mid;
			else lo = mid;
		}
		ans = lo;
	}
	cout << ans;
}