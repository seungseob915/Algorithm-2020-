// [2343] 기타 레슨.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int N, M, ans=0;
int film[100100] = { 0, };
int total = 0;

bool check(int mid) {
	int sum = 0;
	int cnt = 1;
	for (int i = 0; i < N; i++) {
		if (film[i] > mid) return false;
		sum += film[i];
		if (sum > mid) {
			sum = film[i];
			cnt++;
		}
	}
	return M>=cnt;
}

int main()
{
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		cin >> film[i];
		total += film[i];
	}

	int lo = 1;
	int hi = total;

	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		
		//cnt가 M보다 크면
		if (check(mid)) {
			ans = mid;
			hi = mid - 1;
		}
		//cnt가 M보다 작거나 같으면
		else {
			lo = mid + 1;
		}
	}
	cout << ans;
}
