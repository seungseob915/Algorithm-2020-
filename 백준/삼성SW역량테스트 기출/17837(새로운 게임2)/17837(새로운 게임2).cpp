// 17837(새로운 게임2).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef struct {
	int x, y, d;
}Horse;

int n, k;
int map[13][13];
int max_turn = 1000;
bool isEnd = false;
int dx[] = { 0, 0, 0, -1, 1 };
int dy[] = { 0, 1, -1, 0, 0 };
stack<int> now[13][13];		//현재 말 마리 수
Horse h[11];		//말
int turn;	//결과 값

void solo_move(int i, int x, int y, int nx, int ny) {
	// 임시 컨테이너에 저장
	vector<int> a;
	while (now[x][y].top() != i) {
		a.push_back(now[x][y].top());
		now[x][y].pop();
	}
	int temp=now[x][y].top();
	now[x][y].pop();
	now[nx][ny].push(temp);
	h[temp].x=nx;
	h[temp].y = ny;

	// 다시 복원
	int length = a.size();
	for (int i = length - 1; i >= 0; i--) {
		now[x][y].push(a[i]);
	}
}

void move(int i, int x, int y, int nx, int ny) {
	// 임시 컨테이너에 저장
	vector<int> a;
	while (now[x][y].top()!=i) {
		a.push_back(now[x][y].top());
		now[x][y].pop();
	}

	now[x][y].pop();
	now[nx][ny].push(i);
	if (now[nx][ny].size() >= 4) {
		isEnd = true;
		return;
	}

	// 이동할 곳 컨테이너에 저장
	int length=a.size();
	for (int i = length - 1; i >= 0; i--) {
		now[nx][ny].push(a[i]);
		h[a[i]].x = nx;
		h[a[i]].y = ny;
		if (now[nx][ny].size() >= 4) {
			isEnd = true;
			return;
		}
	}
}


// 컨테이너 내 순서를 뒤집어서 넣기
void rev_move(int i, int x, int y, int nx, int ny) {
	// 바로 이동
	while (now[x][y].top()!=i) {
		now[nx][ny].push(now[x][y].top());
		h[now[x][y].top()].x = nx;
		h[now[x][y].top()].y = ny;
		now[x][y].pop();
		if (now[nx][ny].size() >= 4) {
			isEnd = true;
			return;
		}
	}

	now[nx][ny].push(i);
	h[i].x = nx;
	h[i].y = ny;
	now[x][y].pop();
	if (now[nx][ny].size() >= 4) {
		isEnd = true;
		return;
	}
}


void simulate(int i, int x, int y, int d) {
	int nx;
	int ny;
	int nd=d;
	
	//다음 방향 설정
	nx = x + dx[d];
	ny = y + dy[d];
	
	//파란색 및 경계범위 초과시 (방향만 바뀜)
	if (nx > n || nx < 1 || ny > n || ny <1) {
		if (d == 1 || d == 2)
			nd = (d % 2) + 1;
		else if (d == 3 || d == 4)
			nd = (d % 2) + 3;
		nx = x;
		ny = y;
		h[i].d = nd;

		int nnx = x+dx[nd];
		int nny = y+dy[nd];
		if (nnx <= n && nnx > 0 && nny <=n && nny > 0 && map[nnx][nny] != 2) {
			nx = nnx;
			ny = nny;
			simulate(i, nx, ny, nd);
		}
	}

	//흰색
	else if (map[nx][ny] == 0) {
		// 말판을 그대로 다음좌표에 옮기면된다
		move(i, x, y, nx, ny);
		}

	//빨간색
	else if (map[nx][ny] == 1) {
		// 말판 내 쌓여있는 말판 순서 변경 후 이동
		rev_move(i, x, y, nx, ny);
	}
}

int main()
{
	cin >> n >> k;

	// 맵 정보 입력
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cin >> map[i][j];
	}


	// 말 정보 입력
	for (int i = 1; i <= k ; i++) {
		int tx, ty, td;
		cin >> tx>>ty>>td;
		h[i] = { tx, ty, td };
		now[tx][ty].push(i);	// 말 위치 최신화
	}


	//게임 시작
	while(turn<=1000) {
		turn++;
		for (int i = 1; i <= k; i++) {
			int tx = h[i].x;
			int ty = h[i].y;
			int td = h[i].d;

			simulate(i, tx, ty, td);
			if (isEnd)
				break;
		}
		if (isEnd)
			break;
	}


	//결과 값
	if(!isEnd)
		cout << -1 << "\n";
	else
		cout << turn;
	return 0;
}


