// 파이프 옮기기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

//방향 →↘↓
int x[] = {0,1,1};
int y[] = {1,1,0};

int map[17][17];
int check[17][17];
int cnt = 0;

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	int n_cnt = 0;
	tuple <int, int, int> now;
	queue < tuple <int, int, int >> q;

	q.push(make_tuple(1, 2, 0));

	while (!q.empty()) {
		now = q.front();
		q.pop();

		for (int i = 0; i < 3; i++) {
			
			//방향에 따른 케이스 처리를 해주어야합니다...
			if (get<2>(now) == 0 && i==2) {
					continue;
			}
			if (get<2>(now) == 2 && i == 0) {
					continue;
			}

			tuple <int, int, int> next = make_tuple(get<0>(now) + x[i], get<1>(now) + y[i], i);
		
			if (i == 1) {
				if (map[get<0>(next)][get<1>(next)] == 1 || map[get<0>(next) - 1][get<1>(next)] == 1 || map[get<0>(next)][get<1>(next) - 1] == 1)
					continue;
			}

			//예외처리(범위)
			if (get<0>(next) < 1 || get<0>(next) > n || get<1>(next) < 1 || get<1>(next) > n)
				continue;
			if (map[get<0>(next)][get<1>(next)] == 1)
				continue;
			
			if (get<0>(next) == n && get<1>(next) == n) {
				n_cnt++;
				continue;
			}
			q.push(next);
		}
	}
	cout << n_cnt;
}