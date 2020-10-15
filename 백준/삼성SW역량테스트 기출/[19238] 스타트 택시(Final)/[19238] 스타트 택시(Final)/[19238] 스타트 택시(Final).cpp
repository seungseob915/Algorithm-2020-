// [19238] 스타트 택시(Final).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;

typedef struct Taxi {
	int x, y, fuel;
}T;
typedef struct Client {
	int x, y, dtx, dty, finish;
}C;
typedef struct FindClient {
	int dis, idx, x, y;
}FC;

int N, M, F;
int board[21][21] = {};
T t = {};
C c[401] = {};
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1, 0,0 };

struct cmp {
	bool operator()(FC a, FC b) {
		if (a.dis == b.dis) {
			if (a.x == b.x) {
				return a.y > b.y;
			}
			else {
				return a.x > b.x;
			}
		}
		return a.dis > b.dis;
	}
};

int main()
{
	cin >> N >> M >> F;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) {
				board[i][j] = -1;
			}
		}
	}

	cin >> t.x >> t.y;
	t.fuel = F;

	for (int i = 1; i <= M; i++) {
		cin >> c[i].x >> c[i].y >> c[i].dtx >> c[i].dty;
		board[c[i].x][c[i].y] = i;
		c[i].finish = false;
	}
	int cnt = 0;

	//운행시작
	while (1) {
		cnt++;
		//다끝났는지 확인
		bool finish = true;
		for (int i = 1; i <= M; i++) {
			if (!c[i].finish) {
				finish = false;
				break;
			}
		}
		if (finish) break;

		int x = t.x;
		int y = t.y;
		int nf = t.fuel;
		//승객 탑승지 초기화
		int nx = t.x;
		int ny = t.y;
		int nidx = board[x][y];
		int dis = 0;

		bool go = true;
		//거리 0이아니면 지금부터 탐색해서 nx, ny를 찾자
		if (board[x][y] <= 0) {
			priority_queue<FC, vector<FC>, cmp> pq;
			queue<pair<int, int> > q;

			int chk[21][21] = {};
			memset(chk, -1, sizeof(chk));
			q.push(make_pair(x, y));
			chk[x][y] = 0;

			while (!q.empty()) {
				int nowx = q.front().first;
				int nowy = q.front().second;
				q.pop();

				for (int k = 0; k < 4; k++) {
					int nxx = nowx + dx[k];
					int nxy = nowy + dy[k];

					if (nxx<1 || nxx> N || nxy<1 || nxy>N) continue;
					if (chk[nxx][nxy] != -1) continue;
					if (board[nxx][nxy] == -1) continue;
					//0일때랑 승객일때가 남는다.
					if (board[nxx][nxy] > 0) 
						pq.push({ chk[nowx][nowy] + 1, board[nxx][nxy], nxx, nxy });
					q.push(make_pair(nxx, nxy));
					chk[nxx][nxy] = chk[nowx][nowy] + 1;
				}
			}
			if (!pq.empty()) {
				int next_idx = pq.top().idx;
				nx = c[next_idx].x;
				ny = c[next_idx].y;
				nidx = next_idx;
				dis = pq.top().dis;
			}
			else {
				go = false;
			}
		}
	/*	cout << "@#@!#!@#!#@#@!#@!#@!#@!#@!#!@# " << cnt << " 번째 시작 !@#@!#!@#@!#!@#!@#@!#!@#!" << endl;
		cout << "승객 탑승위치 : " << nx << " " << ny << " " << endl;
		cout << "현재연료 : " << t.fuel << endl;*/

		if (!go) {
			t.fuel = -1;
			break;
		}

		//연료 거리만큼 -해주자
		t.fuel -= dis;
		if (t.fuel <= 0) {
			t.fuel = -1;
			break;
		}
		t.x = nx;
		t.y = ny;
		board[nx][ny] = 0;	//손님 태웠으니까

		/*cout << "소모 연료: " << dis << endl;
		cout << "소모 후 연료: " << t.fuel << endl;*/

		// 승객의 도착지로 출발해봅시다
		int dsx = c[nidx].dtx;
		int dsy = c[nidx].dty;
		/*cout << "승객 하차위치 : " << nx << " " << ny << " " << endl;*/


		//bfs로 최소거리 구하자
		int dist2 = -1;
		queue<pair<int, int> > q;
		int chk[21][21] = {};
		memset(chk, -1, sizeof(chk));

		q.push(make_pair(t.x, t.y));
		chk[t.x][t.y] = 0;
		bool findd = false;
		while (!q.empty()) {
			int nowx = q.front().first;
			int nowy = q.front().second;
			q.pop();

			for (int k = 0; k < 4; k++) {
				int nxx = nowx + dx[k];
				int nxy = nowy + dy[k];

				if (nxx<1 || nxx> N || nxy<1 || nxy>N) continue;
				if (chk[nxx][nxy] != -1)continue;
				if (board[nxx][nxy] == -1) continue;
				q.push(make_pair(nxx, nxy));
				chk[nxx][nxy] = chk[nowx][nowy] + 1;
				if (nxx == dsx && nxy == dsy) {
					dist2 = chk[nxx][nxy];
					findd = true;
					break;
				}
			}
			if (findd) break;
		}

		//갈수없다
		if (dist2 == -1) {
			t.fuel = -1;
			break;
		}

		t.fuel -= dist2;
		/*cout << "소모 연료: " << dist2 << endl;
		cout << "소모 후 연료: " << t.fuel << endl;*/
		if (t.fuel < 0) {
			t.fuel = -1;
			break;
		}

		t.fuel += 2 * dist2;
		t.x = dsx;
		t.y = dsy;
		c[nidx].finish = true;
	/*	cout << "충전 후 연료: " << t.fuel << endl;
		cout << endl;*/
	}
	cout << t.fuel;
}
