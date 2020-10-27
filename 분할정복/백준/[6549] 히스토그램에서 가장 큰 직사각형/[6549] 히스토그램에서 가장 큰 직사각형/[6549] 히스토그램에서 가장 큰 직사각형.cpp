// [6549] 히스토그램.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
long long ans = -987654321;
vector<long long> flr;

void Init() {
	flr.clear();
	ans = -9876543210;
}

void check(int left, int right) {
	if (left == right) {
		ans = max(ans, flr[left]);
		return;
	}

	int mid = (left + right) / 2;
	check(left, mid);
	check(mid + 1, right);

	ans = max(ans, flr[mid]);
	int tl = mid;
	int tr = mid;
	long long th = flr[mid];
	while (tl > left || tr < right) {
		if (tr < right && (tl == left || flr[tr + 1] > flr[tl - 1])) {
			tr++;
			th = min(th, flr[tr]);
		}
		else {
			tl--;
			th = min(th, flr[tl]);
		}
		ans = max(ans, (tr - tl + 1) * th);
	}
}

int main()
{
	while (1) {
		Init();
		cin >> N;
		if (N == 0) break;
		for (int i = 0; i < N; i++) {
			int temp;
			cin >> temp;
			flr.push_back(temp);
		}

		check(0, N - 1);

		cout << ans<<endl;
	}
}
