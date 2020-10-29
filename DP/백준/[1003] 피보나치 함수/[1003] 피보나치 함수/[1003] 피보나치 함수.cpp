// [1003] 피보나치 함수.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <memory.h>
using namespace std;

int N;
long long ans = 0;
long long dp[41] = {};
long long z[41] = {};
long long o[41] = {};
long long zcnt = 0, ocnt=0;

long long fibo(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	if (dp[n] != -1) {
		return dp[n];
	}
	dp[n] = fibo(n - 1) + fibo(n - 2);
	z[n] = z[n - 1] + z[n - 2];
	o[n] = o[n - 1] + o[n - 2];
	return dp[n];
}

int main()
{
	int C;
	cin >> C;

	while (C--) {
		cin >> N;
		memset(dp, -1, sizeof(dp));
		z[0] = 1;
		z[1] = 0;
		z[2] = 1;
		o[0] = 0;
		o[1] = 1;
		o[2] = 1;

		ans = fibo(N);
		cout << z[N] << ' ' << o[N] << endl;
	}
}
