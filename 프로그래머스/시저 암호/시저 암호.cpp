// 시저 암호.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>

using namespace std;


string solution(string s, int n) {
    string answer = "";

    int length = s.size();
    int ln = n % 26;        //알파벳 26개

    for (int i = 0; i < length; i++) {
        int temp = ln + s[i];
        if (s[i] == ' ') {
            answer.append(" ");
            continue;
        }
        
            // 대문자일때
            if (temp>'Z' && s[i] >= 'A' && s[i] <= 'Z') {
                int gap = temp - 'Z';
                char ans = gap + 'A' - 1;
                answer += ans;
            }
            //소문자일 때
            else if (temp>'z' && s[i] >= 'a' && s[i] <= 'z') {
                int gap = temp - 'z';
                char ans = gap + 'a' - 1;
                answer += ans;
            }
            else {
                answer += s[i] + n;
            }
    }
    return answer;
}

int main()
{
    string s;
    cin >> s;
    string a=solution(s, 1);
    cout << a;
}
