#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> map;
vector<int> team; //1은 스사트, 0은 링크
int ans = 2147000000;
int n;

//능력치 차 구하기
int computeSub() {
    vector<int> start, link;
    int start_power = 0, link_power = 0;
    for (int i = 1; i <= n; i++) {
        if (team[i]) start.push_back(i); //조합 배열에서 1은 스타트팀
        else link.push_back(i); //0은 링크팀
    }

    //start_power
    for (int i = 0; i < start.size() - 1; i++) {
        for (int j = i + 1; j < start.size(); j++) {
            start_power += map[start[i]][start[j]] + map[start[j]][start[i]];
        }
    }
    //link_power
    for (int i = 0; i < link.size() - 1; i++) {
        for (int j = i + 1; j < link.size(); j++) {
            link_power += map[link[i]][link[j]] + map[link[j]][link[i]];
        }
    }
    return abs(start_power - link_power);
}


void dfs(int start, int level, int target_level) {
    if (level == target_level) {
        ans = min(ans, computeSub());
        return;
    }

    for (int i = start; i <= n; i++) {
        team[i] = 1; //1은 스타트;
        dfs(i + 1, level + 1, target_level);
        team[i] = 0;
    }
}

int main() {

    cin >> n;
    map.assign(n + 1, vector<int>(n + 1, 0));
    team.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }

    //스타트의 인원을 1~n-1명까지 조합!
    for (int i = 1; i <= n - 1; i++) {
        dfs(1, 0, i);
    }

    cout << ans << "\n";
}