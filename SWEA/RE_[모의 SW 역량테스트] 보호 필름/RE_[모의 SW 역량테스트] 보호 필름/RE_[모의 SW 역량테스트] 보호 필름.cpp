// RE_[모의 SW 역량테스트] 보호 필름.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>

using namespace std;

int D, W, K, T, Tcnt = 1;
int board[14][21];

bool check() {
	for (int i = 1; i <= W; i++) {
		bool nflag = false;
		for (int j = 1; j <= D - K; j++) {
			bool nnflag = true;
			for (int k = j; k < j + K; k++) {
				if (board[k][i] != board[j][i]) {
					nnflag = false;
					break;
				}
			}
			if (nnflag) {
				nflag = true;
				break;
			}
		}
		if (!nflag)
			return false;
	}
	return true;
}

int main()
{
	cin >> D >> W >> K;

	for (int i = 1; i <= D; i++) {
		for (int j = 1; j <= W; j++) {
			cin >> board[i][j];
		}
	}

	cout << check();
}
