#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>

using namespace std;

/*
원판 돌리기
원판을 T번 회전시켰을 때, 원판에 적힌 수의 합은?
*/

int N, M, T, ans;
int map[50][50], copyMap[50][50];

void mapCopy() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			copyMap[i][j] = map[i][j];
		}
	}
}

void calculate() {
	int sum = 0, cnt = 0;
	double avg;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) continue;
			sum += map[i][j];
			cnt++;
		}
	}
	avg = (double)sum / cnt;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) continue;
			if (map[i][j] > avg) map[i][j]--;
			else if (map[i][j] < avg) map[i][j]++;
		}
	}
}

void rotation(int i, int k) {
	for (int n = 0; n < k; n++) {
		int tmp = map[i][M - 1];
		for (int j = M - 2; j >= 0; j--) {
			map[i][j + 1] = map[i][j];
		}
		map[i][0] = tmp;
	}
}

void check() {
	int cnt = 0;
	mapCopy();

	// 같은 원판에서 체크 (행 같고, 열 이웃)
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) continue;

			if (map[i][j] == map[i][(j + 1) % M]) {
				if (copyMap[i][j] == 0) {
					copyMap[i][(j + 1) % M] = 0;
					cnt += 1;
				}
				else {
					copyMap[i][j] = 0;
					copyMap[i][(j + 1) % M] = 0;
					cnt += 2;
				}
			}
		}
	}

	// 이웃 원판에서 체크 (열 같고, 행 이웃)
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) continue;

			if (map[i][j] == map[i + 1][j]) {
				if (copyMap[i][j] == 0) {
					copyMap[i + 1][j] = 0;
					cnt += 1;
				}
				else {
					cnt += 2;
					copyMap[i][j] = 0;
					copyMap[i + 1][j] = 0;
				}
			}
		}
	}

	swap(map, copyMap);

	// 인접하면서 수가 같은 것이 없다면, 연산 처리
	if (cnt == 0) calculate();
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> T;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	while (T--) {
		int x, d, k;
		cin >> x >> d >> k;

		// 횟수 교정
		k = k % M;
		if (k == 0) continue;	// 0번 회전은 제자리
		if (d == 1) k = M - k;	// 반시계 방향은 시계방향으로 전환

		// x 배수인 원판을 시계방향으로 k번 회전
		for (int i = 0; i < N; i++) {
			if ((i + 1) % x == 0) {
				rotation(i, k);
			}
		}

		// 인접 체크
		check();
	}

	// 원판에 적힌 수의 합
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			ans += map[i][j];
		}
	}
	cout << ans;
}
