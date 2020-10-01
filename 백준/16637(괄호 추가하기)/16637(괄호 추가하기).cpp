// 백준_코딩테스트.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long max_v;
int length;
int g;
vector <char> con;
vector <bool> check;

long long calc() {
	vector <long long> temp1;
	vector <char> temp2;
	for (int i = 0; i < length; i++) {
		if (check[i]==true) {
			long long t;
			if (con[i + 1] == '+') {
				t = (con[i]-'0') + (con[i + 2]- '0');
			}
			else if (con[i + 1] == '-') {
				t = (con[i] - '0') - (con[i + 2] - '0');
			}
			else {
				t = (con[i] - '0') * (con[i + 2] - '0');
			}
			temp1.push_back(t);


			if (i + 3 < length) {
				temp2.push_back(con[i + 3]);
			}
			i += 3;
			continue;
		}
		if (isdigit(con[i])) {
			temp1.push_back(con[i]-'0');
		}

		else {
			temp2.push_back(con[i]);
		}
	}

	long long tn=temp1[0];
	for (int i = 0; i < temp2.size(); i++) {
		if (temp2[i] == '+') {
			tn += temp1[i+1];
		}
		else if (temp2[i] == '-') {
			tn -= temp1[i+1];
		}
		else {
			tn *= temp1[i+1];
		}
	}
	return tn;
}

void dfs(int start, int cnt) {
	//start 범위지정
	//if (start >= length) {
	if (cnt == g) {
		for (int i = 0; i < length; i++)
			cout << check[i] << " ";
			cout << "\n";

			max_v = max(max_v, calc());
		return;
	}

	for (int i = start; i < length - 1; i += 2) {
		
		if (check[i] == false && check[i + 1] == false && check[i - 1] == false) {
			check[i - 1] = true;
			check[i] = true;
			check[i + 1] = true;
		}

		dfs(i+2, cnt + 1);

		check[i - 1] = false;
		check[i] = false;
		check[i + 1] = false;
	}
}


int main()
{
	int n;
	cin >> n;

	con.resize(n);
	length = n;

	for (int i = 0; i < n; i++)
		cin >> con[i];
	g = ((length / 2) + 1) / 2;
	max_v = con[0]-'0';
	for (int i = 0; i < n; i++) {
		if (!isdigit(con[i])) {
			if (con[i] == '+') {
				max_v += (con[i + 1] - '0');
			}
			else if (con[i] == '-') {
				max_v -= (con[i + 1] - '0');
			}
			else {
				max_v *= (con[i + 1] - '0');
			}
		}
	}

	check.resize(n, false);

	dfs(1, 0);

	cout << max_v;
}

/*
#include <iostream>
#include <climits>
using namespace std;

int N, result = INT_MIN;
char a[19];
bool chk[19] = { 0 };
int res[19] = { 0 };

void cal() {
	int tmp_res = 0;
	if (chk[0] == 1)
		tmp_res += res[0];
	else
		tmp_res += a[0];
	for (int i = 0; i < N / 2; i++) {
		if (chk[2 * i + 1] == 1)
			continue;
		int rval;
		if (chk[2 * i + 2] == 1)
			rval = res[2 * i + 2];
		else
			rval = a[2 * i + 2];
		//계산
		if (a[2 * i + 1] == '+')
			tmp_res += rval;
		else if (a[2 * i + 1] == '-')
			tmp_res -= rval;
		else if (a[2 * i + 1] == '*')
			tmp_res *= rval;
	}
	if (tmp_res > result) {
		for (int i = 0; i < 17; i++)
			cout << chk[i] << " ";
		cout << "\t";
		result = tmp_res;
		cout << result<<"\n";
	}
}

void dfs(int ind) {
	cal();
	for (int i = ind; i < N / 2; i++) {
		if (chk[2 * i] == 1)
			continue;
		chk[2 * i] = 1, chk[2 * i + 1] = 1, chk[2 * i + 2] = 1;
		if (a[2 * i + 1] == '+')
			res[2 * i] = a[2 * i] + a[2 * i + 2];
		else if (a[2 * i + 1] == '-')
			res[2 * i] = a[2 * i] - a[2 * i + 2];
		else if (a[2 * i + 1] == '*')
			res[2 * i] = a[2 * i] * a[2 * i + 2];
		dfs(i + 2);
		chk[2 * i] = 0, chk[2 * i + 1] = 0, chk[2 * i + 2] = 0;
		res[2 * i] = 0;
	}
}

int main() {
	cin >> N;
	cin >> a;
	for (int i = 0; i <= N / 2; i++)
		a[2 * i] -= '0';
	dfs(0);
	cout << result << endl;
	return 0;
}
*/