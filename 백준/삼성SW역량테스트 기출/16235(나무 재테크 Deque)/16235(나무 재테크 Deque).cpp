// 16235(나무 재테크 Deque).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include<vector>
#include <queue>
using namespace std;

int n, m, k;
int map[11][11];
int regular[11][11];
deque <int> live[11][11];	//덱을 이용해서 어린것이 맨앞, 나이들수록 뒤로
queue <int> dead[11][11];	//죽은 것은 일반 큐에 삽입
int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };


//봄, 나이만큼 양분 먹고, 나이+1
void spring(){
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int size = live[i][j].size();
			for (int k = 0; k < size; k++) {
				int age = live[i][j].front();
				live[i][j].pop_front();

				//양분 먹을 수 있으면 나이 증가
				if (map[i][j] >= age) {
					map[i][j] -= age;
					live[i][j].push_back(age + 1);
				}

				//먹을 수 없으면 죽음
				else {
					dead[i][j].push(age);
				}
			}
		}
	}
}


//여름, 죽은 나무를 (나무/2) 만큼 양분으로,
void summer() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			while (!dead[i][j].empty()) {
				map[i][j] += dead[i][j].front() / 2;
				dead[i][j].pop();
			}
		}
	}
}


//가을, 나이가 5의 배수인 나무들을 8방향으로 번식
void fall() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int size = live[i][j].size();
			for (int k = 0; k < size; k++) {
				int age = live[i][j][k];

				// 8방향 번식
				if (age % 5 == 0) {
					for (int dir = 0; dir < 8; dir++) {
						int nx = i + dx[dir];
						int ny = j + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= n)
							continue;
						live[nx][ny].push_front(1);
					}
				}
			}
		}
	}
}



//겨울, 양분 추가
void winter() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] += regular[i][j];
		}
	}
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;

	//양분 입력하기
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> regular[i][j];
			map[i][j] = 5;
		}

	//나무 심기
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		live[x - 1][y - 1].push_front(z);	//나이 z인 것을 live deque에 삽입
	}

	//k년 만큼 반복
	while (k--) {
		spring();
		summer();
		fall();
		winter();
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (live[i][j].empty())
				continue;
			cnt += live[i][j].size();	//해당 위치의 살아있는 나무의 갯수를 확인
		}
	}
	cout << cnt;
}
