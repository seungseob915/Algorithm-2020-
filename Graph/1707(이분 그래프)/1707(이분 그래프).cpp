// 1707(이분 그래프).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;
vector<int> nlist[20001];
int color[20001];

bool dfs(int, int);
int main()
{
	int k;
	scanf("%d", &k);

	while (k--) {
		int v, e;
		scanf("%d %d", &v, &e);

		for (int i = 1; i <= v; i++) {
			nlist[i].clear();
			color[i] = 0;
		}
		for (int i = 0; i < e; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			nlist[u].emplace_back(v);
			nlist[v].emplace_back(u);
		}
		bool ok = true;
		for (int i = 1; i <= v; i++)
			if (color[i] == 0)
				if (dfs(i, 1) == false)
					ok = false;
		printf("%s\n", ok?"YES":"NO");
	}
	return 0;
}

//0: 아직안감, 1: 빨간, 2: 파랑
bool dfs(int node, int ncolor) {
	color[node] = ncolor; 
	for (int i = 0; i < nlist[node].size(); i++) {
		int next = nlist[node][i];
		if (color[next] == 0) {
			if (dfs(next, 3 - ncolor) == false)
				return false;
		}
		else if (color[next] == color[node])
			return false;
	}
	return true;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
