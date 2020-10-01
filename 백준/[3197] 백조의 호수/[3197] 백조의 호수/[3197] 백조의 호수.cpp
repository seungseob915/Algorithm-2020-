// [3197] 백조의 호수.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// check true 처리 안해줘서 메모리초과, 백조의 위치 물로 포함안해서 틀림

#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

typedef struct Swan {
	int r, c;
}swan;

char board[1501][1501];
bool check[1501][1501];

int R, C, water=0;

swan s[2];
int dr[] = { 0,0,-1,1 };
int dc[] = { -1,1,0,0 };

queue <swan> meltq;
queue <swan> meltq2;
queue<swan> meetq;
queue<swan> meetq2;

bool meet() {
	bool ret = false;

	while (meetq.size()) {
		swan now = meetq.front();
		if (s[1].r == now.r && s[1].c == now.c)
			return true;
		meetq.pop();

		for (int i = 0; i < 4; i++) {
			swan next = { now.r + dr[i], now.c + dc[i] };

			if (next.r<1 || next.r>R || next.c<1 || next.c>C)
				continue;
			if (check[next.r][next.c] == true)
				continue;
			if (board[next.r][next.c] == 'X') {
				meetq2.push(next);
				check[next.r][next.c] = true;
				continue;
			}
			meetq.push(next);
			check[next.r][next.c] = true;
		}
	}
	return ret;
}


void melt() {
	// 얼음을 녹이자
	while (meltq.size()) {
		swan now = meltq.front();
		meltq.pop();

		for (int i = 0; i < 4; i++) {
			swan next = { now.r + dr[i], now.c + dc[i] };

			if (next.r<1 || next.r>R || next.c<1 || next.c>C)
				continue;
			if (board[next.r][next.c] != 'X')
				continue;
			board[next.r][next.c] = '.';
			meltq2.push({ next.r, next.c });
		}
	}
}

int main()
{
	cin >> R >> C;

	int s_cnt = 0;

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'L') {
				s[s_cnt++] = { i, j };
				board[i][j] = '.';
				meltq.push({ i, j });
				if (s_cnt == 1) {
					meetq.push({ i, j });
					check[i][j] = true;
				}
			}
			else if (board[i][j] == '.') {
				meltq.push({ i, j });
				water++;
			}
		}
	}

	
	int day = 0;

	while (1) {
		// 백조가 만나면
		if (meet())
			break;

		melt();

		meetq = meetq2;
		meltq = meltq2;
		while (!meetq2.empty())meetq2.pop();
		while (!meltq2.empty())meltq2.pop();
		day++;
	}

	cout << day;
}

