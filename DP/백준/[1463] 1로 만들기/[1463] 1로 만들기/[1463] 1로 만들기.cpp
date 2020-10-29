// [1463] 1로 만들기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
using namespace std;

int num[1000001] = {};
int n;

int dp(int no) {
	if (no == 1) return 0;
	if (num[no] != -1) return num[no];

	int result = dp(no - 1) + 1;
	if (no % 3 == 0) return result=min(result, dp(no / 3) + 1);
	if (no % 2 == 0) return result=min(result, dp(no / 2) + 1);
	num[no] = result;
	return result;
}

int main()
{
	cin >> n;
	fill(num, num + 1000001, -1);
	cout<<dp(n);
}
