// [모의 SW 역량테스트] 원자 소멸 시뮬레이션.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

typedef struct Atom {
    int y, x, dir, k;   //y, x순
}A;

int N, T, Tcnt = 1;
int check[4001][4001] = {};

vector <A> atom;

int dy[] = { 1, -1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };


int main() {
    cin >> T;


    while (T--) {

        cin >> N;

        atom.clear();
        for (int i = 0; i < N; i++) {
            int ty, tx, tdir, tk;
            cin >> tx >> ty >> tdir >> tk;
            atom.push_back({ 2*(ty + 1000), 2*(tx + 1000), tdir, tk });
        }

        int now_atom = N;
        int total = 0;

        while (1) {
            //memset(check, 0, sizeof(check));
            bool finish = true;

            for (int i = 0; i < atom.size(); i++) {
                if (atom[i].k != 0) {
                    finish = false;
                }
            }

            if (finish)
                break;

            //1초
            for (int i = 0; i < N; i++) {
                A now = atom[i];

                if (atom[i].k == 0) {
                    continue;
                }

                // 우선 구조체 정보만 옮기고 다 끝난
                now.y += dy[now.dir];
                now.x += dx[now.dir];

                // 1초후 범위가 영역밖이면 끝
                if (now.y < 0 || now.y > 2000 || now.x < 0 || now.x>2000) {
                    atom[i].k = 0;
                    continue;
                }

                // 위치 최신화
                atom[i].y = now.y;
                atom[i].x = now.x;

                // 체크배열에 i번째 인덱스 넣기
                check[now.y][now.x]++;
            }

            // 주소 저장된 곳만 탐색하자
            for (int i = 0; i < atom.size(); i++) {
                // 저장된 인덱스가 2개이상이면 (충돌했으면)
                if (check[atom[i].y][atom[i].x] >= 2) {
                    for (int j = 0; j < atom.size(); j++) {
                        if (atom[j].k != 0 && atom[i].y == atom[j].y && atom[i].x == atom[j].x) {
                            total += atom[j].k;
                            atom[j].k = 0;
                        }
                    }
                }
                check[atom[i].y][atom[i].x] = 0;
            }
        }
        cout << "#" << Tcnt++ << " " << total << endl;
    }
}