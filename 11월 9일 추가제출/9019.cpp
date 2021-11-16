/*
 * DSLR : https://www.acmicpc.net/problem/9019
 */

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, char> ci; // {숫자, 명령어}
const int SIZE = 10000; //A와 B는 모두 10,000 미만

//역추적
string back(int x, vector<ci> &path) { //x = B부터 역추적 시작
    string ans = "";
    while (path[x].first != -1) { //맨 처음 넣어둔 시작 경로가 될 때까지
        ans += path[x].second; // 명령어 역추적해서 앞에서부터 쌓음
        x = path[x].first; //숫자 갱신
    }
    reverse(ans.begin(), ans.end()); // 명령어 역추적해서 앞에서부터 쌓았으므로 리버스 해줌
    return ans; // 역추적한 명렁어 리턴
}

//bfs
void bfs(int a, int b, vector<ci> &path) {
    vector<bool> visited(SIZE, false); //이미 썼던 숫자인지.
    queue<int> q; //큐에 노드(숫자값) 저장
    q.push(a); //시작 노드 초기화
    visited[a] = true; //시작 노드(숫자값) 초기화
    while (!q.empty()) { //bfs 탐색 진행
        int cur = q.front(); //현재 수
        q.pop(); // pop 안 하면 무한루프!

        if (cur == b) //B를 만들었다면 즉시 탐색 종료
            break;

        //차례대로 D,S,L,R 명령어를 실행했을 때 path (first : 경로(숫자), second : 명령어)
        vector<ci> child = {{cur * 2 % SIZE,                   'D'}, //각 명렁어의 수행 결과를 사칙연산으로 경로 나타낼 수 있음
                            {(cur - 1 + SIZE) % SIZE,          'S'},
                            {(cur * 10 % SIZE) + (cur / 1000), 'L'},
                            {(cur % 10 * 1000) + (cur / 10),   'R'}};

        //각 명령어를 모두 본다.
        for (int i = 0; i < 4; i++) {
            int next = child[i].first; //다음 숫자.
            if (!visited[next]) { //방문한 적 없으면
                q.push(next); // 큐에 추가해주고
                visited[next] = true; //방문 체크
                path[next] = ci(cur, child[i].second); //자식 노드에 부모 노드(경로)와 명령어 저장
            }
        }
    }
}

/**
 * path: 경로와 수행한 명령어(D, S, L, R)를 저장
 *
 * 각 명령어의 수행 결과를 사칙연산으로 나타낼 수 있음 (cur: 현재 수, SIZE = 10,000)
 * D: cur * 2 % SIZE
 * S: (cur - 1 + SIZE) % SIZE (cur이 0일 경우를 처리하기 위해)
 * L: (cur * 10 % SIZE) + (cur / 1000)
 * R: (cur % 10 * 1000) + (cur / 10)
 *
 * 따라서 위의 연산을 적용한 값들을 자식노드로 하여 bfs 탐색 진행
 * 앞서 구한 path값을 따라 B인덱스부터 역추적 시작
 */

int main() {
    int t, a, b;

    //입력 & 연산 & 출력
    cin >> t; //테스트케이스
    while (t--) {
        cin >> a >> b;
        vector<ci> path(SIZE, {-1, ' '}); //first: 경로, second: 명령어
        bfs(a, b, path); //a -> b 경로 bfs 실행
        cout << back(b, path) << '\n'; // 최단 경로 역추적!
    }
    return 0;
}