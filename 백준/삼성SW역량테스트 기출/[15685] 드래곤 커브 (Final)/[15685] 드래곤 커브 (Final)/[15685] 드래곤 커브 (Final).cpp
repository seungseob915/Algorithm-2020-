// [15685] 드래곤 커브 (Final).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> dir;
bool board[101][101] = { false, };
int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };

void simulate(int x, int y, int d, int g) {
	int sx = x;
	int sy = y;

	board[sx][sy] = true;
	dir.push_back(d);

	for (int i = 1; i <= g; i++) {
		int vs = dir.size();

		vector<int> temp;
		temp = dir;
		for (int j = vs - 1; j >= 0; j--) {
			temp.push_back((dir[j] + 1) % 4);
		}
		dir = temp;
	}

	for (int i = 0; i < dir.size(); i++) {
		sx = sx + dx[dir[i]];
		sy = sy + dy[dir[i]];
		if (sx < 0 || sx> 100 || sy < 0 || sy>100) continue;
		board[sx][sy] = true;
	}
	
	dir.clear();
}

int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int y, x, d, g;
		cin >> y >> x >> d >> g;

		simulate(x, y, d, g);
	}

	int ans = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (board[i][j] == true && board[i + 1][j] == true && board[i][j + 1] == true && board[i + 1][j + 1] == true) {
				ans++;
			}
		}
	}

	cout << ans;
}
