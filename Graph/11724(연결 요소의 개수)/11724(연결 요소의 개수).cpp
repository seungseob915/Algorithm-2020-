// 11724(연결 요소의 개수).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.


#include <iostream>
#include <vector>

using namespace std;
bool check[1001];
vector <int> nlist[1001];
int cnt = 0;

void dfs(int);

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        nlist[u].emplace_back(v);
        nlist[v].emplace_back(u);
    }
    
    for (int i = 1; i <= n; i++) {
        if (check[i] == false) {
            dfs(i);
            cnt++;
        }
     }

    printf("%d", cnt);
    return 0;  
}


void dfs(int node) {
    check[node] = true;
    for (int i = 0; i < nlist[node].size(); i++) {
        int next = nlist[node][i];
        if (check[next] == false)
            dfs(next);
    }
}
