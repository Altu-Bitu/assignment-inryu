/*
 *  [별 찍기 - 10] : https://www.acmicpc.net/problem/2447
 */
#include <iostream>
#include <vector>

using namespace std;
vector<vector<char>> map;

void makeStar(int n, int r, int c) { //n, r시작 위치, c시작 위치
    if (n == 3) { // 크기 3패턴 별 찍기.
        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                map[i][j] = '*';
            }
        }
        map[r + 1][c + 1] = ' '; //가운데
        return;
    }

    //3보다 큰 경우
    //테두리 8개 재귀 호출
    for (int i = 0; i < n; i += n / 3) { // 행 시작 점
        for (int j = 0; j < n; j += n / 3) { //열 시작 점
            if (i == n / 3 && j == n / 3) continue; //가운데 뚫린 거 패스
            makeStar(n / 3, r + i, c + j);
        }
    }
}

int main() {
    int n;
    cin >> n;
    map.assign(n, vector<char>(n + 1, ' '));
    makeStar(n, 0, 0);
    //출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << map[i][j];
        }
        cout << "\n";
    }
}