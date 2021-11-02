/*
 * 섬의 개 : https://www.acmicpc.net/problem/4963
 */
#include <iostream>
#include <vector>

using namespace std;

int w, h;
vector<vector<int>> map;
vector<vector<bool>> visited;

///대각선까지
int dr[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dc[8] = {0, 1, 0, -1, -1, 1, -1, 1};

//dfs
void findLand(int r, int c) {
    visited[r][c] = true;
    for (int d = 0; d < 8; d++) {
        int nr = r + dr[d];
        int nc = c + dc[d];
        if (nr < 0 || nr > h - 1 || nc < 0 || nc > w - 1 || !map[nr][nc] || visited[nr][nc]) continue;
        findLand(nr, nc);
    }
}

int main() {
    while (true) {
        int ans = 0;

        cin >> w >> h;
        map.assign(h, vector<int>(w, 0));
        visited.assign(h, vector<bool>(w, false));
        if (!w && !h) break; //마지막 입력

        //map input
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> map[i][j];
            }
        }

        //dfs
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (map[i][j] && !visited[i][j]) {
                    findLand(i, j);
                    ans++;
                }
            }
        }
        cout << ans << "\n";

    }

}