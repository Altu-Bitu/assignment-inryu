/*
 * 거짓말 : https://www.acmicpc.net/problem/1043
 */

//추가제출

#include <iostream>
#include <vector>

using namespace std;

vector<bool> know; //진실을 아는지 여부
vector<int, vector<int>> parent;

//Find 연산
int findParent(int node) {
    if (parent[node] < 0) //값이 음수면 루트 정점
        return node; //이므로 바로 리턴
    return parent[node] = findParent(parent[node]); //그래프 압축하며 루트 정점 찾기
}

//Union 연산
void unionInput(int x, int y) {
    int xp = findParent(x); //x의 부모
    int yp = findParent(y); //y의 부모

    if (xp == yp) { //같은 집합에 있다면 유니온 할 수 없음
        know[xp] = true; // 같은 집합에 있으면 사이클 생기는 거니깐
        return;
    }
    if (know[xp] || know[yp]) //둘 중 하나라도 사이클이 있으면
        know[xp] = know[yp] = true; // 둘 다 사이클 있다고 표시

    if (parent[xp] < parent[yp]) { // 값이 더 작은게 (음수로는 절대값이 큰 게 ) 부모가 됨 (xp)
        parent[xp] += parent[yp]; // 자식 개수 늘려주고 (음수 절대값으로 )
        parent[yp] = xp; //yp의 부모는 xp
    } else { //새로운 루트 yp
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }
}

int cntParty(int n) {
    int cnt = 0;
    //루트중에 진실 모르는 거 -> 과장 가능한 파티
    //각 파티마다 루트는..?

    for (int i = 1; i <= n; i++) {
        if (parent[i] < 0 && !know[i]) cnt++;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, p, val, a, b;
    cin >> n >> m; //사람의 수, 파티의 수.
    cin >> p; //진실을 아는 사람 수
    parent.assign(n + 1, -1);
    know.assign(n + 1, false);
    for (int i = 0; i < p; i++) {
        cin >> val;
        know[val] = true;
    }

    /*
     * 1. 진실을 아는 사람에게는 진실만 말함
     * 2. 진실된 사람이 속한 집합에는 무조건 진실만 말해야 함.
     *  -> union 할 때, 한쪽이 진실을 알고있으면 나머지도 알고 있음.(?)
     */
    for (int i = 0; i < m; i++) {
        cin >> p; //파티에 오는 인원
        // 한 파티에 속한 사람들은 다 같은 집합.
        vector<int> arr; //파티에 오는 사람들
        for (int j = 0; j < p; j++) {
            cin >> val;
            arr.push_back(val);
        }
        for (int j = 0; j < arr.size() - 1; j++) {
            unionInput(arr[i], arr[i + 1]);
        }
    }
    cout << cntParty(n) << "\n";
}

