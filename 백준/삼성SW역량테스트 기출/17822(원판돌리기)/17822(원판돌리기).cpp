// 17822(원판돌리기).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;

int n, m, t;
int map[51][51];

typedef struct {
	int x, d, k;
}order;

order od[51];

int main()
{
	cin >> n >> m >> t;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> map[i][j];

	for (int i = 0; i < t; i++) {
		int temp_x, temp_d, temp_k;
		cin >> temp_x >> temp_d >> temp_k;
		od[i].x = temp_x;
		od[i].d = temp_d;
		od[i].k = temp_k;
	}

	for (int i = 0; i < t; i++) {
		int now_x = od[i].x;
		int now_d = od[i].d;
		int now_k = od[i].k;


			//몇번할지 삭제과정 이후에 정하자
			while (now_k--) {
				//시계방향으로 회전해야할 때
				if (now_d == 0) {
					int temp = map[now_x][m];
					for (int i = m; i >= 1; i--)
						map[now_x][i] = map[now_x][i - 1];
					map[now_x][1] = temp;
				}

				//반시계방향으로 회전해야할 때
				else if (now_d == 1) {
					int temp = map[now_x][1];
					for (int i = 2; i <= m; i++)
						map[now_x][i - 1] = map[now_x][i];
					map[now_x][m] = temp;
				}

				//비슷한 수가 있는지 확인
				int comp_cnt = 0;
				// 회전이 한번 끝났으니 인접한 수 찾기
				for (int i = 1; i <= m; i++) {
					//같은 라인에서 오른쪽 기준 같은지 확인 (만약 3곳이 연속으로 같다면?)
					if (map[now_x][i] == map[now_x][(i + 1)%m]) {
						if (map[now_x][i] != 0) {
							map[now_x][i] = 0;
							map[now_x][(i + 1) % m] = 0;
							comp_cnt++;
						}
					}
					//다른 라인에서 같은지 확인
					if (now_x + 1 <= n && map[now_x][i] == map[now_x + 1][i]) {
						if (map[now_x][i] != 0) {
							map[now_x + 1][i] = map[now_x][i] = 0;
							comp_cnt++;
						}
					}
					
					if (now_x - 1 >= 1 && map[now_x][i] == map[now_x - 1][i])
						if (map[now_x][i] != 0) {
							map[now_x - 1][i] = map[now_x][i] = 0;
							comp_cnt++;
						}
					}

				//지울게 없을때
				if(comp_cnt==0){
					int sum = 0;
					for (int i = 1; i <= m; i++)
						sum += map[now_x][i];
					
					sum = sum / m;
					cout << sum;
					for (int i = 1; i <= m; i++) {
						if (map[now_x][i] > sum)
							map[now_x][i] -= 1;
						else if (map[now_x][i] < sum)
							map[now_x][i] += 1;
					}
				}
		}
	}
		int ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				ans += map[i][j];
		cout << ans;
		return 0;
}
