#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";

    int day = 0;
    int m_d[] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
    string dow[7] = { "FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU" };

    //월 처리
    for (int i = 0; i < a - 1; i++) {
        day += m_d[i];
    }
    //일 처리
    day += b;

    answer = dow[(day - 1) % 7];
    return answer;
}