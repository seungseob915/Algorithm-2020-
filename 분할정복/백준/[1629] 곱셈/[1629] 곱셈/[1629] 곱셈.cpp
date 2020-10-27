// [1629] 곱셈.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int A, B, C;
long long ans = 1;

long long cal(int a, int b) {
	if (b == 0) return 1;
	if (b == 1) return a%C;
	long long temp;
	//짝수
	if (b % 2 == 0) {
		temp= cal(a, b/2);
		return ((temp%C) * (temp%C)) % C;
	}
	//홀수
	else {
		temp = cal(a, b - 1);
		return ((a % C) * (temp%C)) % C;
	}
}

int main()
{
	cin >> A >> B >> C;
	ans=cal(A, B);
	cout << ans % C;
}