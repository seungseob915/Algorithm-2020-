// [모의 SW 역량테스트] 요리사.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <math.h>

using namespace std;

int N, T, Tcnt=1;
int S[17][17];
vector <int> order;

void Init() {
    memset(S, 0, sizeof(S));
    order.clear();
}

int main()
{
    cin >> T;
    
    while (T--) {
        Init();

        cin >> N;

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                cin >> S[i][j];
            }
        }
        int ans = 987654321;

        order.resize(N, 0);

        for (int i = 0; i < N / 2; i++)
            order[i] = 1;

        do {
            int t_a = 0;
            int t_b = 0;
            vector<int> A;  //1 인놈들
            vector<int> B;  //0 인놈들

            for (int i = 0; i < N; i++) {
                if (order[i] == 1) {
                    A.push_back(i + 1);
                }
                else {
                    B.push_back(i + 1);
                }
            }

            for (int i = 0; i < N / 2; i++) {
                for (int j = 0; j < N / 2; j++) {
                    if (i == j) {
                        continue;
                    }
                    t_a += S[A[i]][A[j]];
                    t_b += S[B[i]][B[j]];
                }
            }

            int t_ans = abs(t_a - t_b);
            ans = min(ans, t_ans);

        } while (prev_permutation(order.begin(), order.end()));

        cout << "#"<<Tcnt++<<" "<<ans<<endl;
    }
}