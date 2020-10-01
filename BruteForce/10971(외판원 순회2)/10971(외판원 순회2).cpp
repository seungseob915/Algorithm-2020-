// 10971(외판원 순회2).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

int factorial(int);

int main()
{
	int n;
}

int factorial(int n) {
	if (n == 1)
		return 1;
	return n * factorial(n - 1);
}
