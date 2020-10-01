// 14889(스타트와 링크).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// do이후 벡터가 왜 안되는지 모르겠음....

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int main()
{   
    cin >> n;   // 전체 수

    vector<vector<int>> s(n, vector<int>(n));
    vector<int> comb(n);

    //능력치 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> s[i][j];
        }
    }

    for(int i=0; i<n; i++)
        comb[i]=0;  //순열 0으로 초기화
    
    //순열 i/2 개 1로 초기화
    for (int i = 0; i * 2 < n; i++)
        comb[i] = 1;        //0일때 스타트 , 1일때 링크

    sort(comb.begin(), comb.end());

    int mini=987654321;

    do {
        //점수 초기화
        int s_score = 0;
        int l_score = 0;


        // 사람별로 팀이 어딘지
        int s_team[101] = { 0, };
        int l_team[101] = { 0, };


        int cnts = 0;
        int cntl = 0;

        //순열에 따른 팀내 사람 지정
        for (int k = 0; k < n; k++) {
            if (comb[k] == 0) { //스타트 팀이면
                s_team[cnts++]=k;
            }
            else if(comb[k]==1){ //링크 팀이면
                l_team[cntl++] = k;
            }
        }


        for (int i = 0; 2 * i < n; i++) 
            for (int j = 0; 2 * j < n; j++) {
                if (i == j) {
                   continue;
                }
                s_score += s[s_team[i]][s_team[j]];
                l_score += s[l_team[i]][l_team[j]];
            }


        int temp = s_score - l_score;
        if (temp < 0)
            temp = -temp;

        mini = min(mini, temp);

    } while (next_permutation(comb.begin(), comb.end()));

    cout << mini << "\n";
    return 0;
}
