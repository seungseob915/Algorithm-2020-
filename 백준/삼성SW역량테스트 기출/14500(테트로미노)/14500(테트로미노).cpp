// 14500(테트로미노).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;

int a[501][501];
int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    int ans = 0;
   
    //ㅣ,ㅡ탐색
    for (int i = 0; i < n - 3; i++)
        for (int j = 0; j < m; j++) {
            int temp = a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i + 3][j];
            if (ans < temp)
                ans = temp;
        }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m-3; j++) {
            int temp = a[i][j] + a[i][j+1] + a[i][j+2] + a[i][j+3];
            if (ans < temp)
                ans = temp;
        }

    //ㅜ,ㅏ,ㅗ,ㅓ탐색
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < m-2; j++) {
            int temp = a[i][j] + a[i][j+1] + a[i][j+2] + a[i + 1][j+1];
            if (ans < temp)
                ans = temp;
        }

    for (int i = 0; i < n - 2; i++)
        for (int j = 0; j < m - 1; j++) {
            int temp = a[i][j] + a[i+1][j] + a[i+2][j] + a[i + 1][j + 1];
            if (ans < temp)
                ans = temp;
        }

    for (int i = 0 ; i < n - 1; i++)
        for (int j = 1; j < m - 1; j++) {
            int temp = a[i][j] + a[i + 1][j] + a[i + 1][j-1] + a[i + 1][j + 1];
            if (ans < temp)
                ans = temp;
        }

    for (int i = 1; i < n - 1; i++)
        for (int j = 0; j < m - 1; j++) {
            int temp = a[i][j] + a[i - 1][j+1] + a[i][j+1] + a[i + 1][j + 1];
            if (ans < temp)
                ans = temp;
        }

    //ㄹ탐색
    for (int i = 0; i < n - 2; i++)
        for (int j = 0; j < m - 1; j++) {
            int temp = a[i][j] + a[i+1][j] + a[i+1][j+1] + a[i + 2][j + 1];
            if (ans < temp)
                ans = temp;
        }
    
    for (int i = 1; i < n; i++)
        for (int j = 0; j < m - 2; j++) {
            int temp = a[i][j] + a[i][j+1] + a[i - 1][j + 1] + a[i - 1][j + 2];
            if (ans < temp)
                ans = temp;
        }

    for (int i = 2; i < n; i++)
        for (int j = 0; j < m - 1; j++) {
            int temp = a[i][j] + a[i-1][j] + a[i-1][j + 1] + a[i - 2][j + 1];
            if (ans < temp)
                ans = temp;
        }

    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < m - 2; j++) {
            int temp = a[i][j] + a[i][j + 1] + a[i + 1][j + 1] + a[i + 1][j + 2];
            if (ans < temp)
                ans = temp;
        }
  
    //L 형
    for (int i = 0; i < n - 2; i++)
        for (int j = 0; j < m - 1; j++) {
            int temp = a[i][j] + a[i+1][j] + a[i + 2][j] + a[i + 2][j + 1];
            if (ans < temp)
                ans = temp;
        }
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < m - 2; j++) {
            int temp = a[i][j] + a[i + 1][j] + a[i][j+1] + a[i][j + 2];
            if (ans < temp)
                ans = temp;
        }
    for (int i = 0; i < n - 2; i++)
        for (int j = 0; j < m - 1; j++) {
            int temp = a[i][j] + a[i][j+1] + a[i+1][j + 1] + a[i+2][j + 1];
            if (ans < temp)
                ans = temp;
        }
    for (int i = 1; i < n; i++)
        for (int j = 0; j < m - 2; j++) {
            int temp = a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i - 1][j + 2];
            if (ans < temp)
                ans = temp;
        }
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < m - 2; j++) {
            int temp = a[i][j] + a[i+1][j] + a[i+1][j + 1] + a[i +1][j + 2];
            if (ans < temp)
                ans = temp;
        }
    for (int i = 0; i < n - 2; i++)
        for (int j = 0; j < m - 1; j++) {
            int temp = a[i][j] + a[i][j+1] + a[i + 1][j] + a[i + 2][j];
            if (ans < temp)
                ans = temp;
        }
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < m - 2; j++) {
            int temp = a[i][j] + a[i][j+1] + a[i][j+2] + a[i + 1][j+2];
            if (ans < temp)
                ans = temp;
        }
    for (int i = 2; i < n; i++)
        for (int j = 0; j < m - 1; j++) {
            int temp = a[i][j] + a[i][j + 1] + a[i - 1][j+1] + a[i - 2][j+1];
            if (ans < temp)
                ans = temp;
        }
    //ㅁ탐색
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < m - 1; j++) {
            int temp = a[i][j] + a[i+1][j + 1] + a[i][j + 1] + a[i +1][j];
            if (ans < temp)
                ans = temp;
        }

    cout << ans << "\n";

    return 0;
}
