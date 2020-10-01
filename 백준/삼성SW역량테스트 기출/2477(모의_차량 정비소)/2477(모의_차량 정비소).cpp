// 2477(모의_차량 정비소).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int n, m, k, aa, bb; //접수창구, 정비창구, 고객 수, 접수창구번호, 정비창구번호
int a[9], b[9];
int t[1000];
pair <int, int> info[1000]; //a번호, b 번호

void solve() {
    int time = 0;
    int atime[1000];
    int btime[1000];
    int ause[9] = { 0, };
    int buse[9] = { 0, };
    memset(atime, -1, sizeof(atime));
    memset(btime, -1, sizeof(btime));
    memset(ause, -1, sizeof(ause));
    memset(buse, -1, sizeof(buse));

    priority_queue <pair<pair<int, int>, int>, vector< pair<pair<int, int>, int>>, greater <pair<pair<int, int>, int> >> bwaiting;
    //우선 순위는 time, A번호, 고객번호 순

    int cnt = 0;
    while (1) {
        if (cnt == k)
            break;

        for (int i = 0; i < k; i++) {
            if (t[i] != 0)
                t[i]--;
            else if (t[i] == 0) {
                for(int j=0; j<n; j++)
            }
        }
    }
}

int main()
{
    int tcc;
    cin >> tcc;
    for (int tc = 1; tc <= tcc; tc++) {
        cin >> n >> m >> k >> aa >> bb;
        
        for (int i = 0; i < n; i++)
            cin >> a[i]; 
        for (int i = 0; i < m; i++)
            cin >> b[i];
        for (int i = 0; i < k; i++)
            cin >> t[i];

        solve();

    }
}

