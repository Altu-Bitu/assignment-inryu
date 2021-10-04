#include <iostream>

using namespace std;
int map[10][10];

bool promising(int r, int c, int num) {
    //같은 행, 열
    for (int i = 0; i < 9; i++) {
        if (map[i][c] == num || map[r][i] == num) return false;
    }
    //3*3
    int restR = r % 3;
    int restC = c % 3;
    for (int i = r - restR; i < r - restR + 3; i++) {
        for (int j = c - restC; j < c - restC + 3; j++) {
            if (map[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

bool sudoku(int idx) {
    // 스도쿠 완성
    if (idx == 81) {
        return true; //여럿인 경우 하나만 출력
    }
    int r = idx / 9;
    int c = idx % 9;
    if (map[r][c]) return sudoku(idx + 1); //빈칸이 아니면 다음칸
    //1부터 9넣을 수 있는지
    for (int i = 1; i <= 9; i++) {
        if (promising(r, c, i)) {
            map[r][c] = i;
            bool check = sudoku(idx + 1);
            if (check) return true;
            map[r][c] = 0;
        }
    }
    return false;
}

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> map[i][j];
        }
    }
    sudoku(0); // 인덱스 0부터 시작해서 끝까지 채우기

    //출력
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}