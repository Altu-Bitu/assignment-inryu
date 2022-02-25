/*
 * 특정한 최단 경로 : https://www.acmicpc.net/problem/1504
 */

// 추가제출 하겠습니다.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int MAX = 2147000000;

int dijkstra(int start, int n, vector<vector<pair<int, int>>> &graph) {
    vector<int> dist(n + 1, MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; //최소 힙 // fisrt: 가중치, second: 정점 번호

    //시작 위치 초기화
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int w = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        //주어진 경로 반드시 이동?
    }

}

int main() {
    int n, e, a, b, c, v1, v2;
    cin >> n >> e;
    vector<vector<pair<int, int>>> graph(e + 1, vector<pair<int, int>>(0)); //인접 리스트
    while (e--) {
        cin >> a >> b >> c;
        //무방향 그래프
        graph[a].push_back({b, c}); //a에서 b까지 가는데 c의 가중치
        graph[b].push_back({a, c}); //b에서 a까지 가는데 c의 가중치
    }
    cin >> v1 >> v2; //반드시 지나야하는 정점...

    cout << dijkstra(1, n, graph); //1번에서 n번 정점으로
}

