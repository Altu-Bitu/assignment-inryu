/*
 * 여행가자 : https://www.acmicpc.net/problem/1976
 */

#include <iostream>
#include <vector>

using namespace std;

//vector<bool> cycle; //해당 정점이 사이클에 속하는지 여부
vector<int> parent;

//Find 연산
int findParent(int node) {
    if (parent[node] < 0) //값이 음수면 루트 정점
        return node; //이므로 바로 리턴
    return parent[node] = findParent(parent[node]); //그래프 압축하며 루트 정점 찾기
}

//Union 연산 (사이클 생기면 true 리턴)
void unionInput(int x, int y) {
    int xp = findParent(x); //x의 부모
    int yp = findParent(y); //y의 부모

    if (xp == yp) { //같은 집합에 있다면 유니온 할 수 없음
        return;
    }
    if (parent[xp] < parent[yp]) { // 값이 더 작은게 (음수로는 절대값이 큰 게 ) 부모가 됨 (xp)
        parent[xp] += parent[yp]; // 자식 개수 늘려주고 (음수 절대값으로 )
        parent[yp] = xp; //yp의 부모는 xp
    } else { //새로운 루트 yp
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, val;
    cin >> n >> m; //도시의 수, 여행계획에 속한 도시들의 수
    parent.assign(n + 1, -1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> val;
            if (val == 1) unionInput(i, j);
        }
    }

    bool flag = false;
    //여행 계획.
    int first, next;
    cin >> first;
    for (int i = 1; i < m; i++) {
        cin >> next;
        if (findParent(first) != findParent(next)) {
            cout << "NO\n";
            flag = true;
            break;
        }
    }
    if (!flag) cout << "YES\n";

    return 0;

}

