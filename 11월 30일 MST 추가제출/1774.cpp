/*
 * 우주신과의 교감 : https://www.acmicpc.net/problem/1774
 */

#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <cmath>

using namespace std;
typedef pair<double, double> ci;
typedef tuple<double, int, int> tp;

vector<int> parent; //union & find 용 루트 노드 저장.

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
        parent[xp] += parent[yp]; //xp의 자식 늘려주기
        parent[yp] = xp; //yp의 부모는 xp
    } else { //새로운 루트 yp
        parent[yp] += parent[xp]; //yp의 자식 늘려주기
        parent[xp] = yp; //xp의 부모는 yp
    }
    return true; //유니온 할 수 있다면 true 리턴
}

//kruskal
double kruskal(int v, priority_queue<tp, vector<tp>, greater<>> &pq) {
    int cnt = 0; //사용한 간선 개수
    double sum = 0; //mst 비용

    while (cnt < v - 1) { //사용한 간선의 수가 v-1보다 적을 동안
        double cost = get<0>(pq.top()); // 가중치
        int x = get<1>(pq.top()); //정점1
        int y = get<2>(pq.top()); //정점2

        pq.pop(); //pq에서 pop 해주기
        if (unionInput(x, y)) { //유니온 했다면
            cnt++; //사용된 간선 증가
            sum += cost; //간선의 가중치 더해주기
        }
    }
    return sum; //mst 비용 리턴
}

/**
 * 4386번 : 별자리 만들기의 응용 문제
 * 이미 연결된 정점들이 존재한다는 것을 제외하고는 4386번과 동일
 *
 * 1. 임의의 두 별에 대한 거리(간선) 모두 구하기
 * 2. 이미 존재하는 통로들 표시
 *    !주의! 통로의 개수가 m개라면 v-m-1개의 간선만 더 추가하면 될까?
 *          이미 연결된 통로들도 사이클을 이룰 수 있기 때문에 유니온 연산을 하며 사이클 없이 연결된 간선만 세기
 * 3. 이미 연결된 통로의 수를 k개라고 하면 v-k-1개의 간선을 추가로 선택
 */
int main() {
    int n, m, a, b, v = 0;
    priority_queue<tp, vector<tp>, greater<>> pq; //min heap

    //입력
    cin >> n >> m; // 정점 갯수, 이미 연결된 엣지 개수
    parent.assign(n + 1, -1); //union& find용 초기화
    vector<ci> stars(n + 1); // 우주신들의 좌표
    for (int i = 1; i <= n; i++)
        cin >> stars[i].first >> stars[i].second; //우주신들의 좌표

    //연산
    //통로들의 길이는 2차원 좌표계상의 거리와 같다.
    //임의의 두 별에 대한 거리(간선) 모두 구하기
    for (int i = 1; i <= n - 1; i++) {
        for (int j = i + 1; j <= n; j++) {
            double xd = stars[i].first - stars[j].first; //x좌표 차이
            double yd = stars[i].second - stars[j].second; //y좌표 차이
            pq.push({sqrt(xd * xd + yd * yd), i, j}); // 거리(가중치), 좌표1, 좌표2
        }
    }
    // 이미 연결된 엣지
    while (m--) {
        cin >> a >> b; ///이미 연결된 통로
        if (unionInput(a, b)) //이미 연결된 통로 union 가능하면 (사이클 안 생김)
            v++; // 사이클 없이 이미 연결된 간선
    }

    //연산 & 출력
    cout << fixed;
    cout.precision(2); //소수점 둘째자리까지 출력
    cout << kruskal(n - v, pq); //연결된 거 빼고!
}