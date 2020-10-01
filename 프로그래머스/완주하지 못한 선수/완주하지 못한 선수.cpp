// 완주하지 못한 선수.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 해쉬를 이용하자! 동명이인이 있으므로 해쉬에서 key-value값이 0인 key는 완주 다한거, 완주못한놈은 >1

#include <iostream>
#include <vector>
#include <string>
#include <map>


using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	int total = participant.size();

	map <string, int> runner;	//숫자가 남아있으면 완주 못한것

	for (int i = 0; i < total; i++) {
		// 최초에는 해쉬를 통해 선수 숫자로 초기화(중복된 이름이 있을 수 있어 bool로는 못하고 숫자로 카운트해야됨)
		runner[participant[i]]++;
	}

	int winner_num = completion.size();

	// 완주자 확인하자
	for (int i = 0; i < winner_num; i++) {
			runner[completion[i]]--;	//완주자는 1명씩 줄이기
	}

	for (int i = 0; i < total; i++) {
		if (runner[participant[i]] > 0) {
			return participant[i];
		}
	}
}


int main()
{
	vector <string> p(4);
	vector<string> c(3);

	for (int i = 0; i < 4; i++)
		cin >> p[i];

	for (int i = 0; i < 3; i++)
		cin >> c[i];

	string a = solution(p, c);

	cout << a;
}
