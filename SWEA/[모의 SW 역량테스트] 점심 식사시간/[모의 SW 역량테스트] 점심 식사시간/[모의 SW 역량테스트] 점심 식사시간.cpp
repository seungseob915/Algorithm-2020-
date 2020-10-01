// [모의 SW 역량테스트] 점심 식사시간.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <cmath>
#include <memory.h>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct People {
	int no;
	int x;
	int y;
	int lv_time;
}people;

typedef struct Stair {
	int x;
	int y;
	int d;
}stair;


int N, Pn, Sn, ans = 987654321;	//board Size, 사람수, 계단수
int board[11][11];  // 1은 사람 나머지는 입구
stair s[2];
people p[10];
int dis_ps[11][3];  //사람과 계단의 거리
int cir[11] = {};	//순열
queue <people> wait[2];	//2개의 계단의 대기열

int move() {
	//계단 내 사람 수 
	int s_cnt[2] = {0,0};
	int t_dis[11][3] = {};
	people str[2][3] = {};
	people t_p[10];
	bool finish[11];
	memset(finish, false, sizeof(finish));

	// 거리 배열 초기화
	for (int i = 0; i < Pn; i++) {
		for (int j = 0; j < 2; j++) {
			t_dis[i][j] = dis_ps[i][j];
		}
	}

	for (int i = 0; i < Pn; i++) {
		t_p[i] = p[i];
	}

	int time =0;

	while (1) {
		bool total_f = true;
		
		time++;

		//cout << time << endl;


		// 계단안에 있는 사람 처리
		for (int i = 0; i < 2; i++) {
			int blankcnt = 0;
			for (int j = 0; j < 3; j++) {
				if (s_cnt[i] > 0) {
					str[i][j].lv_time--;		//시간 깎기
					// 시간이 다 됐으면
					if (str[i][j].lv_time == 0) {
						finish[str[i][j].no-1] = true;
						s_cnt[i]--;	//카운트 줄이기
						blankcnt++;

						//배열 한칸씩 땡기기
					}
				}
			}
			while (blankcnt--) {
				for (int j = 0; j < 2; j++) {
					str[i][j] = str[i][j+1];
				}
				str[i][2] = {};	//초기화
			}
		}

		// 대기하는 놈들 계단으로 보내기
		for (int i = 0; i < 2; i++) {
			// 대기하는 놈들이 있다면
			while (s_cnt[i] < 3) {
				if (!wait[i].empty()) {
					people temp = wait[i].front();
					str[i][s_cnt[i]] = temp;
					s_cnt[i]++;
					wait[i].pop();
				}
				else {
					break;
				}
			}
		}

		//사람이 움직일 때
		for (int i = 0; i < Pn; i++) {
			t_dis[i][cir[i]]--;	// 시간 1초마다 거리 -1씩
			
			//계단에 다 도착했으면
			if (t_dis[i][cir[i]] == 0) {
				p[i].lv_time = s[cir[i]].d;
				wait[cir[i]].push(p[i]);
			}
			//cout << endl;

		}


		for (int i = 0; i < Pn; i++) {
			if (finish[i] == false)
				total_f = false;
		}

		//for (int i = 0; i < 2; i++) {
		//	for (int j = 0; j < 3; j++) {
		//		cout << str[i][j].no << " ";
		//	}
		//	cout << endl;
		//}

		//cout << endl;

		//for (int i = 0; i < 2; i++) {
		//	for (int j = 0; j < 3; j++) {
		//		cout << str[i][j].lv_time << " ";
		//	}
		//	cout << endl;
		//}
		//cout << endl;

		//for (int i = 0; i < Pn; i++)
		//	cout << p[i].lv_time << " ";

		//cout << endl;

		if (total_f == true)
			break;

	}
	return time;
}


void dfs(int depth) {
	if (depth == Pn){
		ans = min(ans, move());
		return;
	}

	for (int i = 0; i <= 1; i++) {
		cir[depth] = i;
		dfs(depth + 1);
	}
	/*if (depth < 3) {
		cir[depth] = 0;
	}
	else {
		cir[depth] = 1;
	}
	dfs(depth + 1);
	*/
}

int main()
{
	int T, Tcnt = 1;
	cin >> T;
	while (T--) {

	cin >> N;
	Pn = 0;
	Sn = 0;


	//보드 입력
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
			
			//계단을 찾으면
			if (board[i][j] > 1) {
				s[Sn].x = i;
				s[Sn].y = j;
				s[Sn].d = board[i][j];
				Sn++;
			}

			//사람을 찾으면(사람의 전체수)
			if (board[i][j] == 1) {
				p[Pn].no = Pn+1;
				p[Pn].x = i;
				p[Pn].y = j;
				p[Pn].lv_time = 0;
				Pn++;
			}
		}
	}

	//지점별 거리 계산
	int person_no = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (board[i][j] == 1) {
				for (int str_cnt = 0; str_cnt <= 1; str_cnt++) {
					dis_ps[person_no][str_cnt] = abs(i - s[str_cnt].x) + abs(j - s[str_cnt].y);
				}
				person_no++;
			}
		}
	}

	fill(cir, cir + 11, 0);
	ans = 987654321;
	dfs(0);

	cout << "#" <<Tcnt++ << " " << ans << endl;
	}
}


/*
6
0 0 0 1 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 1 0 0 0 0
2 0 1 0 0 0
0 0 2 0 0 0
6
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
1 0 0 0 0 0
0 0 0 2 0 4
7
0 0 0 0 0 0 0
0 0 0 0 0 0 4
0 0 0 0 1 0 0
1 0 0 1 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 2 0 0 0 0 0
*/