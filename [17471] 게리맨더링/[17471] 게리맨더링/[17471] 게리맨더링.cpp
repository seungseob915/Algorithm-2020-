// [17471] 게리맨더링.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <cmath>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int N, ans = 987654321;
vector <int> list[11];
int popu[11];
int chk[11];	//1 or 2

int check() {
	bool check[11] = {};
	int one = 0;
	int two = 0;
	int total = N;

	// 맨먼저 1인것 처음꺼부터 시작
	for (int i = 1; i <= N; i++) {
		if (check[i]) continue;
		
		if (chk[i] == 1) {
			if (one > 0) continue;
			queue <int> q;
			q.push(i);
			check[i] = true;
			one++;
			total--;

			while (!q.empty()) {
				int n = q.front();
				q.pop();

				for (int k = 0; k < list[n].size(); k++) {
					if (chk[list[n][k]] != 1) continue;
					if (check[list[n][k]]) continue;
					q.push(list[n][k]);
					check[list[n][k]] = true;
					total--;
					one++;
				}
			}
		}

		if (chk[i] == 2) {
			if (two > 0) continue;
			queue <int> q;
			q.push(i);
			check[i] = true;
			total--;
			two++;

			while (!q.empty()) {
				int n = q.front();
				q.pop();

				for (int k = 0; k < list[n].size(); k++) {
					if (chk[list[n][k]] != 2) continue;
					if (check[list[n][k]]) continue;
					q.push(list[n][k]);
					check[list[n][k]] = true;
					total--;
					two++;
				}
			}
		}
	}

	if (total != 0) {
		return -1;
	}

	if (one == 0 || two == 0) {
		return -1;
	}

	int o_sum = 0;
	int t_sum = 0;
	
	for (int i = 1; i <= N; i++) {
		if (chk[i] == 1) {
			o_sum += popu[i];
		}
		else {
			t_sum += popu[i];
		}
	}
	return abs(o_sum - t_sum);
}

void dfs(int depth) {
	if (depth == N+1) {
		int temp = check();
		if (temp != -1)
			ans = min(ans, temp);

		return;
	}

	for (int i = 1; i <= 2; i++) {
		chk[depth] = i;
		dfs(depth + 1);
		chk[depth] = 0;
	}
}

int main()
{
	cin >> N;

	//인구 입력
	for (int i = 1; i <= N; i++)
		cin >> popu[i];
	
	// 인접리스트 연결
	for (int i = 1; i <= N; i++) {
		int no;
		cin >> no;

		while (no--) {
			int temp;
			cin >> temp;
			list[i].push_back(temp);
		}
	}
		
	// 선거구 조합
	dfs(1);

	if (ans == 987654321)
		ans = -1;

	cout << ans;
}
