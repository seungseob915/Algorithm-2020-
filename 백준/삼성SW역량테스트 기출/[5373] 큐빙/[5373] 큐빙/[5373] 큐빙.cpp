// [5373] 큐빙.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

char board[7][4][4] = {};
int T;

void wturn(int a) {
	char t_board[4][4] = {};

	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			t_board[j][4-i] = board[a][i][j];
		}
	}
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			board[a][i][j] = t_board[i][j];
		}
	}
}

void bturn(int a) {
	char t_board[4][4] = {};

	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			t_board[4 - j][i] = board[a][i][j];
		}
	}
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			board[a][i][j] = t_board[i][j];
		}
	}
}

void cir(char a, char b) {
	if (a == 'U') {
		if (b == '+') {
			wturn(1);
			char temp1 = board[4][1][1];
			char temp2 = board[4][1][2];
			char temp3 = board[4][1][3];

			board[4][1][1] = board[5][1][1];
			board[4][1][2] = board[5][1][2];
			board[4][1][3] = board[5][1][3];
			board[5][1][1] = board[3][1][1];
			board[5][1][2] = board[3][1][2];
			board[5][1][3] = board[3][1][3];
			board[3][1][1] = board[6][1][1];
			board[3][1][2] = board[6][1][2];
			board[3][1][3] = board[6][1][3];
			board[6][1][1] = temp1;
			board[6][1][2] = temp2;
			board[6][1][3] = temp3;
		}
		else {
			bturn(1);

			char temp1 = board[4][1][1];
			char temp2 = board[4][1][2];
			char temp3 = board[4][1][3];

			board[4][1][1] = board[6][1][1];
			board[4][1][2] = board[6][1][2];
			board[4][1][3] = board[6][1][3];
			board[6][1][1] = board[3][1][1];
			board[6][1][2] = board[3][1][2];
			board[6][1][3] = board[3][1][3];
			board[3][1][1] = board[5][1][1];
			board[3][1][2] = board[5][1][2];
			board[3][1][3] = board[5][1][3];
			board[5][1][1] = temp1;
			board[5][1][2] = temp2;
			board[5][1][3] = temp3;
		}
	}
	else if (a == 'D') {
		if (b == '+') {
			wturn(2);
			char temp1 = board[3][3][1];
			char temp2 = board[3][3][2];
			char temp3 = board[3][3][3];

			board[3][3][1] = board[5][3][1];
			board[3][3][2] = board[5][3][2];
			board[3][3][3] = board[5][3][3];
			board[5][3][1] = board[4][3][1];
			board[5][3][2] = board[4][3][2];
			board[5][3][3] = board[4][3][3];
			board[4][3][1] = board[6][3][1];
			board[4][3][2] = board[6][3][2];
			board[4][3][3] = board[6][3][3];
			board[6][3][1] = temp1;
			board[6][3][2] = temp2;
			board[6][3][3] = temp3;
		}
		else {
			bturn(2);

			char temp1 = board[3][3][1];
			char temp2 = board[3][3][2];
			char temp3 = board[3][3][3];

			board[3][3][1] = board[6][3][1];
			board[3][3][2] = board[6][3][2];
			board[3][3][3] = board[6][3][3];
			board[6][3][1] = board[4][3][1];
			board[6][3][2] = board[4][3][2];
			board[6][3][3] = board[4][3][3];
			board[4][3][1] = board[5][3][1];
			board[4][3][2] = board[5][3][2];
			board[4][3][3] = board[5][3][3];
			board[5][3][1] = temp1;
			board[5][3][2] = temp2;
			board[5][3][3] = temp3;
		}
	}
	else if (a == 'F') {
		if (b == '+') {
			wturn(3);
			char temp1 = board[1][3][1];
			char temp2 = board[1][3][2];
			char temp3 = board[1][3][3];

			board[1][3][1] = board[5][3][3];
			board[1][3][2] = board[5][2][3];
			board[1][3][3] = board[5][1][3];
			board[5][3][3] = board[2][1][3];
			board[5][2][3] = board[2][1][2];
			board[5][1][3] = board[2][1][1];
			board[2][1][3] = board[6][1][1];
			board[2][1][2] = board[6][2][1];
			board[2][1][1] = board[6][3][1];
			board[6][1][1] = temp1;
			board[6][2][1] = temp2;
			board[6][3][1] = temp3;
		}
		else {
			bturn(3);

			char temp1 = board[1][3][1];
			char temp2 = board[1][3][2];
			char temp3 = board[1][3][3];

			board[1][3][1] = board[6][1][1];
			board[1][3][2] = board[6][2][1];
			board[1][3][3] = board[6][3][1];
			board[6][1][1] = board[2][1][3];
			board[6][2][1] = board[2][1][2];
			board[6][3][1] = board[2][1][1];
			board[2][1][3] = board[5][3][3];
			board[2][1][2] = board[5][2][3];
			board[2][1][1] = board[5][1][3];
			board[5][3][3] = temp1;
			board[5][2][3] = temp2;
			board[5][1][3] = temp3;
		}
	}
	else if (a == 'B') {
		if (b == '+') {
			wturn(4);
			char temp1 = board[1][1][1];
			char temp2 = board[1][1][2];
			char temp3 = board[1][1][3];

			board[1][1][1] = board[6][1][3];
			board[1][1][2] = board[6][2][3];
			board[1][1][3] = board[6][3][3];
			board[6][1][3] = board[2][3][3];
			board[6][2][3] = board[2][3][2];
			board[6][3][3] = board[2][3][1];
			board[2][3][3] = board[5][3][1];
			board[2][3][2] = board[5][2][1];
			board[2][3][1] = board[5][1][1];
			board[5][3][1] = temp1;
			board[5][2][1] = temp2;
			board[5][1][1] = temp3;
		}
		else {
			bturn(4);

			char temp1 = board[1][1][1];
			char temp2 = board[1][1][2];
			char temp3 = board[1][1][3];

			board[1][1][1] = board[5][3][1];
			board[1][1][2] = board[5][2][1];
			board[1][1][3] = board[5][1][1];
			board[5][3][1] = board[2][3][3];
			board[5][2][1] = board[2][3][2];
			board[5][1][1] = board[2][3][1];
			board[2][3][3] = board[6][1][3];
			board[2][3][2] = board[6][2][3];
			board[2][3][1] = board[6][3][3];
			board[6][1][3] = temp1;
			board[6][2][3] = temp2;
			board[6][3][3] = temp3;
		}
	}
	else if (a == 'L') {
		if (b == '+') {
			wturn(5);

			char temp1 = board[1][1][1];
			char temp2 = board[1][2][1];
			char temp3 = board[1][3][1];

			board[1][1][1] = board[4][3][3];
			board[1][2][1] = board[4][2][3];
			board[1][3][1] = board[4][1][3];
			board[4][3][3] = board[2][1][1];
			board[4][2][3] = board[2][2][1];
			board[4][1][3] = board[2][3][1];
			board[2][1][1] = board[3][1][1];
			board[2][2][1] = board[3][2][1];
			board[2][3][1] = board[3][3][1];
			board[3][1][1] = temp1;
			board[3][2][1] = temp2;
			board[3][3][1] = temp3;
		}
		else {
			bturn(5);
			char temp1 = board[1][1][1];
			char temp2 = board[1][2][1];
			char temp3 = board[1][3][1];

			board[1][1][1] = board[3][1][1];
			board[1][2][1] = board[3][2][1];
			board[1][3][1] = board[3][3][1];
			board[3][1][1] = board[2][1][1];
			board[3][2][1] = board[2][2][1];
			board[3][3][1] = board[2][3][1];
			board[2][1][1] = board[4][3][3];
			board[2][2][1] = board[4][2][3];
			board[2][3][1] = board[4][1][3];
			board[4][3][3] = temp1;
			board[4][2][3] = temp2;
			board[4][1][3] = temp3;
		}
	}
	else if (a == 'R') {
		if (b == '+') {
			wturn(6);
			char temp1 = board[1][1][3];
			char temp2 = board[1][2][3];
			char temp3 = board[1][3][3];

			board[1][1][3] = board[3][1][3];
			board[1][2][3] = board[3][2][3];
			board[1][3][3] = board[3][3][3];
			board[3][1][3] = board[2][1][3];
			board[3][2][3] = board[2][2][3];
			board[3][3][3] = board[2][3][3];
			board[2][1][3] = board[4][3][1];
			board[2][2][3] = board[4][2][1];
			board[2][3][3] = board[4][1][1];
			board[4][3][1] = temp1;
			board[4][2][1] = temp2;
			board[4][1][1] = temp3;
		}
		else {
			bturn(6);
			char temp1 = board[1][1][3];
			char temp2 = board[1][2][3];
			char temp3 = board[1][3][3];

			board[1][1][3] = board[4][3][1];
			board[1][2][3] = board[4][2][1];
			board[1][3][3] = board[4][1][1];
			board[4][3][1] = board[2][1][3];
			board[4][2][1] = board[2][2][3];
			board[4][1][1] = board[2][3][3];
			board[2][1][3] = board[3][1][3];
			board[2][2][3] = board[3][2][3];
			board[2][3][3] = board[3][3][3];
			board[3][1][3] = temp1;
			board[3][2][3] = temp2;
			board[3][3][3] = temp3;
		}
	}
}


int main()
{
	cin >> T;

	while (T--) {
		for (int i = 1; i <= 3; i++) {
			for (int j = 1; j <= 3; j++) {
				board[1][i][j] = 'w';
				board[2][i][j] = 'y';
				board[3][i][j] = 'r';
				board[4][i][j] = 'o';
				board[5][i][j] = 'g';
				board[6][i][j] = 'b';
			}
		}
		
		int n;
		cin >> n;

		vector<string> v;

		for (int i = 0; i < n; i++) {
			string temp;
			cin >> temp;
			v.push_back(temp);
		}

		for (int i = 0; i < n; i++) {
			char a = v[i][0];
			char b = v[i][1];

			cir(a, b);
			
		}
		for (int i = 1; i <= 3; i++) {
			for (int j = 1; j <= 3; j++) {
				cout << board[1][i][j];
			}
			cout << endl;
		}
	}
}
