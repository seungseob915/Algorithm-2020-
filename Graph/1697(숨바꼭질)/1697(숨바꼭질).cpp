// 1697(숨바꼭질).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>

using namespace std;

int dist[1000001];
bool check[1000001];		
int n, k;

int main()
{
	scanf("%d %d", &n, &k);

	queue <int> q;
	q.push(n);
	check[n] = true;
	dist[n] = 0;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (now - 1 >= 0) {
			if (check[now - 1] == false) {
				q.push(now - 1);
				check[now - 1] = true;
				dist[now - 1] = dist[now] + 1;
			}

		}
		
		if (now + 1 <= 1000000) {
			if (check[now + 1] == false) {
				q.push(now + 1);
				check[now + 1] = true;
				dist[now + 1] = dist[now] + 1;
			}
		}

		if (now * 2 <= 1000000) {
			if (check[now * 2] == false) {
				q.push(now * 2);
				check[now * 2] = true;
				dist[now * 2] = dist[now] + 1;
;			}
		}

	}
	
	printf("%d", dist[k]);
	
}
