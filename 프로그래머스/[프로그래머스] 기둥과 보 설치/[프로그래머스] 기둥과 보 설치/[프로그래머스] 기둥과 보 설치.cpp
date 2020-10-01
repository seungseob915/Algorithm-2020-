// [프로그래머스] 기둥과 보 설치.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

int board[101][101];
int N;


typedef struct order {
	int x, y, a, b;
}o;

void build_gd(o temp) {
	//바닥위인지?
	if (N - temp.y == N) {
		board[N - temp.y][temp.x] = 0;
	}
	// 다른 기둥 위인지?
	else if (board[N - temp.y + 1][temp.x] == 0) {
		board[N - temp.y][temp.x] = 0;
	}

	// 보위 한쪽 끝부분 위인지? (오버플로우 애초에 보를 설치할 수 없음 다시한번 확인하자)
	else if (temp.x - 1 >= 0 && board[N - temp.y][temp.x - 1] == 1) {
		board[N - temp.y][temp.x] = 0;
	}
}

void build_bo(o temp) {
	// 보는 바닥에 설치 불가능하다
	if (N - temp.y == N) {
		return;
	}

	//양쪽 끝부분이 다른보와 연결되어있는지?
	if (temp.x - 1 >= 0 && temp.x + 1 <= N) {
		if (board[N - temp.y][temp.x - 1] == 1 && board[N - temp.y][temp.x + 1] == 1) {
			board[N - temp.y][temp.x] = 1;
			return;
		}
	}

	// 한쪽 끝이 기둥위인지? (범위설정 중요할듯)
	if (temp.x + 1 <= N) {
		if (board[N - temp.y + 1][temp.x] == 0 || board[N - temp.y + 1][temp.x + 1] == 0) {
			board[N - temp.y][temp.x] = 1;
		}
	}

	else {
		if (board[N - temp.y + 1][temp.x] == 0) {
			board[N - temp.y][temp.x] = 1;
		}
	}
}

void remove(o temp) {
	board[N - temp.y][temp.x] = -1;
}

bool check() {
	bool ret = true;

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			//기둥이라면
			if (board[i][j] == 0) {
				//바닥위인지?
				if (i == N) {
					continue;
				}
				// 다른 기둥 위인지?
				else if (board[i + 1][j] == 0) {
					continue;
				}

				// 보위 한쪽 끝부분 위인지? (오버플로우 애초에 보를 설치할 수 없음 다시한번 확인하자)
				else if (j - 1 >= 0 && board[i][j - 1] == 1) {
					continue;
				}
				return false;
			}

			//보라면
			if (board[i][j] == 1) {
				// 보는 바닥에 설치 불가능하다
				if (i == N) {
					return false;
				}

				//양쪽 끝부분이 다른보와 연결되어있는지?
				if (j - 1 >= 0 && j + 1 <= N) {
					if (board[i][j - 1] == 1 && board[i][j + 1] == 1) {
						continue;
					}
				}

				// 한쪽 끝이 기둥위인지? (범위설정 중요할듯)
				if (j + 1 <= N) {
					if (board[i + 1][j] == 0 || board[i + 1][j + 1] == 0) {
						continue;
					}
				}

				else {
					if (board[i + 1][j] == 0) {
						continue;
					}
				}
				return false;
			}
		}
	}
}


vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	//보드를 -1로 초기화시키자
	memset(board, -1, sizeof(board));

	N = n;

	//정답을 저장하자
	vector<vector<int>> answer;

	// 개수만큼 실행해보자
	for (int i = 0; i < N; i++) {
		o temp = { build_frame[i][0], build_frame[i][1], build_frame[i][2], build_frame[i][3] };
		//기둥을 설치하는 경우
		if (temp.a == 0 && temp.b == 0) {
			build_gd(temp);
		}
		//기동을 제거하는 경우
		else if (temp.a == 0 && temp.b == 1) {
			remove(temp);
			//이상있는지 확인
			if (!check())
				build_gd(temp);
		}
		//보를 설치하는 경우
		else if (temp.a == 1 && temp.b == 0) {
			build_bo(temp);
		}
		//보를 제거하는 경우
		else {
			remove(temp);
			if (!check())
				build_bo(temp);
		}
	}

	for (int i = N; i >= 0; i--) {
		for (int j = 0; j <= N; j++) {
			if (board[i][j] == 0 || board[i][j] == 1) {
				answer.push_back({ j, N - i, board[i][j] });
				cout << j << " " << N - i << " " << board[i][j] << endl;
			}
		}
	}
	return answer;
}

int main()
{
	int N;

	cin >> N;

	vector<vector<int>> build_frame(10, vector<int>(4));

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> build_frame[i][j];
		}
	}

	solution(N, build_frame);

}
