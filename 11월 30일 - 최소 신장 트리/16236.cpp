/*
 * 나무 재태크 : https://www.acmicpc.net/problem/16235
 */

//왜 안돼
#include <iostream>
#include <vector>

using namespace std;

struct Tree {
    int r; //행
    int c; //열
    int age; //나이
    Tree(int rr, int cc, int aage) {
        r = rr;
        c = cc;
        age = aage;
    }

    //나이 오름차순
    bool operator<(const Tree &b) const {
        return age < b.age;
    }
};

vector<vector<int>> add_val; //각 칸에 추가되는 양분 (A[r][c])
vector<vector<int>> map; //맵
int n, m, k;

int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};


vector<Tree> spring(vector<Tree> &live_tree) {
    vector<Tree> dead_tree;
    int idx = -1;
    sort(live_tree.begin(), live_tree.end()); //어린 나이부터
    for (int i = 0; i < live_tree.size(); i++) {
        int r = live_tree[i].r;
        int c = live_tree[i].c;
        int age = live_tree[i].age;

        //나이만큼 양분 먹기
        if (map[r][c] >= age) { //자신의 칸에 있는 양분
            map[r][c] -= age;
        } else {
            idx = i;
            break;
        }
    }
    //죽은 나무가 있으면
    if (idx != -1) {
        for (int i = idx; i < live_tree.size(); i++) {
            dead_tree.push_back(Tree(live_tree[i].r, live_tree[i].c, live_tree[i].age));
        }
    }
    live_tree.erase(live_tree.begin() + idx, live_tree.end());
    return dead_tree; //죽은 트리 반환
}

/*
* <여름>
*  1) 봄에 죽은 나무가 양분으로 변함
*      - 죽은 나무마다 나이를 2로 나눈 값(소수점 버림)이 나무가 있던 칸에 양분으로 추가
*/
void summer(vector<Tree> &dead_tree) {
    for (auto &tree :dead_tree) {
        map[tree.r][tree.c] += tree.age / 2;
    }
}

/*
 *  <가을>
 *  1) 나이가 5의 배수인 나무 인접한 8칸에 나이가 1인 나무가 생김.
 */
void fall(vector<Tree> &live_tree) {
    int size = live_tree.size();
    for (int i = 0; i < size; i++) {
        int r = live_tree[i].r;
        int c = live_tree[i].c;
        int age = live_tree[i].age;

        if (age % 5 == 0) { //5의 배수이면
            for (int d = 0; d < 8; d++) {  //인접한 8칸에
                int nr = r + dr[d];
                int nc = c + dc[d];
                if (nr < 1 || nr > n || nc < 1 || nc > n) continue;

                live_tree.push_back(Tree(nr, nc, 1)); //나이가 1인 나무가 생김.
            }
        }
    }

}

/*
*  <겨울>
*  1) 땅에 양분 추가 A[r][c] 만큼.
*/
void winter() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            map[i][j] += add_val[i][j];
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;
    map.assign(n + 1, vector<int>(n + 1, 5)); //초기엔 전부 5
    add_val.assign(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> add_val[i][j];
        }
    }

    vector<Tree> live_tree;
    vector<Tree> dead_tree;

    int x, y, z;
    while (m--) {
        cin >> x >> y >> z; //위치, 나이
        live_tree.emplace_back(Tree(x, y, z));
    }

    while (k--) {
        dead_tree.clear();
        dead_tree = spring(live_tree);
        summer(dead_tree);
        fall(live_tree);
        winter();
    }
    cout << live_tree.size() << "\n";

}