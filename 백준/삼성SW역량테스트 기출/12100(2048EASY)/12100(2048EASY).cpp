// 12100(2048EASY).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
const int LIMIT = 5;

vector<int> gen(int k) {
	vector<int> e(LIMIT);
	for (int i = 0; i < LIMIT; i++) {
		e[i] = k & 3;
		k >>= 2 ;
	}
	return e;
}


int check(vector<vector<int>>& d, vector <int>& dir) {
	int n = d.size();
	vector<vector<pair<int, bool>>> t(n, vector<pair<int, bool>>(n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			t[i][j].first = d[i][j];

	for (int x : dir) {
		bool ok = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				t[i][j].second = false;
			}
		}
		
		while (true) {
			ok = false;
			if (x == 0) {		//윗방향
				for (int i = 1; i < n; i++) {
					for (int j = 0; j < n; j++){
						if (t[i][j].first == 0)
							continue;
						if (t[i - 1][j].first == 0) {
							t[i - 1][j].first = t[i][j].first;
							t[i - 1][j].second = t[i][j].second;
							t[i][j].first = 0;
							ok = true;
						}
						else if(t[i-1][j].first==t[i][j].first){
							if (t[i - 1][j].second == false && t[i][j].second==false) {
								t[i - 1][j].first *= 2;
								t[i - 1][j].second = true;
								t[i][j].first = 0;
								ok = true;
							}
						}
					}
				}
			}
			else if (x == 1) {		//아랫방향
				for (int i = n-2; i >= 0; i--) {
					for (int j = 0; j < n; j++) {
						if (t[i][j].first == 0)
							continue;
						if (t[i + 1][j].first == 0) {
							t[i + 1][j].first = t[i][j].first;
							t[i + 1][j].second = t[i][j].second;
							t[i][j].first = 0;
							ok = true;
						}
						else if (t[i + 1][j].first == t[i][j].first) {
							if (t[i + 1][j].second ==false && t[i][j].second==false) {
								t[i + 1][j].first *= 2;
								t[i + 1][j].second = true;
								t[i][j].first = 0;
								ok = true;
							}
						}
					}
				}
			}
			else if (x == 2) {		//왼쪽방향
				for (int i = 0; i < n; i++) {
					for (int j = 1; j < n; j++) {
						if (t[i][j].first == 0)
							continue;
						if (t[i][j-1].first == 0) {
							t[i][j-1].first = t[i][j].first;
							t[i][j-1].second = t[i][j].second;
							t[i][j].first = 0;
							ok = true;
						}
						else if (t[i][j-1].first == t[i][j].first) {
							if (t[i][j-1].second == false && t[i][j].second==false) {
								t[i][j-1].first *= 2;
								t[i][j-1].second = true;
								t[i][j].first = 0;
								ok = true;
							}
						}
					}
				}
			}
			if (x == 3) {		//오른쪽방향
				for (int i = 0; i < n; i++) {
					for (int j = n-2; j >= 0; j--) {
						if (t[i][j].first == 0)
							continue;
						if (t[i][j+1].first == 0) {
							t[i][j+1].first = t[i][j].first;
							t[i][j+1].second = t[i][j].second;
							t[i][j].first = 0;
							ok = true;
						}
						else if (t[i][j+1].first == t[i][j].first) {
							if (t[i][j+1].second == false && t[i][j].second == false) {
								t[i][j+1].first *= 2;
								t[i][j+1].second = true;
								t[i][j].first = 0;
								ok = true;
							}
						}
					}
				}
			}
			if (ok == false)
				break;
		}
	}
	int ans = 0;
	for(int i=0; i<n; i++)
		for (int j = 0; j < n; j++) {
			if (ans < t[i][j].first) {
				ans = t[i][j].first;
			}
		}
	return ans;
}

int main()
{
	int n;		//보드 크기
	cin >> n;

	vector <vector<int>> d(n, vector<int>(n));	// 블럭

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++)
			cin >> d[i][j];
	
	int ans = 0;
	for (int k = 0; k < (1 << (LIMIT * 2)); k++) {
		vector<int> dir = gen(k);
		int cur = check(d, dir);
		if (ans < cur) ans = cur;
	}

	cout << ans << '\n';
	return 0;
}

