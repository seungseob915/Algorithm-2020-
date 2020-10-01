// [1차] 프렌즈4블록.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <string>
#include <memory.h>

using namespace std;
int check[30][30] = {};
int chk_cnt=0, cnt = 0;

// 체크해주는 함수
void find(int i, int j, vector<string> &board) {
	for (int x = 0; x < 2; x++) {
		for (int y = 0; y < 2; y++) {
			if (board[i + x][j + y] != board[i][j]) {
				return;
			}
		}
	}

	// 다 같으면
	for (int x = 0; x < 2; x++) {
		for (int y = 0; y < 2; y++) {
			check[i+x][j+y] = 1;
		}
	}

	chk_cnt++;
}

void simulate(vector<string> &board) {
	int mm = board.size();
	int nn = board [0].size();

	while (1) {
		memset(check, 0, sizeof(check));
		chk_cnt = 0;

		// 지울게 있는지 check하자
		for (int i = 0; i < mm-1; i++) {
			for (int j = 0; j < nn-1; j++) {
				if(board[i][j]!='0')
					find(i,j, board);
			}
		}
		
		/// check하자
		for (int i = 0; i < mm; i++) {
			for (int j = 0; j < nn; j++) {
				cout << check[i][j];
			}
			cout << endl;
		}
		cout << cnt << endl;
		cout << endl;

		// check했을때 더이상 바뀔게 없으면
		if (chk_cnt==0) {
			break;
		}

		//지운 만큼 카운트 해주고
		for (int i = 0; i < mm; i++) {
			for (int j = 0; j < nn; j++) {
				if (check[i][j] == 1) {
					cnt++;
					board[i][j] = '0';
				}
			}
		}

		//비어있는칸을 땡겨주자
		for (int j = 0; j < nn; j++) {
			for (int i = mm - 1; i >= 0; i--) {
				if (board[i][j] == '0') {
					for (int k = i - 1; k >= 0; k--) {
						if (board[k][j] != '0') {
							board[i][j] = board[k][j];
							board[k][j] = '0';
							break;
						}
					}
				}
			}
		}
	}
}

int solution(int m, int n, vector<string> board) {
	int answer = 0;
	return answer;
}

int main()
{
	int m, n;

	cin >> m >> n;

	vector<string> brd;

	for (int i = 0; i < m; i++) {
		string temp;
		cin >> temp;
		brd.push_back(temp);
	}

	simulate(brd);

	cout << cnt;
}
