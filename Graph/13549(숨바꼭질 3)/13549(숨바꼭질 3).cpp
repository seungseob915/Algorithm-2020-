// 13549(숨바꼭질 3).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include <deque>
using namespace std;
bool check[1000000];
int time[1000000];

int main()
{
    int n, k;
    cin >> n >> k;
    check[n] = true;
    time[n] = 0;

    deque<int> q;
    q.push_back(n);

    while (!q.empty()) {    //0초걸릴 때는 현재 시간과 같으므로, 큐의 맨 앞에 넣어줌
        int now = q.front();
        q.pop_front();
        if (now * 2 < 1000000) {
            if (check[now * 2] == false) {
                q.push_front(now * 2);
                check[now * 2] = true;
                time[now * 2] = time[now];
            }
            if(now+1 <= 1000000)
                if (check[now + 1] == false) {
                    q.push_back(now + 1);
                    check[now + 1] = true;
                    time[now + 1] = time[now] + 1;
                }
            if (now -1 >= 0)
                if (check[now - 1] == false) {
                    q.push_back(now - 1);
                    check[now -1] = true;
                    time[now - 1] = time[now] + 1;
                }
        }
    }
    printf("%d\n", time[k]);
    return 0;
}
