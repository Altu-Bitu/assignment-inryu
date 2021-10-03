//외판원 순회
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> map;
vector<bool> visited;
int n, ans = 2147000000;


void dfs(int start, int now, int level, int sum) {

    if (sum >= ans) return; //✨ 풀이 참고. 더 계산해볼 것도 없다.

    if (level == n) {
        //다시 시작 도시로.
        if (map[now][start]) { //갈 수 있으면
            ans = min(ans, sum + map[now][start]);
        }

        return;
    }

    //now에서 갈 수 있는 곳
    for (int i = 0; i < n; i++) {
        if (map[now][i] && !visited[i]) {
            visited[i] = true;
            dfs(start, i, level + 1, sum + map[now][i]);
            visited[i] = false;
        }
    }
}

int main() {
    cin >> n;
    map.assign(n, vector<int>(n, 0));
    visited.assign(n, false);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }
    //시작도시는 0~n-1
    for (int i = 0; i < n; i++) {
        visited[i] = true;
        dfs(i, i, 1, 0); //start도시, now도시
        visited[i] = false;
    }

    cout << ans << "\n";
    return 0;
}
