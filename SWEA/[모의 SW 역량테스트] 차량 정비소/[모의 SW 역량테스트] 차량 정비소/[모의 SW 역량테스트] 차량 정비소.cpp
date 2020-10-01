// [모의 SW 역량테스트] 차량 정비소.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

// 창구 데이터 저장
typedef struct Desk {
	int t, index;
}desk;

// 고객 데이터 저장
typedef struct Client {
	int n, arv_t, an, aft, bn, bft;
}c;

struct cmp1 {
	bool operator()(const c& c1, const c& c2) {
		return c1.n > c2.n;
	}
};


int N, M, K, A, B, T, Tcnt = 1;
desk a[10];
desk b[10];
c client[1001];

void Init() {
	memset(a, NULL, sizeof(a));
	memset(b, NULL, sizeof(b));
	memset(client, NULL, sizeof(client));
}

void simulate() {
	int time = 0;
	int finish_no = 0;

	priority_queue<c, vector<c>, cmp1> pq1;
	queue<c> pq2;

	//끝내는 조건은 뭘로할까? 끝나는애들 갯수세자
	while (1) {
		// 다 끝났으면 종료
		if (finish_no == K)	break;

		for (int i = 1; i <= K; i++) {
			if (time == client[i].arv_t) {
				pq1.push(client[i]);
			}
		}

		for (int i = 1; i <= N; i++) {
			// 접수 창구 내 0초인 놈이 있으면
			if (a[i].index != 0 && client[a[i].index].aft == 0) {
				pq2.push(client[a[i].index]);
				a[i].index = 0;
			}
		}

		// 비어있으면 넣자
		for (int i = 1; i <= N; i++) {
			if (a[i].index == 0 && !pq1.empty()) {
				a[i].index = pq1.top().n;
				pq1.pop();
				client[a[i].index].aft = a[i].t;
				client[a[i].index].an = i;
			}
		}

		// 정비소에 들어온 놈들중 bft==0인놈은 종료
		for (int i = 1; i <= M; i++) {
			if (b[i].index != 0 && client[b[i].index].bft == 0) {
				finish_no++;
				b[i].index = 0;
			}
		}

		// 정비소에 비어있으면 넣자
		for (int i = 1; i <= M; i++) {
			if (b[i].index == 0 && !pq2.empty()) {
				b[i].index = pq2.front().n;
				pq2.pop();
				client[b[i].index].bft = b[i].t;
				client[b[i].index].bn = i;
			}
		}

		for (int i = 1; i <= N; i++) {
			if (a[i].index != 0) {
				client[a[i].index].aft--;
			}
		}

		for (int i = 1; i <= M; i++) {
			if (b[i].index != 0) {
				client[b[i].index].bft--;
			}
		}
		time++;
	}
}

int main()
{
	cin >> T;

	while (T--) {
		Init();

		cin >> N >> M >> K >> A >> B;

		for (int i = 1; i <= N; i++) {
			int temp;
			cin >> temp;
			a[i] = { temp, 0 };
		}
		for (int i = 1; i <= M; i++) {
			int temp;
			cin >> temp;
			b[i] = { temp, 0 };
		}
		for (int i = 1; i <= K; i++) {
			int temp;
			cin >> temp;
			client[i] = { i, temp, 0, -1, 0, -1 };
		}

		simulate();
		int total = 0;

		for (int i = 1; i <= K; i++) {
			if (client[i].an == A && client[i].bn == B) {
				total += i;
			}
		}
		if (total == 0)
			total = -1;

		cout << "#" << Tcnt++ << " " << total << endl;
	}
}

