// [16235] 나무 재테크.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, bool> a, pair<int, bool> b) {
	return a.first < b.first;
}

int N, M, K;
vector<pair<int, bool> > board[11][11] = {};
int a[11][11][2] = {};	//0: 매년 보충량 1: 현재량
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = { 0,1,1,1,0,-1,-1,-1 };

void spsm() {
	for (int i = 1; i <= N; i++) {
		for(int j=1; j <= N; j++) {
			int total = a[i][j][1];
			int plus = 0;
			sort(board[i][j].begin(), board[i][j].end());

			for (int k = 0; k < board[i][j].size(); k++) {
				if (total < board[i][j][k].first) {
					board[i][j][k].second = true;
					plus += int(board[i][j][k].first / 2);
					continue;
				}
				total -= board[i][j][k].first;
				board[i][j][k].first++;
			}

			vector<pair<int, bool> > temp;
			for (int k = 0; k < board[i][j].size(); k++) {
				if (board[i][j][k].second) continue;
				temp.push_back(make_pair(board[i][j][k].first, false));
			}
			board[i][j] = temp;
			a[i][j][1] = total;
			a[i][j][1] += plus;
		}
	}
}

void fall() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < board[i][j].size(); k++) {
				if ((board[i][j][k].first % 5) == 0) {
					//번식하자
					for (int d = 0; d < 8; d++) {
						int nx = i + dx[d];
						int ny = j + dy[d];

						if (nx<1 || nx> N || ny<1 || ny>N) continue;
						board[nx][ny].push_back(make_pair(1, false));
					}
				}
			}
		}
	}
}

void winter() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			a[i][j][1] += a[i][j][0];
		}
	}
}

int main()
{
	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> a[i][j][0];	// 보충되는 양분
			a[i][j][1] = 5;
		}
	}

	// 첫 나무 넣어주기
	for(int i=1; i<=M; i++){
		int x, y, z;
		cin >> x >> y >> z;
		board[x][y].push_back(make_pair(z, false));
	}
	int cnt = 0;

	while (K--) {
		spsm();
		cnt++;

		/*cout << "@#!@#@$@$@$@$$ Time  : " << cnt << " @$$@$@$@$@$@$" << endl;
		cout << "Spring Summer" << endl;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cout << board[i][j].size() << ' ';
			}
			cout << endl;
		}
		cout << endl;*/


		fall();
		/*cout << "Fall" << endl;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cout << board[i][j].size() << ' ';
			}
			cout << endl;
		}
		cout << endl;*/

		winter();
		/*cout << "Winter 양분" << endl;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cout << a[i][j][1] << ' ';
			}
			cout << endl;
		}
		cout << endl;*/

		//cnt++;

	}


	int ans = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			ans += board[i][j].size();
		}
	}

	cout << ans;
}
