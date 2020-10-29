// [9251] LCS.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string>
using namespace std;

string A, B;
int dp[1001][1001] = {};

int go(int a, int b) {
	int ans = 0;
	if (a < 0 || b < 0) return 0;
	if (dp[a][b] != -1) return dp[a][b];
	if (A[a] == B[b]) {
		ans++;
		return dp[a][b]= ans + go(a - 1, b - 1);
	}
	else {
		return dp[a][b] = max(go(a - 1, b), go(a, b - 1));
	}
}

int main()
{
	cin >> A >> B;
	memset(dp, -1, sizeof(dp));
	cout << go(A.size()-1, B.size()-1);
}
