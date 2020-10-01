// 체육복.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    map <int, int> re;

    int l_num = lost.size();
    int r_num = reserve.size();
    int now = n - l_num;

    //해쉬 초기화 모두 1벌씩 있는것으로
    for (int i = 1; i <= n; i++) {
        re[i] = 1;
    }

    //먼저 잃어버린놈들 0으로 처리
    for (int i = 0; i < l_num; i++) {
        re[lost[i]]--;
    }

    //여벌 있는놈들은 +1
    for (int i = 0; i < r_num; i++) {
        re[reserve[i]]++;
    }

    //빌려주기 시작(왼쪽부터 먼저 확인)
    for (int i = 1; i <= n; i++) {
        //없는놈 찾았을때
        if (re[i] == 0) {
            //왼쪽 확인
            if (i - 1 >= 1 && re[i-1]==2) {
                    re[i - 1]--;
                    re[i]++;
            }
            //오른쪽 확인
            else if (i + 1 <= n && re[i+1]==2) {
                    re[i + 1]--;
                    re[i]++;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        if (re[i] >= 1)
            answer++;
    return answer;
}

int main()
{

}
