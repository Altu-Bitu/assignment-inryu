/*
 * 아기상어 : https://www.acmicpc.net/problem/16236
 */

//이전에 풀이 참고하고 풀어봤었던 문제입니다.
#include<iostream>
#include<queue>

using namespace std;
int map[21][21], ch[21][21];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

struct State {
    int r, c, dis;

    State(int a, int b, int d) { //아기상어 움직이는 상황 (좌표, 출발한 곳에서부터 거리)
        r = a;
        c = b;
        dis = d;
    }

    bool operator<(const State &b) const {
        if (dis != b.dis) return dis > b.dis; //거리가 같지 않으면 거리 기준으로 최소힙
        if (r != b.r) return r > b.r; //거리가 같으면, x좌표가 다르면 x(행)기준으로 위에꺼가 탑으로
        else return c > b.c; //거리가 같은데 x도 같으면 열이 작은 걸로 (왼쪽)
    }
};

struct Shark {
    int r, c, s, ate; //심바의 상태 (출발점의 위치, 몸집 크기, 먹은 회수)
    void sizeUp() {
        ate = 0;
        s++;
    }
};

int main() {
    int n, i, j, res = 0;
    priority_queue<State> Q;
    Shark baby;
    cin >> n;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cin >> map[i][j];
            if (map[i][j] == 9) { //아기상어 위치
                baby.r = i;
                baby.c = j;
                map[i][j] = 0;
            }
        }
    }
    Q.push(State(baby.r, baby.c, 0)); //심바의 위치, 거리
    baby.s = 2;
    baby.ate = 0;

    while (!Q.empty()) {
        State tmp = Q.top();
        Q.pop();

        int r = tmp.r;
        int c = tmp.c;
        int z = tmp.dis;

        //잡아 먹을 수 있는지
        if (map[r][c] != 0 && map[r][c] < baby.s) {
            baby.r = r;
            baby.c = c;
            baby.ate++;
            if (baby.ate >= baby.s) baby.sizeUp();
            map[r][c] = 0; //잡아 먹었으니까

            for (i = 1; i <= n; i++) {
                for (j = 1; j <= n; j++) {
                    ch[i][j] = 0; //체크 배열 초기화 //아기상어 새로운 위치에서 다시 퍼져야 하니깐
                }
            }

            //다시 출발해야하니깐
            while (!Q.empty()) Q.pop(); //큐도 다 비워줌다.

            //현재까지 움직인 거리..
            res = tmp.dis;
        }

        //아기상어 위치에서 퍼져 나가기
        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];

            //좌표가 경계를 벗어나고, simba 사이즈보다 크고... 방문을 했음
            if (nr < 1 || nr > n || nc < 1 || nc > n || map[nr][nc] > baby.s || ch[nr][nc] > 0) continue;

            //아니라면
            Q.push(State(nr, nc, z + 1)); //출발점에서 dis++
            ch[nr][nc] = 1;
            //방문
        }
    }
    cout << res << "\n";
    return 0;
}