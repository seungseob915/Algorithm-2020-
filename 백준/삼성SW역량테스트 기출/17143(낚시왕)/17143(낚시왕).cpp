// 17143(낚시왕).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 구조체 써서 한번 작성

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


//많은 변수저장을 위한 상어 구조체 선언
typedef struct {
	int rr, cc, s, d, z;	//s: 속력, d: 이동방향, z:크기
}shark;

int r, c, m;
shark sharklist[100001];
bool sharkdead[100001]; //상어 잡혔는지 여부

int map[101][101];	//상어의 위치 및 사람 위치 저장 보드
int copymap[101][101];	//상어의 위치 및 사람 위치 저장 보드
int dr[] = { 0, -1, 1, 0, 0 };
int dc[] = { 0, 0, 0, 1, -1};
int score, cnt;	//cnt: 몇마리 잡았는지? score: 잡은 상어의 크기

//상어 잡기
void catchshark(int i) {
	for (int k = 1; k <= r; k++) {
		if (map[k][i] > 0) {
			sharkdead[map[k][i]] = true;
			cnt += 1;	//잡은 상어 수
			score += sharklist[map[k][i]].z;
			map[k][i] = 0;
			return;
		}
	}
}

//상어 이동
void moveshark() {
	memset(copymap, 0, sizeof(copymap));

	//살아있는 모든 상어가 움직임
	for (int i = 1; i <= m; i++) {
		if (sharkdead[i])
			continue;

		shark cur = sharklist[i];
		int x, y, s, dir, z;
		
		x = cur.rr;
		y = cur.cc;
		s = cur.s;
		dir = cur.d;
		z = cur.z;

			map[x][y] = 0;	//상어가 움직일것이므로 현재위치는 0이됨

			int nr = x, nc = y;
			
			//열방면
			if (dir == 1 || dir == 2) {
				int move = s % ((r - 1) * 2);	//move 칸 움직여야 다음위치

				for (int i = 0; i < move; i++) {
					nr += dr[dir];	//dir 방향으로 1만큼 이동
					
					// 위쪽벽에 부딪혔을 때
					if (nr < 1) {
						dir= 2;
						nr = 2;
					}

					// 아래쪽벽에 부딪혔을 때
					else if (nr > r) {
						dir = 1;
						nr = r-1;
					}
				}
			}
			//행방면
			else if (dir == 3 || dir == 4) {
				int move = s % ((c - 1) * 2);

				for (int i = 0; i < move; i++) {
					nc += dc[dir];

					//오른쪽 벽에 부딪혔을때
					if (nc > c) {
						dir = 4;
						nc = c - 1;
					}

					//왼쪽벽에 부딪혔을때
					else if (nc < 1) {
						dir = 3;
						nc = 2;
					}
				}
			}

			// 상어가 움직이다 다른상어 만났을때
			if (copymap[nr][nc] != 0) {
				int temp = copymap[nr][nc];
				if (sharklist[temp].z < z)	//사이즈가 만난애보다 크면
					sharkdead[temp] = true;

				else {
					sharkdead[i] = true;	//사이즈가 만난애보다 작으면
					continue;
				}
			}

			copymap[nr][nc] = i;
			sharklist[i] = { nr, nc, s, dir, z };
		}
	
	for (int i = 1; i <= m; i++) {
		if (sharkdead[i])
			continue;
		map[sharklist[i].rr][sharklist[i].cc] = i;
	}

}


int main()
{
	cin >> r >> c >> m;
	
	for (int i = 1; i <= m; i++) {
		int tr, tc, ts, td, tz;
		cin >> tr >> tc >> ts >> td >> tz;
		sharklist[i] = { tr, tc, ts, td, tz };
		map[tr][tc] = i;	//상어의 이름을 map에 표시
	}

	//낚시왕이 이동하는 경로
	for (int i = 1; i <= c; i++) {
		if (cnt == m)
			break;
		catchshark(i);		//상어 잡기
		moveshark();			//상어 이동
	}
	cout << score;
}

