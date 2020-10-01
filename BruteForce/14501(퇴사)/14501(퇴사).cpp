#include <iostream>
#include <vector>

using namespace std;

int n, result=0;
vector<int> t;
vector<int> p;

void cal(int, int);

int main() {

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int temp1 = 0, temp2 = 0;
		cin >> temp1 >> temp2;
		t.emplace_back(temp1);
		p.emplace_back(temp2);
	}
	
	cal(0, 0);

	cout << result;
}

void cal(int day, int totalpay) {
	if (day > n)
		return;
	if (day == n) {
		if (totalpay > result)
			result = totalpay;
		return;
	}

	cal(day + 1, totalpay);
	cal(day + t[day], totalpay + p[day]);
}