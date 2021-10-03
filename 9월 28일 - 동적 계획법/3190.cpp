#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k, l;
vector<vector<int>> board;
vector<vector<bool>> visited;
queue<pair<int, char>> moves;
queue<pair<int, char>> tail; //꼬리

//방향 오른쪽, 아래, 왼쪽, 위쪽
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};
int cur_dir = 0; //처음엔 오른쪽방향 (방향벡터의 인덱스)
int cur_r = 1; //처음 위치
int cur_c = 1;

//time초에 이동.
bool moveSnake(int r, int c, int time) {
    //이동할 칸
    int nr = r + dr[cur_dir];
    int nc = c + dc[cur_dir];
    //벽에 부딪히거나 자기자신 몸과 부딪히면
    if (nr > n || nc > n || nr < 1 || nc < 1 || visited[nr][nc]) {
        return false;
    }
    //이동
    tail.push({nr, nc});
    visited[nr][nc] = true;
    cur_r = nr;
    cur_c = nc;

    if (board[nr][nc] == 1) { //사과가 있다면
        board[nr][nc] = 0; // 사과를 없애준다.
    } else { //없다면
        int tr = tail.front().first;
        int tc = tail.front().second;
        tail.pop();
        visited[tr][tc] = false; //꼬리가 위치한 칸의 뱀을 비워준다.
        //🌟처음엔 바로 전 칸을 지워서 틀림. // 꼬리 위치를 계속해서 큐에 담아줘야 함.
    }

    //뱀의 방향 변환이 필요한지
    if (moves.front().first == time) {
        if (moves.front().second == 'L') //왼쪽 회전
            cur_dir = (cur_dir + 3) % 4;
        else cur_dir = (cur_dir + 1) % 4; //오른쪽 회전
        moves.pop();
    }
    return true;
}


int main() {

    //입력
    cin >> n >> k;
    board.assign(n + 1, vector<int>(n + 1, 0)); //인덱스 1,1부터 시작 (사과)
    visited.assign(n + 1, vector<bool>(n + 1, 0)); //인덱스 1,1부터 (뱀)
    int r, c, time;
    char dir;
    for (int i = 0; i < k; i++) {
        cin >> r >> c;
        board[r][c] = 1; //사과
    }
    cin >> l;
    for (int i = 0; i < l; i++) {
        cin >> time >> dir;
        moves.push({time, dir});

    }

    int ans = 0;
    visited[1][1] = 1; //처음 뱀 위치
    tail.push({1, 1});
    while (true) {
        ans++;
        if (!moveSnake(cur_r, cur_c, ans)) {
            break;
        }
    }

    cout << ans << "\n";

}

