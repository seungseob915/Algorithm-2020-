// 14500(테트로미노).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
using namespace std;

int map[501][501];

int findResult(int**, int, int);

int main()
{
    int n, m;  
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> map[i][j];

}

int findResult(int arr[][], int n, int m) {
    
    int sum=0, result=0;
    //1. 1자
    for (int i = 1; i <= n - 3; i++)
        for (int j = i; j <= i + 3; j++) {
            for (int k = 1; k <= m; k++) {
                sum += arr[j][k];
            }
            result = max(result, sum);
            sum = 0;
        }
    
    //2. ㅡ자
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m-3; j++) {
            for (int k = j; k <= j+3; k++) {
                sum += arr[i][k];
            }
            result = max(result, sum);
            sum = 0;
        }

    //3. ㅁ자
    for (int i = 1; i <= n-1; i++)
        for (int k = 1; k <= m - 1; k++) {
            for (int j = i; j <= i + 1; j++) {
                for (int l = k; l <= k + 1; l++) {
                    sum += arr[j][k];
                }
            }
            result = max(result, sum);
            sum = 0;
        }


}
