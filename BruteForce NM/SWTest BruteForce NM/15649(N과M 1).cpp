#include <iostream>
#include <memory.h>
using namespace std;
int a[10];
bool c[10];

void go(int, int, int);

int main() {
	int n, m;

	cin >> n >> m;
	memset(c, false, 10);
	go(0, n, m);
	
	return 0;
}

void go(int index, int n, int m) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
			cout << a[i];
			if (i != m - 1)
				cout << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (c[i] == true)
			continue;
		c[i] = true;
		a[index] = i;
		go(index + 1, n, m);
		c[i] = false;
	}
}
