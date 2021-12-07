
/*
 * 나무 재테크 : https://www.acmicpc.net/problem/16235
 */
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <tuple>
#include <algorithm>

using namespace std;
typedef vector<vector<int>> matrix;
typedef tuple<int, int, int> tp;

//봄 :  봄: 하나의 칸마다 나이가 어린 나무부터 자신의 나이만큼 양분을 먹고, 나이가 1 증가함
//각 칸에 양분이 부족해 자신의 나이만큼 양분을 못 먹는 나무는 즉시 죽음
queue<tp> spring(matrix &land, deque<tp> &tree, queue<pair<int, int>> &breeding_tree) {
    queue<tp> dead_tree;
    int size = tree.size();
    while (size--) { //모든 나무 검사
        int age = get<0>(tree.front()); //나이
        int row = get<1>(tree.front()); //행
        int col = get<2>(tree.front()); //열
        tree.pop_front(); // 어린 순서대로 앞에서 빼고 뒤에 넣음으로써 다 끝나면 순서대로 들어가있으 것.

        if (land[row][col] < age) { //자신의 나이만큼 양분을 먹을 수 없다면
            dead_tree.push({age, row, col}); // 죽은 나무에 추가
            continue;
        }
        land[row][col] -= age; //먹을 수 있으면 양분 먹고
        tree.emplace_back(age + 1, row, col); //나이 하나 더해준 거 뒤에 넣음
        if ((age + 1) % 5 == 0) //나이가 5의 배수라면
            breeding_tree.push({row, col}); //번식할 트리
    }
    return dead_tree; //죽은 나무 리턴
}

//여름: 봄에 죽은 나무가 양분으로 변함. 죽은 나무마다 나이를 2로 나눈 값이 양분으로 추가 (소수점 버림)
void summer(queue<tp> &dead_tree, matrix &land) {
    while (!dead_tree.empty()) { //죽은 나무
        int age = get<0>(dead_tree.front()); //죽은 나무의 나이
        int row = get<1>(dead_tree.front()); //죽은 나무의 행 위치
        int col = get<2>(dead_tree.front()); //죽은 나무의 열 위치
        dead_tree.pop(); // pop해서 없애고
        land[row][col] += (age / 2); //양분으로 변해서 원래 있던 자리에 추가
    }
}

// 가을: 나이가 5의 배수인 나무가 번식. 인접한 8개 칸에 나이가 1인 나무가 생김
void fall(int n, deque<tp> &tree, queue<pair<int, int>> &breeding_tree) {

    //방향 벡터
    int dr[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dc[8] = {0, 0, -1, 1, -1, 1, -1, 1};

    // 나이가 5의 배수인 나무 저장했던 것
    while (!breeding_tree.empty()) {
        int row = breeding_tree.front().first; //번식할 나무의 행
        int col = breeding_tree.front().second; //번식할 나무의 열
        breeding_tree.pop(); //pop해서 없애줘야 함

        //8방향으로
        for (int j = 0; j < 8; j++) {
            int nr = row + dr[j]; //새로운 행
            int nc = col + dc[j]; //새로운 열
            if (nr < 0 || nr >= n || nc < 0 || nc >= n) //범위 넘어가면 패스
                continue;
            tree.push_front({1, nr, nc}); //새로 생긴 나무 -> 나이가 1이므로 front에 Push!
        }
    }
}

// 겨울: 로봇(S2D2)이 땅을 돌아다니면서 A[r][c]만큼 각 칸에 양분 추가
void winter(int n, matrix &a, matrix &land) {
    //land를 돌아다니며 각 칸에 양분 추가 (a)
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            land[i][j] += a[i][j];
}

int main() {
    int n, m, k, x, y, z;

    //입력
    cin >> n >> m >> k; //맵 크기, 나무 개수, 몇 년 반복
    matrix a(n, vector<int>(n, 0)); // 겨울에 주는 양분의 양
    matrix land(n, vector<int>(n, 5)); //맵 : 처음 양분 모든 칸에 5
    queue<pair<int, int>> breeding_tree; //번식할 트리 (나이가 5의 배수)
    deque<tp> tree; // 번식한 나무 (나이가 1)인 애를 앞에 넣어주면 입력 후에만 정렬 한 후 사용 가능.

    //겨울에 주는 양분의 양 입력
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    // 나무 개수만큼 나무 정보 입력
    while (m--) {
        cin >> x >> y >> z; // 행 좌표, 열 좌표, 나이
        tree.emplace_back(z, x - 1, y - 1); //(0, 0)부터 시작하도록 구현하기위해 1을 빼준 인덱스에 접근
    }

    //연산
    sort(tree.begin(), tree.end()); //어린 나이 순으로 정렬
    //k년 동안 반복
    while (k--) {
        queue<tp> dead_tree = spring(land, tree, breeding_tree); //봄이 지나고 죽은 나무
        summer(dead_tree, land);
        fall(n, tree, breeding_tree);
        winter(n, a, land);
    }

    //출력
    cout << tree.size();
}