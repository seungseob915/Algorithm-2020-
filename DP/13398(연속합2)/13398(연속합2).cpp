// 13398(연속합2).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 좌 우를 나눠서 풀이

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int main()
{
	cin >> n;

	vector<int> a(n);
	vector<int> d1(n);
	vector<int> d2(n);

	for (int i = 0; i < n; i++) 
		cin >> a[i];
			
		for (int i = 0; i < n; i++) {
			d1[i] = a[i];
			if (i == 0)
				continue;
			if (d1[i] < d1[i - 1] + a[i])
				d1[i] = d1[i - 1] + a[i];
		}
		for (int i = n-1 ; i > 0; i--) {
			d2[i] = a[i];
			if (i == n - 1)
				continue;
			if (d2[i] < d2[i + 1] + a[i])
				d2[i] = d2[i + 1] + a[i];
		}
	int ans = d1[0];
	for (int i = 1; i < n; i++)
		if (ans < d1[i])
			ans = d1[i];

	for (int i = 1; i < n - 1; i++)
		if (ans < d1[i - 1] + d2[i + 1])
			ans = d1[i - 1] + d2[i + 1];

	cout << ans;
	
	return 0;
}