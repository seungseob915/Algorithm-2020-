// [1654] 랜선 자르기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
using namespace std;
int K, N;
long long ans = 0;
long long line[10001] = {};

int main()
{
	cin >> K >> N;

	for (int i = 0; i < K; i++) cin >> line[i];
	
	long long lo = 1;
	long long hi = *max_element(line, line + K);

	while (lo <= hi) {
		long long mid = (lo + hi) / 2;
		long long cnt = 0;

		for (int i = 0; i < K; i++) cnt += (line[i] / mid);

		if (N <= cnt) {
			ans =max(ans, mid);
			lo = mid + 1;
		}
		else {
			hi = mid - 1;
		}
	}
	cout << ans;
}

