// 프로그래머스.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// getline 함수 사용, vector내 문자열 저장

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string str1, str2;

int main()
{
	getline(cin, str1);
	getline(cin, str2);
		
	vector <string> n_str1;
	vector <string> n_str2;

	int gap = (char) 'a' - (char) 'A';	//32

	
	//포문 돌면서 특수문자 없는 것만 옮겨담기
	for (int i = 0; i < str1.size()-1; i++) {
		string temp="";
		//문자만 포함
		if (((str1[i] >= 'a' && str1[i] <= 'z') || (str1[i] <= 'Z' && str1[i] >= 'A')) && ((str1[i+1] >= 'a' && str1[i+1] <= 'z') || (str1[i+1] <= 'Z' && str1[i+1] >= 'A'))) {
			//대문자이면 소문자로 변경
			if (str1[i] <= 'Z' && str1[i] >= 'A')
				str1[i] += gap;
			//대문자이면 소문자로 변경
			if (str1[i+1] <= 'Z' && str1[i+1] >= 'A')
				str1[i+1] += gap;
			temp.push_back(str1[i]);
			temp.push_back(str1[i+1]);
			n_str1.push_back(temp);
		}
	}

	//포문 돌면서 특수문자 없는 것만 옮겨담기
	for (int i = 0; i < str2.size()-1; i++) {
  		string temp = "";
		if (((str2[i] >= 'a' && str2[i] <= 'z') || (str2[i] <= 'Z' && str2[i] >= 'A')) && ((str2[i+1] >= 'a' && str2[i+1] <= 'z') || (str2[i+1] <= 'Z' && str2[i+1] >= 'A'))) {
			//대문자이면 소문자로 변경
			if (str2[i] <= 'Z' && str2[i] >= 'A')
				str2[i] += gap;
			//대문자이면 소문자로 변경
			if (str2[i+1] <= 'Z' && str2[i+1] >= 'A')
				str2[i+1] += gap;
			temp.push_back(str2[i]);
			temp.push_back(str2[i+1]);
			n_str2.push_back(temp);
		}
	}


	vector <bool> a(n_str1.size(), false);	// 1234 있을때 12의 체크 여부는 1에 기입
	vector <bool> b(n_str2.size(), false);

	int total = a.size() + b.size();
	int cnt = 0;

	//교집합 찾기(비교 시작)
	for (int i = 0; i < n_str1.size(); i++) {
		for (int j = 0; j < n_str2.size(); j++) {
			//이미 확인을 한 집합이라면
			if (a[i] == true || b[j] == true)
				continue;
			//문자가 같으면
			if (n_str1[i] == n_str2[j]) {
				cnt++;
				a[i] = true;
				b[j] = true;
				break;
			}
		}
	}

	total -= cnt;
	int ans;

	if (total == 0 && cnt == 0)
		ans = 65536;

	else
		ans = ((double) cnt / (double) total) * 65536;


	cout <<ans;
	return 0;
}

