// 1759(암호 만들기).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int l, c, jaeum=0, moeum=0;
    bool check=false;
    cin >> l;
    cin >> c;


    vector<char> a(c);
    vector<int> com(c, 0);

    for (int i = 0; i < c; i++)
        cin >> a[i];
    
    for (int i = 0; i < c; i++)      
        if(i<l)
            com[i] = 1;
   
    sort(a.begin(), a.end());

    do {
        for (int i = 0; i < com.size(); i++) {
            if (com[i] == 1) {
                if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u')
                    moeum++;
                else
                    jaeum++;
            }
        }
        if (moeum >= 1 && jaeum >= 2)
            check = true;
        else
            check = false;
        moeum = 0;
        jaeum = 0;

        if (check) {
            for (int i = 0; i < c; i++) {
                if (com[i] == 1)
                    cout << a[i];
            }
            cout << "\n";
        }
    } while (prev_permutation(com.begin(), com.end()));
    
    return 0;
}
