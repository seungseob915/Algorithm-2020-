// 6603(로또).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	int n;

	while (true) {
		cin >> n;
		if (n == 0)
			return 0;

		vector<int> num(n);	// 숫자
		vector<bool> c(n, 0); // 조합 벡터

		for (int i = 0; i < n; i++)
			cin >> num[i];

		// 조합 벡터
		for (int i = 0; i < n; i++)
			if (i < 6)
				c[i] = 1;


				do {
					for (int i = 0; i < n; i++) {
						if(c[i])
							cout << num[i] << ' ';
					}
					cout << "\n";
				} while (prev_permutation(c.begin(), c.end()));
				cout << "\n";
	}
	return 0;
}
