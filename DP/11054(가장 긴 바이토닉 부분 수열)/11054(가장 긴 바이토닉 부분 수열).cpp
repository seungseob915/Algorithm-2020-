// 11054(가장 긴 바이토닉 부분 수열).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int main()
{
	cin >> n;
	vector <int> a(n + 1);		// 부분 수열 값
	vector <int> d1(n + 1);      // k지점이 중심++인 최대 길이
	vector <int> d2(n + 1);		// k지점이 중심--인 최대 길이

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int t = 1; t <= n; t++) {		//k부터 증가
			d1[t] = 1;
			for (int j = 1; j <= t; j++) {
				if (a[t] > a[j] && d1[t] < d1[j] + 1)
					d1[t] = d1[j] + 1;
			}
	}
	for (int t = n; t >= 1; t--) {		//k부터 감소
			d2[t] = 1;
		for (int j = t+1; j <= n; j++)
			if (a[t] > a[j] && d2[t] < d2[j] + 1)
				d2[t] = d2[j] + 1;
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (ans < d1[i] + d2[i]-1)
			ans = d1[i] + d2[i]-1;
	
	cout << ans;

	return 0;
}
