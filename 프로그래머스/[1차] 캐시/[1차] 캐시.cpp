// [1차] 캐시.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int cacheSize;      //캐시 사이즈
int time = 0;       //시간 0으로 초기화
vector <string> cities; //입력 대기열
queue <string> wait;    //대기 큐 생성
vector <string> cache;  //캐시 백터 생성

//대문자를 소문자로 바꾸기
void letter_change(string &str) {
    int gap = 32;
    for (int i = 0; i < str.size(); i++)
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += gap;
}

// 벡터 내부 최신화 함수
void cache_push(string temp){
    // 만약 벡터가 비어있다면 넣어라
    if (cache.size() < cacheSize)
        cache.push_back(temp);

    //만약 꽉차있다면
    else if (cache.size() == cacheSize) {
        //벡터 내부 바꾸는 함수
        for (int i = 0; i < cache.size() - 1; i++)
            cache[i] = cache[i + 1];
        cache[cache.size() - 1] = temp;
    }
}

// 벡터 내부 최신화 함수
void cache_change(string temp) {
    // temp의 위치 찾기
    int x;
    for (int i = 0; i < cache.size(); i++) {
        if (temp == cache[i]) {
            x = i;
            break;
        }
    }

    for (int i = x; i < cache.size() - 1; i++)
        cache[i] = cache[i + 1];
    cache[cache.size() - 1] = temp;
    
    return;
}



//원소의 중복여부 확인 후 시간 추가
void check_double(string temp) {
    for (int i = 0; i < cache.size(); i++) {
        //중복된 원소가 있다면
        if (temp == cache[i]) {
            time += 1;
            cache_change(temp);
            return;
        }
    }

    //중복된 원소가 없다면 시간 5 추가 및 Cache에 삽입 및 삭제
    time += 5;
    cache_push(temp);
}



int main()
{
    cin >> cacheSize;

    int t = 4;

    //도시 입력
    while (t--) {
        string temp;
        cin >> temp;
        cities.push_back(temp);
    }

    //cachesize가 0일때 종료
    if (cacheSize == 0) {
        for (int i = 0; i < cities.size(); i++)
            time += 5;
        cout << time;
        return 0;
    }

    //문자를 대문자에서 소문자로 일괄 변경
    for (int i = 0; i < cities.size(); i++)
        letter_change(cities[i]);


    //벡터에 입력되어있는 정보를 대기 큐로 옮기자
    for (int i = 0; i < cities.size(); i++)
        wait.push(cities[i]);

    //대기큐에 정보가 있는 동안
    while (!wait.empty()) {
        // 대기큐에 있는 값 임시로 저장
        string temp = wait.front();
        wait.pop();
        
        check_double(temp);
    }

    cout << time;
    return 0;
}
