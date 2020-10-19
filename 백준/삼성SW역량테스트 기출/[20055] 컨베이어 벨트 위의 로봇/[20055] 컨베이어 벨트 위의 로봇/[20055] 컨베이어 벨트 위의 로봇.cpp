// [20055] 컨베이어 벨트 위의 로봇.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int N, K;
int board[201][2] = { 0, };

int main()
{
	cin >> N >> K;

	for (int i = 1; i <= 2 * N; i++) {
		cin >> board[i][0];
	}

	int time = 0;

	while (1) {

		int temp = board[2 * N][0];

		for (int i = 2 * N; i >= 2; i--) {
			if (i == N + 1 || i==N) {
				board[i][0] = board[i - 1][0];
				board[i][1] = 0;
				continue;
			}
			board[i][0] = board[i - 1][0];
			board[i][1] = board[i - 1][1];
		}
		board[1][0] = temp;
		board[1][1] = 0;

		for (int i = N-1; i >= 1; i--) {
			if (board[i][1] == 0) continue;
			if (board[i + 1][1] == 1 || board[i + 1][0] == 0) continue;
			
			board[i + 1][0]--;
			board[i + 1][1] = board[i][1];
			board[i][1] = 0;

			if (i + 1 == N) {
				board[N][1] = 0;
			}
		}

		if (board[1][0] > 0 && board[1][1] == 0) {
			board[1][0]--;
			board[1][1]=1;
		}
		int cmp = 0;
		for (int i = 1; i <= 2 * N; i++) {
			if (board[i][0] == 0) cmp++;
		}

		time++;

		if (cmp >= K) break;
	}

	cout << time;
}