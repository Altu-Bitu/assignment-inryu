/*
 *  [222-풀] : https://www.acmicpc.net/problem/17829
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> map;

int findSecond(int r, int c) {
    vector<int> arr;
    //2*2
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            arr.push_back(map[r + i][c + j]);
        }
    }
    sort(arr.begin(), arr.end());
    return arr[2]; //2번째로 큰 수
}

int pooling(int size) {
    //사이즈가 1이면
    if (size == 1) {
        cout << map[0][0] << "\n";
        //return map[0][0]; // 🖍 이걸로 하면 엄청나게 큰 수가 뜹니다...?! 왜일까요 cout으로 하면 잘 나오는데..
        return 0;
    }

    // 2*2씩 두번째 큰 수 구하고, 배열 1/4크기 왼쪽 위에 담기
    for (int i = 0; i < size; i += 2) {
        for (int j = 0; j < size; j += 2) {
            map[i / 2][j / 2] = findSecond(i, j);
        }
    }
    pooling(size / 2);
    return 0;
}

int main() {

    int n;
    cin >> n;
    map.assign(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    pooling(n);
    return 0;
}