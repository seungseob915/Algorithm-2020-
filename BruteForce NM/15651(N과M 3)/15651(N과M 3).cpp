// 15651(N과M 3).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int a[10];

void go(int, int, int);

int main()
{
	int n, m;
	cin >> n >> m;
	go(0, n, m);
	return 0;
}

void go(int index, int n, int m) {
	if (index == m) {
		for (int i = 0; i < m; i++)
			cout << a[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		a[index] = i;
		go(index + 1, n, m);
	}
}
