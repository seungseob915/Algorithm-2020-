// [2748] 피보나치 수 2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <memory.h>
using namespace std;

int N;
long long dp[91] = {};
long long fibo(int n) {
	if (n == 1 || n==2) return 1;
	if (dp[n] != -1) return dp[n];
	dp[n]=fibo(n - 1) + fibo(n - 2); 
	return dp[n];
}

int main()
{
	cin >> N;
	memset(dp, -1, sizeof(dp));
	long long ans=fibo(N);
	cout << ans;
}
