// 컨베이어 벨트 위의 로봇
#include <iostream>
#include <queue>

using namespace std;

struct Block {
    bool is_robot;
    int power;
};

deque<Block> belt; //2*N의 크기를 가질 벨트.
int N, K;

void rotateBelt() {
    //내리는 위치에 존재하면 로봇은 사라질 것이니깐
    belt[N - 1].is_robot = false;
    //디큐 회전
    belt.push_front(belt.back()); // 한 칸 회전 ( 맨 뒤 원소를 맨 앞에 push 하고)
    belt.pop_back(); // 맨 뒤 원래 위치에서 제거
}

void moveRobot() {
    //내리는 위치
    if (belt[N - 1].is_robot) {
        belt[N - 1].is_robot = false;
    }
    //가장 먼저 올라간 로봇부터 (N-2)
    for (int i = N - 2; i >= 0; i--) {
        //현재 칸에 로봇 존재 & 다음 칸에 로봇 안 존재 & 다음 칸 내구도 >=1
        if (belt[i].is_robot && !belt[i + 1].is_robot && belt[i + 1].power >= 1) {
            belt[i + 1].is_robot = true;
            belt[i + 1].power--;
            belt[i].is_robot = false;
        }
    }
}

void putRobot() {
    //올리는 위치 칸 내구도가 있고 로봇이 없으면
    if (belt[0].power && !belt[0].is_robot) {
        belt[0].is_robot = true; //하나 올림
        belt[0].power--;
    }
}

int checkZero() {
    int res = 0;
    for (int i = 0; i < 2 * N; i++) {
        if (!belt[i].power) res++;
    }
    return res;
}

int main() {
    int val;

    cin >> N >> K;

    //인덱스 0~  2N-1까지
    /*
     * 올리는 위치 : 0 / 내리는 위치 : N-1
     */
    for (int i = 0; i < 2 * N; i++) {
        cin >> val;
        belt.push_back({false, val});
    }

    int stage = 0;
    while (true) {
        stage++;
        rotateBelt();
        moveRobot();
        putRobot();
        if (checkZero() >= K) break;
    }

    cout << stage << "\n";
}
