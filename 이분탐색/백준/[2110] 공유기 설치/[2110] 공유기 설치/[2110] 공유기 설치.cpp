// [2110] 공유기 설치.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
using namespace std;

int N, C, ans=0;
int map[200001] = {  };

int main()
{
	cin >> N >> C;

	for (int i = 0; i < N; i++) cin >> map[i];
	sort(map, map + N);
	int lo = 1;
	int hi = map[N-1];

	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		int now = map[0];
		int cnt = 1;

		for (int i = 1; i < N; i++) {
			if (now + mid > map[i]) continue;
			cnt++;
			now = map[i];
		}

		if (C <= cnt) {
			ans = mid;
			lo = mid + 1;
		}
		else {
			hi = mid - 1;
		}
	}
	cout << ans;
}