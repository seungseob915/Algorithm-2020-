// [모의 SW 역량테스트] 줄기세포배양.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;


typedef struct Cell {
	int r, c, x, mt, lt, dt, nt;
}C;

struct cmp {
	bool operator()(const C &a, const C &b) {
		if (a.nt == b.nt) {
			if (a.lt != b.lt)
				return a.lt > b.lt;
			else
				return a.x < b.x;
		}
		return a.nt > b.nt;
	}
};


int N, M, K, X, T, Tcnt=1;
C board[800][800] = {};
vector <C> start;
int rx[] = { 0, 0, -1, 1 };
int cy[] = { -1, 1, 0, 0 };

void Init() {
	memset(board, NULL, sizeof(board));
	start.clear();
}

void simulate(int finish) {

	priority_queue < C, vector <C>, cmp> pq;
	// 최초 시작 세포 pq에 삽입
	for (int i = 0; i < start.size(); i++) {
		pq.push(start[i]);
	}

	while (!pq.empty()) {
		C temp = pq.top();
		pq.pop();

		// 현재시간이 K라면
		if (temp.nt == finish + 1)
			break;

		// 활성화 되는 시간이라면
		if (temp.lt + 1 == temp.nt) {
			for (int k = 0; k < 4; k++) {
				C next = { temp.r + rx[k], temp.c + cy[k], temp.x, temp.nt, temp.nt + temp.x, temp.nt + (temp.x * 2), temp.nt + 1 };

				// 이미 있으면 (우선순위 큐로 사전 정렬해놔서 생명력 높은 것부터 들어감
				if (board[next.r][next.c].x > 0 ) {
					continue;
				}

				pq.push(next);
				board[next.r][next.c] = next;
			}
		}

		// 활성화 시간이 아니면 현재 시간만 늘려준다
		else if(temp.lt+1 > temp.nt) {
			temp.nt += 1;
			pq.push(temp);
		}
	}
}

int main()
{
	cin >> T;
	while (T--) {
		Init();

		cin >> N >> M >> K;

		for (int i = 350; i < 350 + N; i++) {
			for (int j = 350; j < 350 + M; j++) {
				int temp_x;
				cin >> temp_x;
				// 최초 세포 저장
				if (temp_x > 0) {
					board[i][j] = { i, j, temp_x, 0, temp_x, temp_x + temp_x, 0 };
					start.push_back(board[i][j]);
				}
			}
		}

		simulate(K);

		int ans = 0;
		
		for (int i = 0; i < 800; i++) {
			for (int j = 0; j < 800; j++) {
				if (board[i][j].dt > K)
					ans++;
			}
		}

		cout << "#" << Tcnt << " " << ans << endl;
		Tcnt++;
	}
}
