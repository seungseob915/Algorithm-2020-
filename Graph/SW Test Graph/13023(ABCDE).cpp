#include <iostream>
#include <vector>
using namespace std;
vector <int> graph[2000];
bool check[2000];
int ans = 0;
void dfs(int, int);

int main() {
	int n, m, cnt=0;
	cin >> n>>m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x>>y;
		graph[x].emplace_back(y);
		graph[y].emplace_back(x);
	}
	for (int i = 0; i < n; i++) {
		dfs(i, 0);
		check[i] = false;
		if (ans == 1)
			break;
	}
	cout << ans << endl;
	return 0;
}

void dfs(int node, int depth) {
	check[node] = true;
	if (depth == 4) {
		ans = 1;
		return;
	}
	for (int i = 0; i < graph[node].size(); i++) {
		int y = graph[node][i];
		if (check[y] == false) {
			check[y] = true;
			dfs(y, depth + 1);
			check[y] = false;
		}
	}
}
