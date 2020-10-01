// 후보키.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int col;
int row;
bool visit[8];
vector<vector<string>> rel;
vector<string> colcomb;

bool cmp(string a, string b) {
	return a.length() < b.length();
}

void dfs(int idx) {
	set<string> temp;
	for (int i = 0; i < row; i++) {
		string str = "";
		for (int j = 0; j < col; j++) {
			if (visit[j]) {
				str += rel[i][j];
			}
		}
		temp.insert(str);
	}

	if (temp.size() == row) {
		string str = "";
		for (int j = 0; j < col; j++) {
			if (visit[j]) {
				str += to_string(j);
			}
		}
		colcomb.push_back(str);
		return;
	}

	for (int i = idx + 1; i < col; i++) {
		if (visit[i])
			continue;
		visit[i] = true;
		dfs(i);
		visit[i] = false;
	}
}


int solution(vector<vector<string>> relation) {
	int answer = 0;
	rel = relation;
	col = rel[0].size();
	row = rel.size();

	//조합 dfs
	for (int i = 0; i < col; i++) {
		if (visit[i])
			continue;

		visit[i] = true;
		dfs(i);
		visit[i] = false;
	}

	sort(colcomb.begin(), colcomb.end(), cmp);

	for (int i = 0; i < colcomb.size(); i++) {
		string s = colcomb[i];

		for (int j = i + 1; j < colcomb.size(); j++) {
			bool isCheck = false;
			for (int k = 0; k < s.size(); k++) {
				if (colcomb[j].find(s[k]) == -1) {
					isCheck = true;
					break;
				}
			}
			if (!isCheck) {
				colcomb.erase(colcomb.begin() + j);
				j--;
			}
		}
	}
	answer = colcomb.size();

	return answer;
}

int main()
{

}
