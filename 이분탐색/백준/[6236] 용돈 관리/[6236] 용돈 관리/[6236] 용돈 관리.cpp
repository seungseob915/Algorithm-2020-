// [6236] 용돈 관리.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

int N, M, ans = 0;
int money[100001] = { 0, };

int main()
{
	cin >> N >> M;
	int hi = 0;
	for (int i = 1; i <= N; i++) {
		cin >> money[i];
		hi += money[i];
	}

	int lo = *max_element(money + 1, money + 1 + N);

	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		int cnt = 0;
		int now = 0;
		for (int i = 1; i <= N; i++) {
			if (now - money[i] < 0) {
				now = mid - money[i];
				cnt++;
				continue;
			}
			now -= money[i];
		}

		if (cnt > M) {
			lo = mid+1;
		}
		else {
			ans = mid;
			hi = mid-1;
		}
	}
	cout << ans;
}
