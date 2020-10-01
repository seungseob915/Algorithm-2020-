// [3190] 뱀.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

typedef struct Snake {
	int hx, hy, tail, l, dir;
}S;

int N, K, L, time=0;
int board[101][101];
vector<pair<int, char>> rot;
S s = { 1,1,0,1,1 };

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };


void simulate() {
	queue<pair<int, int>> q;
	board[s.hx][s.hy] = time;	//처음 시작
	int no = 0;
	q.push({ s.hx, s.hy });

	while (1) {
		pair<int, int> now=q.front();
		q.pop();
		pair<int, int> next = {now.first+dx[s.dir], now.second+dy[s.dir]};
		time++;

		if (next.first<1 || next.first >N || next.second<1 || next.second>N)	break;
		if (board[next.first][next.second]>=s.tail) break;
		
		//방향 바꿔주고 싶당
		if ((no<rot.size()) && (time == rot[no].first)) {
			if (rot[no].second == 'L') {
				s.dir -= 1;
				if (s.dir == -1)
					s.dir = 3;
			}
			else {
				s.dir += 1;
				if (s.dir == 4)
					s.dir = 0;
			}
			no++;
		}
		if (board[next.first][next.second] == -2) {
			q.push({ next.first, next.second });
			board[next.first][next.second] = time;
			continue;
		}
		// 빈칸일때
		s.tail++;	//꼬리 위치 변경
		q.push({ next.first, next.second });
		board[next.first][next.second] = time;
	}
}

int main()
{
	memset(board, -1, sizeof(board));	//-1: 공백, -2: 사과

	cin >> N >> K;

	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		board[x][y] = -2;	// 사과
;	}


	cin >> L;
	for (int i = 0; i < L; i++) {
		int x;
		char y;
		cin >> x >> y;
		rot.push_back({ x, y });	//뱀 변경
	}

	simulate();

	cout << time;
	
	return 0;
}
