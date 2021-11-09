/*
 *  [⚾]: https://www.acmicpc.net/problem/17281
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<bool> base(4); //1루, 2루, 3루

// num : 1~4 전진
int move(int num) {
    int sum = 0;
    for (int i = 3; i >= 1; i--) { //3루~1루순으로 전진
        if (base[i] && i + num > 3) { //홈에 도착할 수 있는 경우
            sum++;
            base[i] = false;
            continue;
        }
        if (base[i]) {
            base[i + num] = base[i];
            base[i] = false;
        }
    }
    if (num <= 3) base[num] = 1; // 홈런인 경우 빼고
    return sum;
}

int computeScore(int n, vector<int> &order, vector<vector<int>> &result) {
    int total_score = 0;
    int idx = 1;
    int cur_order = order[idx]; //1번 타자 선수부터 시작
    for (int i = 0; i < n; i++) { // n이닝 동안
        base.assign(4, false); // 이거 안해줌; 각 이닝마다 다시 시작...
        int out = 0; //3아웃되면 종료
        while (out < 3) {
            switch (result[i][cur_order]) { //i번째 이닝의 cur_order 선수의 기록
                case 0: //아웃
                    out++;
                    break;
                case 1: //안타.
                    total_score += move(1);
                    break;
                case 2: //2루타
                    total_score += move(2);
                    break;
                case 3: //3루타
                    total_score += move(3);
                    break;
                case 4: //홈런
                    total_score += move(4);
                    total_score++; //타자까지 득점
                    break;
            }
            idx++;
            if (idx == 10) idx = 1; //인덱스는 1~9까지
            cur_order = order[idx]; //다음 타자
        }
    }
    return total_score;
}

int main() {
    int n, ans = -1;
    cin >> n;
    vector<vector<int>> result(n, vector<int>(10, 0)); //n이닝 , 9번 타자까지 (인덱스 1~9)
    vector<int> player(8); //순열을 만들기 위함
    vector<int> order(10); // 결정된 타순
    //input
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 9; j++) {
            cin >> result[i][j];
        }
    }
    //순열 만들기용
    for (int i = 0; i < 9; i++) {
        player[i] = i + 2; //2~8 (1번은 이미 결정되었으니까)
    }
    //순서 순열 만들기
    do {
        for (int i = 0; i < 3; i++) {
            order[i + 1] = player[i];
        }
        order[4] = 1; //  1번타자는 4회 고정
        for (int i = 3; i < 8; i++) {
            order[i + 2] = player[i];
        }
        ans = max(ans, computeScore(n, order, result));
    } while (next_permutation(player.begin(), player.end()));
    cout << ans << "\n";
    return 0;
}

