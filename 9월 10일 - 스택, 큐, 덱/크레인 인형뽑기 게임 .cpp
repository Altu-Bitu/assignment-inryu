#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> bucket;
    stack<int> map[board.size()];

    //각 열마다 stack 전처리
    for (int j = 0; j < board.size(); j++) { //열
        for (int i = board.size() - 1; i >= 0; i--) {//행 : 맽 밑부터
            if (board[i][j]) map[j].push(board[i][j]);
            else break; //0이 나오면 바로 break;
        }
    }

    for (auto move: moves) {
        int col = move - 1; //0열부터 시작하므로

        //해당 열의 스택 확인
        if (!map[col].empty()) {
            int doll_num = map[col].top(); //가장 위에 있는 인형
            map[col].pop(); //뽑기

            if (bucket.empty()) { //버킷이 비어있으면 바로 push
                bucket.push(doll_num);
                continue;
            }

            //버킷이 비어있지 않을 때 버킷의 top과 현재 뽑은 인형 비교
            if (bucket.top() == doll_num) {
                bucket.pop();
                answer += 2;
            } else {
                bucket.push(doll_num);
            }
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