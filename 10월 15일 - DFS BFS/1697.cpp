/*
 * 숨바꼭질 : https://www.acmicpc.net/problem/1697
 */

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
#define MAX 100000
int visited[MAX + 1];

int bfs(int n, int k) {
    queue<pair<int, int>> q; // 수빈이 위치, 시간
    q.push(make_pair(n, 0));
    visited[n] = true;

    while (!q.empty()) {
        int loc = q.front().first;
        int time = q.front().second;
        q.pop();

        // 동생을 찾았을 때
        if (loc == k)
            return time;

        // 3가지 경우
        // 방문하지 않은 곳만! (방문한 곳에 다시 가면 최단 거리 X)
        if (loc - 1 >= 0 && !visited[loc - 1]) {
            q.push(make_pair(loc - 1, time + 1));
            visited[loc - 1] = true;
        }
        if (loc + 1 <= MAX && !visited[loc + 1]) {
            q.push(make_pair(loc + 1, time + 1));
            visited[loc + 1] = true;
        }

        if (loc * 2 <= MAX && !visited[loc * 2]) {
            q.push(make_pair(loc * 2, time + 1));
            visited[loc * 2] = true;
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << bfs(n, k) << "\n";
    return 0;
}