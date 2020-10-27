// 울타리 잘라내기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int C;
long ans = -987654321;
vector<long> flr;

void Init() {
    ans = -987654321;
    flr.clear();
}

void simulate(int left, int right) {
    if (left == right) {
        ans = max(ans, flr[left]);
        return;
    }

    int mid = (left + right) / 2;

    simulate(left, mid);
    simulate(mid+1, right);

    //중앙 비교
    ans = max(ans, flr[mid]);
    int tl = mid;
    int tr = mid + 1;

    long th = min(flr[tl], flr[tr]);
    ans = max(ans, 2*th);
    while (tl > left || tr < right) {
        if (tr < right && (tl == left || flr[tl-1] < flr[tr+1])) {
            tr++;
            th = min(th, flr[tr]);
        }
        else {
            tl--;
            th = min(th, flr[tl]);
        }
        ans = max(ans, (tr - tl + 1) * th);
    }
}

int main()
{
    cin >> C;

    while (C--) {
        Init();
        
        int N;
        cin >> N;

        for (int i = 0; i < N; i++) {
            int temp;
            cin >> temp;
            flr.push_back(temp);
        }
        simulate(0, N - 1);
        cout << ans << endl;
    }
}
