#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int map[10][10];
vector<pair<int, int>> blank;

void sudoku(int level) {
    // 스도쿠 완성
    if (level == blank.size()) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << map[i][j] << " ";
            }
            cout << "\n";
        }
        exit(0); //한 번 찾고 종료
    }

    //현재 빈칸
    int r = blank[level].first;
    int c = blank[level].second;

    //가로, 세로, 작은 네모를 탐색하며 어느 칸이 없는지 체크할 것
    int candidate[10] = {0,};

    //가로, 세로
    for (int i = 0; i < 9; i++) {
        if (map[r][i]) candidate[map[r][i]] = 1;
        if (map[i][c]) candidate[map[i][c]] = 1;
    }

    //9칸.
    int restR = r % 3;
    int restC = c % 3;
    for (int i = r - restR; i < r - restR + 3; i++) {
        for (int j = c - restC; j < c - restC + 3; j++) {
            if (map[i][j]) {
                candidate[map[i][j]] = 1;
            }
        }
    }

    //1~9까지 없는 칸을 후보로 DFS 진행
    for (int i = 1; i <= 9; i++) {
        if (candidate[i] == 0) {
            map[r][c] = i;
            sudoku(level + 1); //다음 빈칸.
            map[r][c] = 0; //백트래킹. //레벨까지 못 갈 수도 있기 때문에 여러 경로
        }
    }
}

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> map[i][j];
            if (map[i][j] == 0) {
                blank.push_back({i, j});
            }
        }
    }
    sudoku(0); // black 0인덱스부
}