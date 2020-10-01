// [2933] 미네랄.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>

using namespace std;

char board[101][101];
vector<int> stick;
int R, C, N;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first > b.first;
	}
	return a.second < b.second;
}

void remove(int stk_no, int dir) {
	if (dir == 0) {
		for (int i = 1; i <= C; i++) {
			if (board[R-stk_no+1][i] == 'x') {
				board[R - stk_no + 1][i] = '.';
				return;
			}
		}
	}
	else {
		for (int i = C; i >= 1; i--) {
			if (board[R - stk_no + 1][i] == 'x') {
				board[R - stk_no + 1][i] = '.';
				return;
			}
		}
	}
}

int main()
{
	cin >> R >> C;

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> board[i][j];
		}
	}

	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		stick.push_back(temp);
	}
	

	for (int i = 0; i < N; i++) {
		int dir;
		if (i % 2 == 0) {	//왼쪽
			dir = 0;
		}
		else {
			dir = 1;	//오른쪽
		}

		//부시자
		remove(stick[i], dir);

		// 혹시 클러스터가 떨어져 있는게 있는지 확인한다
		bool check[101][101] = {};
		queue <pair<int, int>> q;

		// 맨밑에 있는 미네랄과 연관되어있는지 확인
		for (int j = 1; j <= C; j++) {
			if (board[R][j] == 'x') {
				q.push({ R, j });
				check[R][j] = true;
			}
		}

		while (!q.empty()) {
			pair<int, int> now = q.front();
			q.pop();
			
			for (int j = 0; j < 4; j++) {
				pair<int, int> next = { now.first + dx[j], now.second + dy[j] };

				if (next.first > R || next.first<1 || next.second>C || next.second < 1) {
					continue;
				}
				if (board[next.first][next.second] != 'x') {
					continue;
				}
				if (check[next.first][next.second] == true) {
					continue;
				}
				q.push(next);
				check[next.first][next.second] = true;
			}
		}
		
		//클러스터는 무조건 1개만 떨어지니까, 떠있는놈의 좌표를 일단 다 저장하자 
		vector <pair<int, int>> fly;
		

		for (int k = 1; k <= R; k++) {
			for (int j = 1; j <= C; j++) {
				if (board[k][j] == 'x' && check[k][j] == false) {
					fly.push_back({ k, j });
				}
			}
		}

		vector <pair<int, int>> row_list;

		for (int k = 1; k <= C; k++) {
			for (int j = R; j >= 1; j--) {
				if (board[j][k] == 'x' && check[j][k] == false) {
					row_list.push_back({ j, k });
					break;
				}
			}
		}

		////떠있는 놈이 있다면
		if (fly.size() != 0) {
			int temp_val = 987654321;
			pair<int,int> temp_index;
			for (int j = 0; j < row_list.size(); j++) {	// 하나의 클러스터 중 블록 마다 가장 밑에서 가까운 놈을 찾자
				int diff=-1;
				pair<int, int> nw = row_list[j];

				for (int k = nw.first+1; k <= R; k++) {
					if (board[k][nw.second] == 'x') {
						diff = k - nw.first-1;
						break;
					}
				}

				//땅바닥에 닿았으면
				if (diff == -1) {
					diff = R - nw.first;
				}

				// 거리차 비교하자
				if (diff < temp_val) {
					temp_val = diff;
					temp_index = { nw.first, nw.second };
				}
			}


			//정렬을 해줘야된다.
			sort(fly.begin(), fly.end(), cmp);
			// 최소 거리를 찾았으니 내리자
			for (int j = 0; j < fly.size(); j++) {
				pair<int, int> nw = fly[j];
				board[nw.first + temp_val][nw.second] = 'x';
				board[nw.first][nw.second] = '.';
			}
		}
	}

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << board[i][j];
		}
		cout << endl;
	}

	return 0;
}

