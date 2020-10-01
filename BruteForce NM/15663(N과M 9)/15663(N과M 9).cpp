// 15663(N과M 5).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <vector<int>> g;

void go(int index, int n, int m, vector <int> a, vector<bool> c, vector<int> d) {
	if (index == m) {
		vector<int> temp;
		for (int i = 0; i < m; i++)
			temp.push_back(d[i]);
		g.push_back(temp);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (c[i] == true)
			continue;
		c[i] = true;
		d[index] = a[i];
		go(index + 1, n, m, a, c, d);
		c[i] = false;
	}
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector <int> a(n);
	vector <bool> c(n);
	vector <int> d(n);


	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a.begin(), a.end());

	go(0, n, m, a, c, d);

	sort(g.begin(), g.end());
	g.erase(unique(g.begin(), g.end()), g.end());


	for (auto &r : g) {
		for (int i = 0; i < m; i++) {
			cout << r[i];
			if (i != m - 1) {
				cout << ' ';
			}
		}
		cout << "\n";
	}
	return 0;
}

