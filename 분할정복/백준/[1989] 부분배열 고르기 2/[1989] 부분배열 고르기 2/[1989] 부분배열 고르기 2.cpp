// [1989] 부분배열 고르기 2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
using namespace std;

long long N, ans = -987654321;
int s = 1, e = 1;
long long arr[100001] = { 0, };

void cal(long long start, long long end) {
	if (start == end) {
		long long temp = arr[start] * arr[start];
		if (ans < temp) {
			ans = temp;
			s = start;
			e = start;
		}
		return;
	}
	long long mid = (start + end) / 2;

	cal(start, mid);
	cal(mid + 1, end);

	long long temp = arr[mid] * arr[mid];
	if (ans < temp) {
		ans = temp;
		s = mid;
		e = mid;
	}
	long long ts = mid;
	long long te = mid;
	long long ta = arr[mid];

	long long t = ta;	// x축값을 계속저장
	while (start < ts || te < end) {
		if (te < end && (start == ts || arr[ts - 1] < arr[te + 1])) {
			te++;
			ta = min(ta, arr[te]);
			t += arr[te];
		}
		else {
			ts--;
			ta = min(ta, arr[ts]);
			t += arr[ts];
		}
		long long tans = ta * t;
		if (ans < tans) {
			ans = tans;
			s = ts;
			e = te;
		}
	}
}

int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++) cin >> arr[i];

	cal(1, N);

	cout << ans << endl << s << ' ' << e;
}
