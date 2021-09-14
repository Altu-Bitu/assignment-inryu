#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> bucket;

    for (auto move: moves) {
        int col = move - 1; //0행부터 시작하므로
        int row = 0; //가장 윗줄부터 확인
        while (row < board.size()) {
            // 빈 칸이라면
            if (!board[row][col]) {
                row++; //다음 줄
                continue;
            }
            // 빈 칸이 아니라면
            int doll_num = board[row][col];
            board[row][col] = 0; //뽑아서 0으로

            if (bucket.empty()) {  //1. 스택이 비어있음
                bucket.push(doll_num); //바로 삽입.
                break;
            }

            if (bucket.top() == doll_num) {  //2. 같은 모양 2개가 연속해서 들어있음
                bucket.pop();
                answer += 2;
            } else bucket.push(doll_num); //3. 같은 모양이 아님
            break;
        }
    }
    return answer;

}

int main() {
    vector<vector<int>> board = {{0, 0, 0, 0, 0},
                                 {0, 0, 1, 0, 3},
                                 {0, 2, 5, 0, 1},
                                 {4, 2, 4, 4, 2},
                                 {3, 5, 1, 3, 1}};
    vector<int> moves = {1, 5, 3, 5, 1, 2, 1, 4};
    cout << solution(board, moves);
}