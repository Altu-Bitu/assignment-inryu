/*
 * 도시 건설 : https://www.acmicpc.net/problem/21924
 */

#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;
typedef tuple<int, int, int> tp;

vector<int> parent; // union, find

//Find 연산
int findParent(int node) {
    if (parent[node] < 0) //값이 음수면 루트 정점
        return node; //바로 리턴
    return parent[node] = findParent(parent[node]); //그래프 압축하며 루트 정점 찾기
}

//Union 연산
bool unionInput(int x, int y) {
    int xp = findParent(x); //x의 부모
    int yp = findParent(y); //y의 부모

    if (xp == yp) //같은 집합에 있다면 유니온 할 수 없음
        return false; //바로 false 리턴
    if (parent[xp] < parent[yp]) { //새로운 루트 xp
        parent[xp] += parent[yp]; //xp의 자식 개수 늘려주기
        parent[yp] = xp; //yp의 부모는 xp
    } else { //새로운 루트 yp
        parent[yp] += parent[xp]; //yp의 자식 개수 늘려주기
        parent[xp] = yp; //xp의 부모는 yp
    }
    return true; //유니온 했다면 true 리턴.
}

//kruskal
long long kruskal(int v, long long tot, priority_queue<tp, vector<tp>, greater<>> &pq) {
    int cnt = 0; // 사용한 간선의 개수
    long long sum = 0; // mst 비용

    while (cnt < v - 1) { //사용한 간선의 수가 v-1보다 적을 동안
        if (pq.empty()) //사용한 간선이 v-1개가 안됐는데 더 이상 검사할 간선이 없다면
            return -1; // 모든 건물을 다 연결 할 수 없으므로 -1 출력

        //가중치가 작은 순서대로 들어가 있음
        int cost = get<0>(pq.top()); //가중치
        int x = get<1>(pq.top()); //정점1
        int y = get<2>(pq.top()); //정점2

        pq.pop(); //간선 사용.
        if (unionInput(x, y)) { //유니온 했다면
            cnt++; //사용한 간선 개수 ++
            sum += cost; //mst 비용에 가중치 더해주기
        }
    }
    return tot - sum; // (절약할 수 있는 예산) = (도로를 다 설치 할 때 드는 비용) - (MST 비용)
}

/**
 * 기본 MST 문제에서 트리를 만들 수 없는 경우(간선이 N-1개가 아닌 경우)를 고려한 문제
 *
 * 최대 비용의 범위가 약 10^6 x 10^5 이므로 long long 자료형을 써야 함
 */

int main() {
    int n, m, a, b, c; //건물(노드)개수, 도로(엣지)개수
    long long tot = 0; // 모든 도로 비용의 합
    priority_queue<tp, vector<tp>, greater<>> pq; // min heap

    //입력
    cin >> n >> m;
    parent.assign(n + 1, -1); // union, find
    while (m--) { // 간선 개수
        cin >> a >> b >> c; //두 정점 a,b  가중치 c
        pq.push({c, a, b}); // 가중치를 기준으로 min heap이 되도록.
        tot += c; //도로를 다 설치할 때 드는 비용
    }
    //연산 & 출력
    cout << kruskal(n, tot, pq);
}