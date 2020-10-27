// [1992] 쿼드트리.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
using namespace std;

string ans;
int N;
int board[65][65] = { 0, };

string convert(int x, int y, int length) {
	int half = length / 2;
	if (half == 0) {
		return to_string(board[x][y]);
	}
	string u_left = convert(x, y, half);
	string u_right = convert(x, y + half, half);
	string d_left = convert(x + half, y, half);
	string d_right = convert(x + half, y+half, half);
	
	if (u_left.size() == 1 && u_left == u_right && u_right == d_left && d_left == d_right) {
		return u_left;
	}
	else {
		return '(' + u_left + u_right + d_left + d_right + ')';
	}
}

int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%1d", &board[i][j]);
		}
	}
	cout << convert(1, 1, N) << endl;
}


/*

// [1992] 쿼드트리.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
using namespace std;

string ans;
int N;
int board[65][65] = { 0, };

string convert(int x, int y, int length) {
	int half = length / 2;
	if (half == 0) {
		return to_string(board[x][y]);
	}

	bool flag = true;
	int standard = board[x][y];
	for (int i = x; i < x + length; i++) {
		for (int j = y; j < y + length; j++) {
			if (standard != board[i][j]) {
				flag = false;
				break;
			}
		}
	}
	if (flag) 	return to_string(standard);
	else {
		string u_left = convert(x, y, half);
		string u_right = convert(x, y + half, half);
		string d_left = convert(x + half, y, half);
		string d_right = convert(x + half, y + half, half);
		return '(' + u_left + u_right + d_left + d_right + ')';
	}
}

int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%1d", &board[i][j]);
		}
	}
	cout << convert(1, 1, N) << endl;
}
*/