// 4963(섬의 개수).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <cstring>

int map[50][50];
int check[50][50];  // 방문: 1, 미방문: 0
int dh[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dw[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int h, w;
void bfs(int, int, int);

int main()
{
	do {
		scanf("%d %d", &w, &h);
		
		int cnt = 0;	// 단지수 카운트
		memset(check, 0, sizeof(check));	//미방문으로 초기화
	
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				scanf("%1d", &map[i][j]);		//배열 입력시 숫자 한개씩

		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				if (check[i][j] == 0 && map[i][j] == 1)
					bfs(i, j, ++cnt);

		if(!(w == 0 && h == 0))
			printf("%d\n", cnt);
	} while (!(w == 0 && h == 0));

	return 0;
}

void bfs(int y, int x, int cnt) {
	check[y][x] = 1;	//방문체크
	for (int i = 0; i < 8; i++) {
		int nx = x + dw[i];
		int ny = y + dh[i];

		if (nx >= 0 && ny >= 0 && nx < w && ny < h)
			if (check[ny][nx] == 0 && map[ny][nx] == 1)
				bfs(ny, nx, cnt);
	}
	
}