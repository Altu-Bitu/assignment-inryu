/*
 * 감시 : https://www.acmicpc.net/problem/15683
 */
#include <iostream>
#include <vector>
//이전에 스터디에서 다른 분이 구글링참고해서

using namespace std;

int direction_size[5] = {4, 2, 4, 4, 1}; //각 방향마다 몇번 돌려야 하는지 //로테이션 개수 벡터
// 예를 들면 1번은 4번 돌려야하고, 2번은 2번만 돌리면 나머지는 동일함.
int map[9][9];
int ans = 2137000000;
vector<pair<int, int>> cctv;
int n, m;

//b를 a에 복사
void copyMap(int a[9][9], int b[9][9]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = b[i][j];
        }
    }
}

// 방향으로 뻗어서 보기
void observe(int dir, int r, int c) {
    int d = dir % 4;
    if (d == 0) { //상
        for (int nr = r - 1; nr >= 0; nr--) {
            if (map[nr][c] == 6) break;
            if (map[nr][c] >= 1 && map[nr][c] <= 5) continue;
            map[nr][c] = -1;
        }
    } else if (d == 1) { //우
        for (int nc = c + 1; nc < m; nc++) {
            if (map[r][nc] == 6) break;
            if (map[r][nc] >= 1 && map[r][nc] <= 5) continue;

            map[r][nc] = -1;
        }
    } else if (d == 2) { //하
        for (int nr = r + 1; nr < n; nr++) {
            if (map[nr][c] == 6) break;
            if (map[nr][c] >= 1 && map[nr][c] <= 5) continue;

            map[nr][c] = -1;
        }
    } else if (d == 3) { //좌
        for (int nc = c - 1; nc >= 0; nc--) {
            if (map[r][nc] == 6) break;
            if (map[r][nc] >= 1 && map[r][nc] <= 5) continue;
            map[r][nc] = -1;
        }
    }

}

//모든 경우의 수 dfs
void dfs(int level) {
    //모든 cctv를 본 경우
    if (level == cctv.size()) { //최소 사각지대 개수 계산
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 0)
                    cnt++;
            }
        }
        ans = min(ans, cnt);
        return;
    }

    int tmp[9][9];
    //cctv번호 : -1로 해서 로테이션 횟수 벡터 이용하기
    int cctv_type = map[cctv[level].first][cctv[level].second] - 1;
//    cout << "cctv_type : " << cctv_type << "\n";
    for (int d = 0; d < direction_size[cctv_type]; d++) { //각 cctv 타입마다, 돌려야 하는 횟수를 지정해놓음
        copyMap(tmp, map);
        //type에 따라 감시하기
        switch (cctv_type) {
            case 0: //1번 cctv
                observe(d, cctv[level].first, cctv[level].second); //방향, cctv 정보
                break;
            case 1:  //2번 cctv : 한 방향과 그 방향에서 +2한 방향이 한 묶음
                observe(d, cctv[level].first, cctv[level].second); //방향, cctv 정보
                observe(d + 2, cctv[level].first, cctv[level].second); //방향, cctv 정보
                break;
            case 2:  //3번 cctv : 한 방향과, 그 방향 +1 방향이 한 묶음
                observe(d, cctv[level].first, cctv[level].second); //방향, cctv 정보
                observe(d + 1, cctv[level].first, cctv[level].second); //방향, cctv 정보
                break;
            case 3: // 한 방향, +1, +2 방향이 한 묶음
                observe(d, cctv[level].first, cctv[level].second); //방향, cctv 정보
                observe(d + 1, cctv[level].first, cctv[level].second); //방향, cctv 정보
                observe(d + 2, cctv[level].first, cctv[level].second); //방향, cctv 정보
                break;
            case 4: //모든 방향이 한 묶음
                observe(d, cctv[level].first, cctv[level].second); //방향, cctv 정보
                observe(d + 1, cctv[level].first, cctv[level].second); //방향, cctv 정보
                observe(d + 2, cctv[level].first, cctv[level].second); //방향, cctv 정보
                observe(d + 3, cctv[level].first, cctv[level].second); //방향, cctv 정보
                break;
        }
        dfs(level + 1); //다음 cctv
        copyMap(map, tmp); //백트래킹!
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] >= 1 && map[i][j] <= 5)
                cctv.push_back({i, j});
        }
    }
    dfs(0);
    cout << ans << "\n";
}