// [1074] Z.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int N, fx, fy;
bool flag = false;
int ans = 0;
int now = 0;	// 0부터 시작한다

void simulate(int x, int y, int nsize) {
	if (flag) return;
	if (nsize == 1) {
		now++;
		if (x == fx && y == fy) {
			ans = now;
			flag = true;
		}
		return;
	}
	int ns= nsize / 2;
	int plus = ns * ns;
	if (fx >= x && fx < x + ns && fy >= y && fy < y + ns) {
		simulate(x, y, ns);
	}
	else if (fx >= x && fx < x + ns && fy >= y + ns && fy < y + 2 * ns) {
		now += plus;
		simulate(x, y + ns, ns);
	}
	else if (fx >= x + ns && fx < x + 2 * ns && fy >= y && fy < y + ns) {
		now += 2 * plus;
		simulate(x + ns, y, ns);
	}
	else if (fx >= x + ns && fx < x + 2 * ns && fy >= y + ns && fy < y + 2 * ns) {
		now += 3 * plus;
		simulate(x + ns, y + ns, ns);
	}
}

int main()
{
	cin >> N;
	cin >> fx >> fy;
	int nsize = pow(2, N);

	simulate(0, 0, nsize);
	cout << ans-1;
}
