// 1107(리모콘).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
bool broke[11];


//해결 시작점 채널에 고장난 버튼이 있는지: 있으면 true
int incl_bb(int test) {
	if (test == 0) {
		if (broke[0])
			return 0;
		else
			return 1;
	}

	int len = 0;
	while (test > 0) {
		if (broke[test % 10]) {
			return 0;
		}
		len += 1;
		test /= 10;
		}
	return len;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	fill(broke, broke+11, false);



	//고장난 버튼 입력
	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;
		broke[temp] = true;
	}
	
	int ans = n - 100;
	if (ans < 0)
		ans = -ans;
	

	//채널 생성
	for (int i = 0; i <= 1000000; i++) {
		int temp = i;	// 고장난 버튼 확인 및 채널 누른 갯수 확인
		int cnt = incl_bb(temp);	//+, - 횟수 카운트
								
		if (cnt > 0) {
			int press = temp - n;
			if (press < 0) {
				press = -press;
			}
			if (ans > cnt + press) {
				ans = cnt + press;
			}
		}
	}
	cout << ans;
	return 0;
}
