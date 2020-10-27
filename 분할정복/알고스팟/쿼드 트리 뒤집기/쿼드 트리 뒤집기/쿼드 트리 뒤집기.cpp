// 쿼드 트리 뒤집기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
using namespace std;

int C;
string ans;
string str;
string::iterator iter;

void Init() {
	ans.clear();
	str.clear();
}

string reverse(string::iterator& it) {
	char head = *it;
	it++;

	if (head == 'b' || head == 'w') return string(1, head);

	//x일때 순서 변환해줘야함
	else {
		string u_left = reverse(it);
		string u_right = reverse(it);
		string d_left = reverse(it);
		string d_right = reverse(it);
		return 'x' + d_left + d_right + u_left + u_right;
	}
}

int main()
{
	cin >> C;

	while (C--) {
		Init();
		cin >> str;
		iter = str.begin();
		cout << reverse(iter) << endl;
	}
}
