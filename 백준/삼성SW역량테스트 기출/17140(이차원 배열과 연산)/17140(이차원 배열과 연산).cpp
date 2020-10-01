// 17140(이차원 배열과 연산).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int r, c, k, ans;
int now_r, now_c, prev_r, prev_c;
int a[101][101];

void do_R(int y) {
    int cnt[101] = { 0, };

      for (int j = 1; j <= prev_c; ++j) {
            // 숫자별 갯수 찾기
                 cnt[a[y][j]] += 1;
    }
    int temp = 0;

    //배열 재정렬
    for(int i=1; i<=100 && temp<100; ++i)
        for (int j = 1; j <= 100 && temp < 100;++j){
            if (cnt[j] == i) {
                a[y][++temp] = j;
                a[y][++temp] = i;
            }
        }

    //나머지 칸들은 배열 크기에 맞춰 0 처리
    for (int i = temp + 1; i <= prev_c; ++i) {
        a[y][i] = 0;
    }

    // 배열 크기 최신화
    if (now_c < temp)
    {
        now_c = temp;
    }
}

void do_C(int x) {
    int cnt[101] = { 0, };

    for (int i = 1; i <= prev_r; ++i)
            // 숫자별 갯수 찾기
            cnt[a[i][x]] += 1;
        
    int temp = 0;

    //배열 재정렬
    for (int i = 1; i <= 100 && temp < 100; ++i)
        for (int j = 1; j <= 100 && temp < 100; ++j) {
            if (cnt[j] == i) {
                a[++temp][x] = j;
                a[++temp][x] = i;
            }
        }

    //나머지 칸들은 배열 크기에 맞춰 0 처리
    for (int i = temp + 1; i <= prev_r; ++i) {
        a[i][x] = 0;
    }

    // 배열 크기 최신화
    if (now_r < temp)
    {
        now_r = temp;
    }
}

void solve() {
    // r,c 가 k가 아닐때 동안 무한 루프
    while (a[r][c]!=k) {
        //행>=열: R연산
        if (now_r >= now_c) {
            prev_c = now_c;
            now_c = 0;
            for(int i=1; i<=now_r;++i)
                do_R(i);
        }

        //행<열: C연산
        else {
                prev_r = now_r;
                now_r = 0;
                for (int i = 1; i <= now_c; ++i)
                    do_C(i);
        }
        ans += 1;
        if (ans > 100)
            break;
    }
}

int main()
{
    prev_c = 3;
    prev_r = 3;
    now_c = 3;
    now_r = 3;
    cin >> r >> c >> k;

    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
            cin >> a[i][j];

    ans = 0;

    solve();

    if (ans > 100)
        cout << "-1";
    else
        cout << ans;

    return 0;

}