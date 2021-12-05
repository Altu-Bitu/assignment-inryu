/*
 * 거짓말 : https://www.acmicpc.net/problem/1043
 */
#include <iostream>
#include <vector>

using namespace std;

vector<bool> know; //진실을 아는지 여부
vector<int> parent; // 부모 노드

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
        return; // 바로 리턴
    }
    if (know[xp] || know[yp]) //둘 중 하나라도 사이클이 있으면
        know[xp] = know[yp] = true; // 둘 다 사이클 있다고 표시
    if (parent[xp] < parent[yp]) { // 값이 더 작은게 (음수로는 절대값이 큰 게 ) 부모가 됨 (xp)
        parent[xp] += parent[yp]; // 자식 개수 늘려주고 (음수 절대값으로 )
        parent[yp] = xp; //yp의 부모는 xp
    } else { //새로운 루트 yp
        parent[yp] += parent[xp]; // 자식 개수 늘려주고 (음수 절대값으로)
        parent[xp] = yp; //xp의 부모는 yp
    }
}

int cntLiarParty(vector<int> &parties) {
    int cnt = 0; // 과장 가능한 파티 세기
    //루트중에 진실 모르는 거 -> 과장 가능한 파티
    for (int i = 0; i < parties.size(); i++) { //각 파티마다
        int root = findParent(parties[i]); //파티 집합의 루트 정점
        if (!know[root]) cnt++; //루트 정점 중 진실 모르는 거 -> 과장 가능한 파티 개수 세기
    }
    return cnt; //과장 가능한 파티 개수 리턴.
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, init, p;
    cin >> n >> m; //사람의 수, 파티의 수.
    parent.assign(n + 1, -1);
    know.assign(n + 1, false);

    cin >> init;
    while (init--) { //진실 아는 사람들
        cin >> p;
        know[p] = true;
    }
/**
 * 1. 각 사람들은 다양한 파티를 통해 연결됐다고 할 수 있음
 * 2. 연결된 사람들은 같은 집합에 속함
 * 3. 각 집합에 속한 사람들 중 한 명이라도 진실을 안다면 그 집합의 사람들이 속한 파티에는 거짓말을 할 수 없음
 * -> 유니온 파인드로 사람들을 집합으로 묶은 뒤, 파티마다 거짓말을 할 수 있는지 확인하기
 *
 * !주의! 파티 정보를 입력받으며 바로 거짓말 가능 여부를 판단할 수 없음 (예제 입력 4)
 *       각 파티에서 한 사람만 저장해둔 뒤, 마지막에 거짓말 가능 여부 한 번에 판단
 */
    int cnt, first_person, people;
    vector<int> parties; //각 파티마다 첫 번째 사람만 저장 할 거임
    while (m--) { //파티의 수
        cin >> cnt >> first_person; // 참여 인원, 첫번째 사람
        //연산
        parties.push_back(first_person); //파티 정보로 각 파티의 첫번째 사람만 저장
        while (--cnt) { //남은 인원
            cin >> people; //받아서
            unionInput(first_person, people); //첫번째 사람이랑 유니온
        }
    }
    cout << cntLiarParty(parties) << "\n";
}