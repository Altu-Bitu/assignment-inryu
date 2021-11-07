/*
 * 녹색 옷 입은 애가 젤다지? : https://www.acmicpc.net/problem/4485
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n;
const int MAX = 2147000000;
vector<vector<int>> map;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

struct Loc {
    int w; //가중치 (도둑루피 크기)
    int r; //행 좌표
    int c; //열 좌표

    Loc(int ww, int rr, int cc) {
        w = ww;
        r = rr;
        c = cc;
    }

    bool operator<(const Loc &b) const {
        return w > b.w; //내림차순 (최소힙)
    }
};

int dijkstra(int r, int c, vector<vector<int>> &map) {
    vector<vector<int>> dist(n, vector<int>(n, MAX)); // 초기엔 최대값으로
    priority_queue<Loc> pq;

    //시작 위치 초기화 (r=0,c=0)
    pq.push(Loc(map[r][c], r, c));
    dist[r][c] = map[r][c];
    while (!pq.empty()) {
        int cur_w = pq.top().w;
        int cur_r = pq.top().r;
        int cur_c = pq.top().c;
        pq.pop();
        //if (cur_w > dist[cur_r][cur_c]) continue; //이미 확인했던 정점
        for (int d = 0; d < 4; d++) {
            int nr = cur_r + dr[d];
            int nc = cur_c + dc[d];
            if (nr < 0 || nr > n - 1 || nc < 0 || nc > n - 1) continue;
            int nw = cur_w + map[nr][nc]; //연결된 정점까지의 거리
            if (dist[nr][nc] > nw) { //더 짧은 경로로 갈 수 있으면
                dist[nr][nc] = nw;
                pq.push(Loc(nw, nr, nc));
            }
        }
    }
    return dist[n - 1][n - 1];
}

int main() {
    int stage = 1;
    while (true) {
        cin >> n;
        if (n == 0) break;
        map.assign(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> map[i][j];
            }
        }
        cout << "Problem " << stage++ << ": " << dijkstra(0, 0, map) << "\n";
    }

}