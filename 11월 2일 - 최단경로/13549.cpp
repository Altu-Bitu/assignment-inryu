/*
 *  숨바꼭질 3 : https://www.acmicpc.net/problem/13549
 */
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
#define MAX 100000
bool visited[MAX + 1];
int n, k;

int bfs(int time, int pos) {
    deque<pair<int, int>> dq; //bfs에서 큐에 넣을 땐 가중치(?) 같은 것이 한 번에 들어가는데 순간이동만 가중치가 0이므로, 큐 맨앞에 넣어줘야함
    visited[pos] = true;
    dq.push_back({time, pos});
    while (!dq.empty()) {
        int curTime = dq.front().first;
        int curPos = dq.front().second;
        dq.pop_front();

        if (curPos == k) return curTime;
        //2*x
        if (2 * curPos <= MAX && !visited[2 * curPos]) {
            visited[2 * curPos] = true;
            dq.push_front({curTime, 2 * curPos}); // 이동거리 (time)이 0이므로 front에 넣어줘야함!!
        }
        //x-1
        if (curPos >= 1 && !visited[curPos - 1]) {
            visited[curPos - 1] = true;
            dq.push_back({curTime + 1, curPos - 1});
        }

        //x+1
        if (curPos <= MAX - 1 && !visited[curPos + 1]) {
            visited[curPos + 1] = true;
            dq.push_back({curTime + 1, curPos + 1});
        }
    }
}

int main() {
    cin >> n >> k;
    cout << bfs(0, n) << "\n";
    return 0;
}
