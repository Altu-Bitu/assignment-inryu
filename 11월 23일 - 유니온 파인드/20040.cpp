/*
 * 사이클 게임 : https://www.acmicpc.net/problem/20040
 */

#include <iostream>
#include <vector>

using namespace std;

vector<bool> cycle; //해당 정점이 사이클에 속하는지 여부
vector<int> parent;

//Find 연산
int findParent(int node) {
    if (parent[node] < 0) //값이 음수면 루트 정점
        return node; //이므로 바로 리턴
    return parent[node] = findParent(parent[node]); //그래프 압축하며 루트 정점 찾기
}

//Union 연산 (사이클 생기면 true 리턴)
bool unionInput(int x, int y) {
    int xp = findParent(x); //x의 부모
    int yp = findParent(y); //y의 부모

    if (xp == yp) { //같은 집합에 있다면 유니온 할 수 없음
        cycle[xp] = true; // 같은 집합에 있으면 사이클 생기는 거니깐
        return true; //사이클 생기면 true 리턴
    }
    if (cycle[xp] || cycle[yp]) //둘 중 하나라도 사이클이 있으면
        cycle[xp] = cycle[yp] = true; // 둘 다 사이클 있다고 표시
    if (parent[xp] < parent[yp]) { // 값이 더 작은게 (음수로는 절대값이 큰 게 ) 부모가 됨 (xp)
        parent[xp] += parent[yp]; // 자식 개수 늘려주고 (음수 절대값으로 )
        parent[yp] = xp; //yp의 부모는 xp
    } else { //새로운 루트 yp
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, a, b;
    cin >> n >> m; //점의 개수, m번째 차례
    parent.assign(n + 1, -1);
    cycle.assign(n + 1, false);

    int stage = 1;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        if (unionInput(a, b)) {
            cout << stage << "\n";
            break;
        }
        stage++;
    }

    //m 번의 차례를 모두 처리한 이후에도 종료되지 않았다면
    if (stage == m + 1) cout << "0\n";

}
