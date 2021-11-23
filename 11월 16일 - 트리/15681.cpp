/*
 * 트리와 쿼리 : https://www.acmicpc.net/problem/15681
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> subtree_cnt; // 인덱스 i 정점을 루트로 하는 서브트리에 속한 정점의 수 저장.

// dfs
int treeDp(int cur, vector<vector<int>> &graph) {
    if (subtree_cnt[cur] != -1) //이미 탐색했던 상태
        return subtree_cnt[cur]; // cur 정점을 루트로 하는 서브트리에 속한 정점의 수 리턴.

    //서브트리에 속한 정점의 수를 세고, 저장
    subtree_cnt[cur] = 0; //초기화
    int node = 1; // 처음엔 나 하나.
    for (int i = 0; i < graph[cur].size(); i++) //인접한 노드들
        node += treeDp(graph[cur][i], graph); //인접한 노드를 루트로 하는 서브트리에 속한 정점의 수를 ..재귀적으로 더해주기
    return subtree_cnt[cur] = node; // 개수 다 구한 후 넣어주기.
}

/**
 * PPT 트리의 정점의 수 구하기 응용
 *
 * 1. 루트에서부터 dfs 탐색
 * 2. 각 노드를 루트로 하는 서브트리의 정점 수를 재귀적으로 계산
 */
int main() {
    //입출력 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, r, q, u, v, input;

    //입력
    cin >> n >> r >> q; // 정점의 수, 루트 번호, 쿼리의 수
    vector<vector<int>> graph(n + 1, vector<int>(0)); //인접 리스트
    subtree_cnt.assign(n + 1, -1); // 인덱스 i 정점을 루트로 하는 서브트리에 속한 정점의 수. -1로 초기화

    while (--n) { //무방향 그래프
        cin >> u >> v; //u와 v를 양 끝점으로 하는 간선
        graph[u].push_back(v); //인접 리스트 추가 u->v
        graph[v].push_back(u); //인접 리스트 추가 v->u
    }

    //연산
    treeDp(r, graph); // r: 루트번호

    //출력
    while (q--) {
        cin >> input; //각 쿼리
        cout << subtree_cnt[input] << '\n'; //각 쿼리를 루트로 하는 서브트리에 속한 정점의 수 출력.
    }
}