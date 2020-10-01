#include <iostream>
#include <queue>
using namespace std;

struct position {
    int b;
    int x;
    int y;
    int n;
    int d;
    position() {
        this->b = 0;
        this->x = 0;
        this->y = 0;
        this->n = 0;
        this->d = 0;
    }
    position(int b, int x, int y, int n, int d) {
        this->b = b;
        this->x = x;
        this->y = y;
        this->n = n;
        this->d = d;
    }
};

char map[11][11];
int chk[11][11];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

queue<position> q;

int main(void) {
    int N, M;
    cin >> N >> M;

    position hall;
    position red;
    position blue;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'O') {
                hall.x = i;   hall.y = j;   hall.n = 0;
                chk[i][j] = 100;
            }
            else if (map[i][j] == 'R') {
                red.x = i; red.y = j; red.b = 200;
                q.push(position(red.b, red.x, red.y, red.n, red.d));
                chk[i][j] = 200;
            }
            else if (map[i][j] == 'B') {
                blue.x = i;   blue.y = j; blue.b = 300;
                chk[i][j] = 300;
            }
            else if (map[i][j] == '#') {
                chk[i][j] = -1;
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (chk[i][j] == 100) cout << "@ ";
            else if (chk[i][j] == 200) cout << "R ";
            else if (chk[i][j] == 300) cout << "B ";
            else if (chk[i][j] == -1) cout << "# ";
            else cout << chk[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    bool result = true;
    int cnt = 0;
    while (!q.empty()) {
        cout << "큐 들어옴" << endl;
        position f = q.front();
        q.pop();
        int b = f.b;
        int x = f.x;
        int y = f.y;
        int n = f.n;
        int d = f.d;
        if (n > 10) {
            result = false;
            break;
        }
        if (hall.x == blue.x && hall.y == blue.y) {
            result = false;
            break;
        }
        if (x == hall.x && y == hall.y) {
            if (hall.x == (blue.x + dx[blue.d]) && hall.y == (blue.y + dy[blue.d])) {
                result = false;
                break;
            }
            result = true;
            cnt = n;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int mx = x + dx[i];
            int my = y + dy[i];
            int mn = n + 1;
            if (d == i && n > 0) mn = n;
            if (mx < 2 || my < 2 || mx > N - 1 || my > N - 1) continue;
            if (mx == hall.x && my == hall.y) {
                chk[mx][my] = b;
                q.push(position(b, mx, my, mn, i));
                //cout << " 큐 푸 시 : " << mx << " , " << my << " : " << mn << " / " << i << endl;
                continue;
            }
            if (map[mx][my] != '.') continue;
            if (chk[mx][my] != 0) continue;
            chk[mx][my] = b;
            q.push(position(b, mx, my, mn, i));
            int bx = blue.x + dx[i];
            int by = blue.y + dy[i];
            int bd = i;
            if (bx < 2 || by < 2 || bx > N - 1 || by > N - 1) continue;
            if (map[bx][by] != '.') continue;
            blue.x = bx; blue.y = by; blue.d = bd;

            cout << " 큐 푸 시 : " << mx << " , " << my << " : " << mn << " / " << i << endl;
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (chk[i][j] == 100) cout << "@ ";
                else if (chk[i][j] == 200) cout << "R ";
                else if (chk[i][j] == 300) cout << "B ";
                else if (chk[i][j] == -1) cout << "# ";
                else cout << chk[i][j] << " ";
            }
            cout << endl;
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (chk[i][j] == 100) cout << "@ ";
            else if (chk[i][j] == 200) cout << "R ";
            else if (chk[i][j] == 300) cout << "B ";
            else if (chk[i][j] == -1) cout << "# ";
            else cout << chk[i][j] << " ";
        }
        cout << endl;
    }

    if (result == true) cout << cnt;
    else cout << "-1";
}