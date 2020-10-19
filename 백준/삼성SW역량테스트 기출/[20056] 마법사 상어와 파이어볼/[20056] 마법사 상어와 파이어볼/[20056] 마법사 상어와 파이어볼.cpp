// [20056] 마법사 상어와 파이어볼.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;

typedef struct Planet {
	int x, y, m, s, d;
}P;

int N, M, K, ans=0;
vector<P> p;
vector<P> tp;
int chk[51][51] = { 0, };
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main()
{
	cin >> N >> M >> K;

	if (M == 0) {
		cout << ans;
		return 0;
	}

	for (int i = 0; i < M; i++) {
		int x, y, m, s, d;
		cin >> x >> y >> m >> s >> d;
		p.push_back({ x, y, m, s, d });
		chk[x][y]++;
	}
	while (K--) {
		for (int i = 0; i < p.size(); i++) {
			if (p[i].m == 0) continue;
			int x = p[i].x;
			int y = p[i].y;
			int s = p[i].s;
			int d = p[i].d;

			int nx = x + (dx[d] * s);
			int ny = y + (dy[d] * s);

			if (nx < 1) {
				nx = (N - (-nx % N));
			}
			if (nx > N) {
				nx %= N;
				if (nx == 0)
					nx = N;
			}
			if (ny < 1) {
				ny = (N - (-ny % N));
			}
			if (ny > N) {
				ny %= N;
				if (ny == 0)
					ny = N;
			}
			p[i].x = nx;
			p[i].y = ny;
			chk[nx][ny]++;
			chk[x][y]--;
		}
		tp.clear();

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (chk[i][j] >= 2) {
					int tcnt = 0;
					int ssum = 0;
					int msum = 0;
					int tdir = -1;	//3이면 짝수 혹은 홀수만, 4이면 섞여있음
					int dtype = 3;
					for (int k = 0; k < p.size(); k++) {
						if (p[k].m == 0) continue;
						if (p[k].x == i && p[k].y == j) {
							tcnt++;
							if (tdir == -1) {
								tdir = p[k].d % 2;
							}
							else {
								if (tdir != (p[k].d % 2)) {
									dtype = 4;
								}
							}
							ssum += p[k].s;
							msum += p[k].m;

							p[k].m = 0;
							chk[i][j]--;
						}
					}

					int fs = int(ssum / tcnt);
					int fm = int(msum / 5);

					if (fm == 0)
						continue;
					if (dtype == 3) {
						for (int kk = 0; kk <= 6; kk+=2) {
							P ttp = { i, j, fm, fs, kk };
							tp.push_back(ttp);
							chk[i][j]++;
						}
					}
					else {
						for (int kk = 1; kk <= 7; kk += 2) {
							P ttp = { i, j, fm, fs, kk };
							tp.push_back(ttp);
							chk[i][j]++;
						}
					}
				}
			}
		}

		for (int i = 0; i < p.size(); i++) {
			if (p[i].m == 0) continue;
			tp.push_back(p[i]);
		}

		p.clear();
		p = tp;
		
	}

	for (int i = 0; i < p.size(); i++) {
		ans += p[i].m;
	}
	cout << ans;
}
