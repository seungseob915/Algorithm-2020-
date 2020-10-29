// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <memory.h>
using namespace std;

string P;
string F;
int N;
int dp[101][101];

int match(int w, int s) {

    int ret = dp[w][s];
    if (ret != -1) return ret;

    while (s < F.size() && w < P.size() && P[w] == F[s]) {
        w++;
        s++;
    }

    if (w == P.size())
        return ret=(s == F.size());

    if(P[w]=='*')
        for (int skip = 0; s + skip <= F.size(); skip++) {
            if (match(w+1, s+skip)) {
                return ret=1;
            }
        }
    return ret=0;
}

int main()
{
    cin >> P;
    cin >> N;
    vector<string> ans;
    for (int i = 0; i < N; i++) {
        memset(dp, -1, sizeof(dp));
        cin >> F;
        if (match(0, 0) == 1)
            ans.push_back(F);
    }
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
}