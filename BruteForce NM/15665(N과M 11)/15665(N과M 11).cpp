// 15665(N과M 11).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> g;
void go(int index, int n, int m, vector <int> a, vector<int> d) {
	if (index == m) {
		vector <int> temp;
		for (int i = 0; i < m; i++)
			temp.push_back(d[i]);
		g.push_back(temp);
		return;
	}

	for (int i = 0; i < n; i++) {
		d[index] = a[i];
		go(index + 1, n, m, a, d);
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

	go(0, n, m, a, d);

	sort(g.begin(), g.end());
	g.erase(unique(g.begin(), g.end()), g.end());

	for (auto& f : g) {
		for (int i = 0; i < m; i++) {
			cout << f[i] << " ";
		}
		cout << "\n";
	}
	return 0;

}

