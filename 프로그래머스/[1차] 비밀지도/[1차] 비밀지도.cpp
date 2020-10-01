// [1차] 비밀지도.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n; // 보드의 크기
int arr1[16];
int arr2[16];
char arr[16][16];

//2진수로 변환
void binary(int i) {
	int temp1 = arr1[i];
	int temp2 = arr2[i];

	char t_t1[16];
	char t_t2[16];

	for (int j = n - 1; j >= 0; j--) {
		int tt1 = temp1 % 2;
		int tt2 = temp2 % 2;
		temp1 /= 2;
		temp2 /= 2;
				
		if (tt1==0 && tt2 == 0)
			arr[i][j] = ' ';
		else
			arr[i][j] = '#';
	}
	return;
}

int main()
{
	cin >> n;

	vector <string> str(n);
	
	for (int i = 0; i < n; i++)
		cin >> arr1[i];

	for (int i = 0; i < n; i++)
		cin >> arr2[i];
	
	//or연산
	for (int i = 0; i < n; i++) {
		binary(i);
	}

	
	for (int i = 0; i < n; i++) {
		string temp = arr[i];
		str[i]=temp;
		for (int j = 0; j < n; j++) {
			cout << arr[i][j];
		}
		cout << "\n";
	}

	for (int i = 0; i < n; i++)
		cout << str[i]<<"\n";
	return 0;
}


/*
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int nn; // 보드의 크기
vector <int> arr11;
vector <int> arr22;
char arr[16][16];

//2진수로 변환
void binary(int i) {
	int temp1 = arr11[i];
	int temp2 = arr22[i];

	char t_t1[16];
	char t_t2[16];

	for (int j = nn - 1; j >= 0; j--) {
		int tt1 = temp1 % 2;
		int tt2 = temp2 % 2;
		temp1 /= 2;
		temp2 /= 2;

		if (tt1==0 && tt2 == 0)
			arr[i][j] = ' ';
		else
			arr[i][j] = '#';
	}
	return;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {

	vector <string> str(n);
	nn=n;
	arr11=arr1;
	arr22=arr2;

		//or연산
	for (int i = 0; i < n; i++) {
		binary(i);
	}


	for (int i = 0; i < n; i++) {
		string temp = arr[i];
		str[i]=temp;
	}

	return str;
}
*/