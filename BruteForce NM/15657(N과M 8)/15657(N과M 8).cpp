// 15657(N과M 8).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void go(int index, int start, int n, int m, vector <int> a, vector<int> d) {
	if (index == m) {
		for (int i = 0; i < m; i++)
			cout << d[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = start; i < n; i++) {
		d[index] = a[i];
		go(index + 1, i, n, m, a, d);
	}
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector <int> a(n);
	vector <int> d(n);


	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a.begin(), a.end());

	go(0, 0, n, m, a, d);


}

