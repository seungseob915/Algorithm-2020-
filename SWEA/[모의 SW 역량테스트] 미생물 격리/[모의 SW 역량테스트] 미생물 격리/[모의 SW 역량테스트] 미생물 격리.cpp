// [모의 SW 역량테스트] 미생물 격리.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

typedef struct Virus {
	int x, y, size, dir;
}V;

int T, Tcnt=1, N, M, K;
vector <int> check[101][101];
vector<V> virus;

int r[] = { -1,0,1,0 };	//상좌하우  (+2)%4하면 방향 전환됨
int c[] = { 0,-1,0,1 };


void move() {
	memset(check, NULL,sizeof(check));

	//k개의 군집을 옮기자
	for (int i = 0; i < K; i++) {
		//size==0이면 죽거나 합쳐진거
		if (virus[i].size == 0)
			continue;

		int nextx = virus[i].x + r[virus[i].dir];
		int nexty = virus[i].y + c[virus[i].dir];

		//다음칸이 테두리이면 size를 감소시켜주고 방향을 바꿔준다
		if (nextx < 1 || nextx > N - 2 || nexty< 1 || nexty > N - 2) {
			virus[i].size = virus[i].size / 2;
			virus[i].dir = (virus[i].dir + 2) % 4;
		}

		virus[i].x = nextx;
		virus[i].y = nexty;

		//해당위치 check배열에 바이러스 번호 넣어줌
		check[nextx][nexty].push_back(i);
	}

	// 1~K개의 군집을 다 옮겼으면 check배열을 확인해서 합쳐야할 군집 확인
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			//2개이상 들어있다면 합쳐줘야지
			if (check[i][j].size() > 1) {
				int max_idx = check[i][j][0];
				int max_sz = virus[check[i][j][0]].size;
				for (int k = 0; k < check[i][j].size(); k++) {
					if (max_sz < virus[check[i][j][k]].size) {
						max_sz = virus[check[i][j][k]].size;
						max_idx = check[i][j][k];
					}
				}
				//최대 군집에 바이러스 저장하고 나머지 군집은 size 0처리
				for (int k = 0; k < check[i][j].size(); k++) {
					if (check[i][j][k]!=max_idx) {
						virus[max_idx].size+=virus[check[i][j][k]].size;
						virus[check[i][j][k]].size = 0;
					}
				}
			}
		}
	}
}

int main()
{
	cin >> T;

	while (T--) {
		cin >> N >> M >> K;
		virus.resize(K);

		for (int i = 0; i < K; i++) {
			int tx, ty, ts, tdir;
			cin >> tx >> ty >> ts >> tdir;
			if (tdir == 2)tdir = 3;
			else if (tdir == 3)tdir = 2;
			virus[i] = { tx, ty, ts, tdir - 1 };
		}

		for (int i = 1; i <= M; i++) {
			move();
		}

		int total = 0;

		for (int i = 0; i < K; i++) {
			total += virus[i].size;
		}

		cout << "#" << Tcnt << " " << total << endl;

		Tcnt++;

	}
}
