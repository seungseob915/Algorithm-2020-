// [모의 SW 역량테스트] 탈주범 검거.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;

int T, n, m, mr, mc, l, t;
int board[51][51] = {};
bool route[51][51][4] = {};     //길의 4면을 표현

void Init() {
	n = 0, m = 0, mr = 0; mc = 0, l = 0;
	memset(board, 0, sizeof(board));
	memset(board, NULL, sizeof(board));
}

int simulate() {
	
	t = 1;
	//time==l될때까지 돌리면 된다

	int check[51][51];

	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			check[i][j] = 0;
		}
	}

	queue <pair<int, int>> q;
	
	//맨홀 입구 큐 삽입
	q.push(make_pair(mr, mc));
	check[mr][mc] = t;

	while (!q.empty()) {
		pair<int, int> now = q.front();
		int nowx = now.first;
		int nowy = now.second;

		//cout << nowx << endl;
		q.pop();

		// 다음 항목이랑 비교
		for (int i = 0; i < 4; i++) {
			if (route[nowx][nowy][i]) {
				//0부터
				if (i == 0) {
					int nextx = nowx - 1;
					int nexty = nowy;

					if (nextx < 0) {
						continue;
					}
					if (!route[nextx][nexty][2]) {
						continue;
					}
					if (check[nextx][nexty] > 0) {
						continue;
					}
					q.push(make_pair(nextx, nexty));
					check[nextx][nexty] = check[nowx][nowy]+1;
				}

				//1
				else if (i == 1) {
					int nextx = nowx;
					int nexty = nowy+1;

					if (nexty>m-1) {
						continue;
					}
					if (!route[nextx][nexty][3]) {
						continue;
					}
					if (check[nextx][nexty] > 0) {
						continue;
					}
					q.push(make_pair(nextx, nexty));
					check[nextx][nexty] = check[nowx][nowy] + 1;
				}

				//2
				else if (i == 2) {
					int nextx = nowx + 1;
					int nexty = nowy;

				
					if (nextx > n-1) {
						continue;
					}
					if (!route[nextx][nexty][0]) {
						continue;
					}
					if (check[nextx][nexty] > 0) {
						continue;
					}
					q.push(make_pair(nextx, nexty));
					check[nextx][nexty] = check[nowx][nowy] + 1;
				}

				//3
				else if (i == 3) {
					int nextx = nowx;
					int nexty = nowy - 1;

					if (nexty < 0) {
						continue;
					}
					if (!route[nextx][nexty][1]) {
						continue;
					}
					if (check[nextx][nexty] > 0) {
						continue;
					}
					q.push(make_pair(nextx, nexty));
					check[nextx][nexty] = check[nowx][nowy] + 1;
				}
			}
		}

	}

	int ret = 0;

	//숨을수 있는 최대공간 탐색
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (check[i][j] > 0 && check[i][j] <=l) {
				ret++;
			}
		}
	}
	return ret;
}


int main()
{
	cin >> T;
	int Tcnt = 1;

	while (T--) {
		Init();
		cin >> n >> m >> mr >> mc >> l;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				for (int k = 0; k < 4; k++) {
					route[i][j][k] = false;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> board[i][j];
				if (board[i][j] == 1) {			//+
					for (int k = 0; k < 4; k++) {
						route[i][j][k] = true;
					}
				}
				else if (board[i][j] == 2) {
					route[i][j][0] = true, route[i][j][2] = true;
				}
				else if (board[i][j] == 3) {
					route[i][j][1] = true, route[i][j][3] = true;
				}
				else if (board[i][j] == 4) {
					route[i][j][0] = true, route[i][j][1] = true;
				}
				else if (board[i][j] == 5) {
					route[i][j][1] = true, route[i][j][2] = true;
				}
				else if (board[i][j] == 6) {
					route[i][j][2] = true, route[i][j][3] = true;
				}
				else if (board[i][j] == 7) {
					route[i][j][0] = true, route[i][j][3] = true;
				}
			}
		}

		int ans = simulate();

		cout << "#"<<Tcnt<<" "<<ans<<endl;
		Tcnt++;
	}
}
