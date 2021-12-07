/*
 * MST 게임 : https://www.acmicpc.net/problem/16202
 */

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
typedef tuple<int, int, int> tp; // 가중치, 두 정점의 번호 x,y

vector<int> parent; // Union Find

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
        return false; //false 리턴
    if (parent[xp] < parent[yp]) { //새로운 루트 xp
        parent[xp] += parent[yp]; //xp에 자식 하나 더해주기
        parent[yp] = xp; //yp의 부모는 xp
    } else { //새로운 루트 yp
        parent[yp] += parent[xp]; //yp에 자식 하나 더해주기
        parent[xp] = yp; //xp의 부모는 yp
    }
    return true; //유니온 했을 경우 true 리턴.
}

// kruskal
int kruskal(int n, int idx, vector<tp> &edges) {
    int cnt = 0, sum = 0; //사용한 간선의 수, mst 비용
    for (int i = idx; i < edges.size(); i++) { //idx-1까지의 간선은 제외하고
        if (cnt == n - 1) //n-1개의 간선을 모두 연결함
            break;
        int dist = get<0>(edges[i]); //가중치
        int x = get<1>(edges[i]); //정점1 번호
        int y = get<2>(edges[i]); //정점2 번호

        if (unionInput(x, y)) { //유니온 했을 경우
            cnt++; // 사용한 간선의 수 ++
            sum += dist; // mst 비용에 가중치 더해주기
        }
    }
    if (cnt < n - 1) //mst를 만들 수 없으면 0 리턴
        return 0;
    return sum; // mst 만들 수 있으면 mst 비용 리턴
}

/**
 * MST 알고리즘을 여러 번 실행해도 될까?
 * 1. 크루스칼 알고리즘의 시간 복잡도는 O(ElogE)
 *    이는 오직 간선을 정렬하는 연산의 시간 복잡도!
 *    즉, 모든 간선을 한 번 정렬해서 저장해두면 이후 몇 번의 알고리즘을 수행하여도 연산 시간에 큰 영향이 없음
 * 2. 간선 재사용을 위해 우선순위 큐가 아닌 벡터에 저장하고 크루스칼 알고리즘 k번 실행
 * 3. 매번 크루스칼을 수행할 때마다 제일 먼저 추가한 간선을 제외함
 *    -> 제외될 간선은 배열의 0번째 간선부터 1, 2, 3번째 간선으로 순차적 제외
 * 4. 만약 한 번 MST를 만들 수 없다는게 확인됐다면 이후에도 MST를 만들 수 없으므로 flag 변수로 불필요한 연산 절약
 */
int main() {
    int n, m, k, x, y;

    cin >> n >> m >> k; //정점 개수, 간선 개수, 턴의 수
    vector<tp> edges; //재사용할거라 우선순위 큐가 아닌 벡터에 저장
    for (int i = 1; i <= m; i++) { //간선 정보
        cin >> x >> y; // 두 정점의 번호
        edges.emplace_back(i, x, y); //가중치, 두 정점의 번호
    }

    bool flag = false; // mst를 만들지 못한 상황인가
    for (int i = 0; i < k; i++) {
        if (flag) { //더이상 mst를 만들 수 없음
            cout << 0 << ' '; //0 출력
            continue;
        }
        parent.assign(n + 1, -1); //초기화
        int ans = kruskal(n, i, edges); //i-1까지의 간선은 제외. //mst 비용 구하기
        if (ans == 0) //mst 만들 수 없다면
            flag = true; //flag값 설정해주고 이후 것들도 모두 0
        cout << ans << ' '; // mst 비용 출력.
    }
}