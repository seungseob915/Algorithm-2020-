#include <iostream>
#include <algorithm>
#include <vector>
#include<stack>
#include <queue>
using namespace std;
int dice[10];
int stone[4];

int map[33];
int turn[33];
int score[33];
bool check[35];

int ans = 0;
void dfs(int dep, int sum) {
	if (dep == 10) {
		if (sum > ans)ans = sum;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int prev = stone[i];
		int cur = prev;
		int move = dice[dep];

		if (turn[cur]) {
			cur = turn[cur];
			move--;
		}

		while (move--) {
			cur = map[cur];
		}
		if (cur != 21 && check[cur])continue;

		check[prev] = false;
		check[cur] = true;
		stone[i] = cur;

		dfs(dep + 1, sum + score[cur]);

		stone[i] = prev;
		check[cur] = false;
		check[prev] = true;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 21; i++) {
		map[i] = i + 1;
		score[i] = i * 2;
	}
	for (int i = 22; i < 27; i++)map[i] = i + 1;
	map[21] = 21;
	map[28] = 29; map[29] = 30; map[30] = 25;
	map[31] = 32; map[32] = 25; map[27] = 20;
	turn[5] = 22; turn[10] = 31; turn[15] = 28;
	turn[25] = 26;
	score[22] = 13; score[23] = 16; score[24] = 19;
	score[31] = 22; score[32] = 24; score[28] = 28;
	score[29] = 27; score[30] = 26; score[25] = 25;
	score[26] = 30; score[27] = 35;

	for (int i = 0; i < 10; i++) {
		cin >> dice[i];
	}
	dfs(0, 0);
	cout << ans << "\n";
	return 0;
}
