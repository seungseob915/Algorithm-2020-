// 3752. 가능한 시험 점수.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include<memory.h>

using namespace std;

int N, T, Tcnt=1;
int score[101][2];		// 1번째는 점수, 2번째는 맞/틀 여부
vector <int> score_sum;

void total(int now, int t_score) {
	if (now == N) {
		score_sum.push_back(t_score);
		return;
	}
	
	for (int i = 0; i <= 1; i++) {
		score[now][1] = i;
		if (i) {
			total(now + 1, t_score + score[now][0]);
		}
		else {
			total(now + 1, t_score);
		}
	}
}

int main()
{
	cin >> T;

	while (T--) {
		cin >> N;

		score_sum.clear();
		memset(score, 0, sizeof(score));

		for (int i = 0; i < N; i++) {
			int temp;
			cin >> temp;
			score[i][0] = temp;
		}

		total(0, 0);

		sort(score_sum.begin(), score_sum.end());
		score_sum.erase(unique(score_sum.begin(), score_sum.end()), score_sum.end());

		int ans = score_sum.size();

		cout <<"#"<<Tcnt<<" "<< ans<<endl;
		Tcnt++;
	}
}
