// 14226(이모티콘).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

int s, c, n;
int time[1001][1001];

int main()
{
    scanf("%d", &n);

    memset(time, -1, sizeof(time));

    queue <pair<int, int>> q;
    q.push(make_pair(1, 0));
    time[1][0] = 0;

    while (!q.empty()) {
        tie(s, c) = q.front();
        q.pop();

        if (time[s][s] == -1) {
            time[s][s] = time[s][c] + 1;
            q.push(make_pair(s, s));
        }
        if (s + c <= n && time[s + c][c] == -1) {      // 먼저 s+c<=n 조건을 실행시켜야 실행시간 단축
            time[s + c][c] = time[s][c] + 1;
            q.push(make_pair(s + c, c));
        }
        if (s - 1 >= 0 && time[s - 1][c] == -1) {
            time[s - 1][c] = time[s][c] + 1;
            q.push(make_pair(s - 1, c));
        }
    }
    int ans = -1;
    for (int i = 0; i <= n; i++) {
        if (time[n][i] != -1 && ans == -1 || ans > time[n][i]) {
            ans = time[n][i];
        }
    }
    printf("%d\n", ans);
    return 0;
}
