// [19237] 어른 상어.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

typedef struct Shark {
	int x, y, dir;
	bool dead;
}S;

int N, M, K, time=0;
S s[401];
pair <int, int> chk[21][21];
int sdir[401][5][5];
int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, -1, 1};

int main()
{
	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		for(int j=1; j<=N; j++){
			int temp;
			cin >> temp;

			if (temp >= 1) {
				s[temp] = { i, j, 0, false };
				chk[i][j] = make_pair(temp, K);
				continue;
			}
			chk[i][j] = make_pair(0, 0);	//초기화
		}
	}
	//현재 상어 방향
	for (int i = 1; i <= M; i++) {
		cin >> s[i].dir;
	}
	//상어별 우선방향 받자
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int k = 1; k <= 4; k++) {
				cin >> sdir[i][j][k];
			}
		}
	}

	while (time <= 1000) {

		int board[21][21] = {};

		// 상어 1만 남았다면
		bool finish = true;
		for (int i = 2; i <= M; i++) {
			if (!s[i].dead) {
				finish = false;
				break;
			}
		}
		
		if (finish) break;

		// 상어이동
		for (int i = 1; i <= M; i++) {
			if (s[i].dead) continue;

			bool go = false;
			for (int k = 1; k <= 4; k++) {
				int nx = s[i].x + dx[sdir[i][s[i].dir][k]];
				int ny = s[i].y + dy[sdir[i][s[i].dir][k]];

				if (nx<1 || nx>N || ny<1 || ny>N) continue;
				if (chk[nx][ny].first != 0) continue;

				s[i].x = nx;
				s[i].y = ny;
				s[i].dir = sdir[i][s[i].dir][k];
				go = true;
				break;			
			}

			// 만약 빈칸이 없으면 왔던곳으로 되돌린다
			if (!go) {
				for (int k = 1; k <= 4; k++) {
					int nx = s[i].x + dx[sdir[i][s[i].dir][k]];
					int ny = s[i].y + dy[sdir[i][s[i].dir][k]];

					if (nx<1 || nx>N || ny<1 || ny>N) continue;
					if (chk[nx][ny].first == i) {
						s[i].x = nx;
						s[i].y = ny;
						s[i].dir = sdir[i][s[i].dir][k];
						chk[nx][ny].second = -1;
						break;
					}
				}
			}
		}

		//냄새 설정 및 위치설정(위치설정간 그 칸에 상어가있으면 그친구는 죽인다.(빠른순으로 설정 필수)
		for (int i = 1; i <= M; i++) {
			if (s[i].dead) continue;
			int x = s[i].x;
			int y = s[i].y;

			if (chk[x][y].second>=0 && chk[x][y].first != 0) {
				s[i].dead = true;
				continue;
			}
			chk[x][y].first = i;
			chk[x][y].second = K+1;
		}

		// 냄새 cnt--
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (chk[i][j].first == 0) continue;
				chk[i][j].second--;
				if (chk[i][j].second == 0) chk[i][j].first = 0;
			}
		}
		time++;

		/*for (int i = 1; i <= M; i++) {
			if (s[i].dead) continue;
			board[s[i].x][s[i].y] = i;
		}
		cout << "!#!@#!@#!@#@ Time : "<<time<< " !@##!#!@#!@#!@#" << endl;
		cout << endl;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cout << board[i][j]<<' ';
			}
			cout << endl;
		}
		cout << endl;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cout << chk[i][j].second << ' ';
			}
			cout << endl;
		}
		cout << endl;*/
	}

	if (time == 1001)
		time = -1;

	cout << time;
}
