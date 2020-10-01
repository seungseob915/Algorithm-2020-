// 14888(연산자 끼워넣기).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main()
{
	int n, result;
	cin >> n;
	
	vector<int> num(n);
	vector<int> cal(n - 1);
	vector<int> final_result;
	int c[4];	//0: 덧셈, 1: 뺄셈, 2:곱셈, 3: 나눗셈

	for (int i = 0; i < n; i++)
		cin >> num[i];

	for (int i = 0; i < 4; i++)
		cin >> c[i];

	int count = 0;

	for (int i = 0; i < c[0]; i++) {
		cal[count] = 0;
		count++;
	}
	for (int i = 0; i < c[1]; i++) {
		cal[count] = 1;
		count++;
	}
	for (int i = 0; i < c[2]; i++) {
		cal[count] = 2;
		count++;
	}
	for (int i = 0; i < c[3]; i++) {
		cal[count] = 3;
		count++;
	}

	
	do {
		result = num[0];

		for (int i = 0; i < n - 1; i++) {
			if (cal[i] == 0)
				result = result + num[i + 1];
			else if (cal[i] == 1)
				result = result - num[i + 1];
			else if (cal[i] == 2)
				result = result * num[i + 1];
			else if (cal[i] == 3)
				result = result / num[i + 1];
		}
		final_result.emplace_back(result);
	} while (next_permutation(cal.begin(), cal.end()));

	auto final=minmax_element(final_result.begin(), final_result.end());	//함수이용 minmax_element(오름차순으로 벡터 정렬)
	cout << *final.second<<"\n";
	cout << *final.first;
	
	return 0;
}

