/*
 * 테트로미노 : https://www.acmicpc.net/problem/1448
 */

/*
 * 이전에 구글링 참고해서 풀었던 문제를 기억해서 푼 것이라 정확히 참고 링크는 없지만 구글링 풀이 참고했습니다!
 */
#include <iostream>
#include <algorithm>

using namespace std;

int map[500][500];
int ch[500][500]; // 0: false , 1 : true
int ans = -2147000000;//최대값 구하기

int dr[4] = {0, 1, 0, -1}; //상우하좌
int dc[4] = {-1, 0, 1, 0};
int n, m;

//1. map을 한 칸 씩 순회하면서 최대값 찾기
//2. 이때 4개 모양은 DFS로 가능, ㅗ 모양은 따로


// ㅗ 모양 제외 4가지 모양 검사
void dfs(int level, int r, int c, int sum) {
    if (level == 3) {
        ans = max(ans, sum); //max 값 업데이트
    } else {
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m || ch[nr][nc]) continue;

            ch[nr][nc] = 1;
            dfs(level + 1, nr, nc, sum + map[nr][nc]);
            ch[nr][nc] = 0;
        }
    }

}

//ㅗ 모양 검사
void check_last(int r, int c) { //행 (n) 열 (y) 주의

    //ㅗ
    if (r - 1 >= 0 && c - 1 >= 0 && c + 1 <= m - 1) {
        ans = max(ans, map[r][c] + map[r - 1][c] + map[r][c - 1] + map[r][c + 1]);
    }

    //ㅏ
    if (r - 1 >= 0 && r + 1 <= n - 1 && c + 1 <= m - 1) {
        ans = max(ans, map[r][c] + map[r - 1][c] + map[r + 1][c] + map[r][c + 1]);
    }

    //ㅜ
    if (c - 1 >= 0 && c + 1 <= m - 1 && r + 1 <= n - 1) {
        ans = max(ans, map[r][c] + map[r][c - 1] + map[r][c + 1] + map[r + 1][c]);
    }

    //ㅓ
    if (c - 1 >= 0 && r - 1 >= 0 && r + 1 <= n - 1) {
        ans = max(ans, map[r][c] + map[r - 1][c] + map[r + 1][c] + map[r][c - 1]);
    }

}


int main() {

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    //map을 순회하면서 검사
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            //1) DFS로 4가지 모양 검사
            ch[i][j] = 1; //방문체크
            dfs(0, i, j, map[i][j]); //레벨 0부터 시작
            ch[i][j] = 0;

            //2) ㅗ 모양 검사
            check_last(i, j);
        }
    }

    cout << ans;

    return 0;

}