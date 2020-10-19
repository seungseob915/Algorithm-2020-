// [17825] 주사위 윷놀이(Final).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Horse {
	int now;
	bool finish;
}H;

int ans = 0;
int order[11] = {0, };	
int board[33][2];	//0:원래 score / 1: 몇명 있는지
H h[5] = {};	//21가면 finish=true

void dfs(int depth, int score) {
	if (depth == 10) {
		ans = max(ans, score);
		return;
	}

	int t_board[33] = { 0, };
	H t_h[5] = {};
	for (int i = 0; i <= 32; i++) {
		t_board[i] = board[i][1];
	}
	for (int i = 1; i <= 4; i++) {
		t_h[i] = h[i];
	}

	//말 4개
	for (int i = 1; i <= 4; i++) {
		if (h[i].finish) continue;

		int now = h[i].now;
		//몇칸가는지?
		int go = order[depth + 1];
		int next=go+now;

		if (now == 5) {
			next = 22;
			next+= go - 1;

			if (next > 24) {
				next = 30 + next - 25;
			}
			if (next > 32) {
				next = 20 + next - 33;
				if (next >= 21) {
					next = 21;
				}
			}
		}
		else if (now == 10) {
			next = 25;
			next += go - 1;

			if (next > 26) {
				next = 30 + next - 27;
			}
			if (next > 32) {
				next = 20 + next - 33;
				if (next >= 21) {
					next = 21;
				}
			}
		}
		else if (now == 15) {
			next = 27;
			next += go - 1;

			if (next > 32) {
				next = 20 + next - 33;
				if (next >= 21) {
					next = 21;
				}
			}
		}
		else if (now >= 22 && now <= 24) {
			next = now;
			next += go;

			if (next > 24) {
				next = 30 + next - 25;
			}
			if (next > 32) {
				next = 20 + next - 33;
				if (next >= 21) {
					next = 21;
				}
			}
		}
		else if (now >= 25 && now <= 26) {
			next = now;
			next += go;

			if (next > 26) {
				next = 30 + next - 27;
			}
			if (next > 32) {
				next = 20 + next - 33;
				if (next >= 21) {
					next = 21;
				}
			}
		}
		else if (now >= 27 && now <= 32) {
			next = now;
			next += go;

			if (next > 32) {
				next = 20 + next - 33;
				if (next >= 21) {
					next = 21;
				}
			}
		}
		else{
			next = go + now;
			if (next >= 21) {
				next = 21;
			}
		}

		// 도착한 놈은 끝내준다
		if (next == 21) h[i].finish = true;
		//next에 다른 말이있을때 안된다
		if (next != 21 && board[next][1] != 0) 	continue;

		board[h[i].now][1]--;
		h[i].now = next;
		board[next][1]++;

		dfs(depth + 1, score + board[next][0]);

		for (int i = 0; i <= 32; i++) {
			board[i][1] = t_board[i];
		}
		for (int i = 1; i <= 4; i++) {
			h[i] = t_h[i];
		}
	}
}

int main()
{
	//명령 주입
	for (int i = 1; i <= 10; i++) {
		cin >> order[i];
	}

	//말위치 초기화
	for (int i = 1; i <= 4; i++) {
		h[i].now = 0;
		h[i].finish = false;
	}

	//말판 초기화
	for (int i = 0; i <= 20; i++) {
		board[i][0] = 2 * i;
	}
	board[0][1] = 4;
	board[21][0] = 0;	board[22][0] = 13;	board[23][0] = 16;
	board[24][0] = 19;	board[25][0] = 22;	board[26][0] = 24;
	board[27][0] = 28;	board[28][0] = 27;	board[29][0] = 26;
	board[30][0] = 25;	board[31][0] = 30;	board[32][0] = 35;

	dfs(0, 0);
	cout << ans;
}
