#include <iostream>
#include <queue>

using namespace std;
int n, m;
deque<int> deck[2]; //0: 도도, 1: 수수
deque<int> ground[2];

int check_top() {
    if ((!ground[0].empty() && ground[0].front() == 5) || (!ground[1].empty() && ground[1].front() == 5)) return 0; //도도
    if (!ground[0].empty() && !ground[1].empty() && ground[0].front() + ground[1].front() == 5) return 1;
    return 2; //아무도 못가져감
}

int main() {
    cin >> n >> m;
    int a, b;
    while (n--) {
        cin >> a >> b;
        deck[0].push_front(a);
        deck[1].push_front(b);
    }

    int turn = 0; //도도부터
    while (m--) {
        //내려놓기
        ground[turn].push_front(deck[turn].front());
        deck[turn].pop_front();

        //도중에 덱에 있는 카드수가 0이 된다면
        if (deck[turn].empty()) {
            if (turn == 1) cout << "do\n";
            else cout << "su\n";
            return 0;
        }

        int winner = check_top();
        if (winner == 2) { //아무도 못가져감
            turn = abs(turn - 1);
            continue;
        }
        int loser = abs(winner - 1);
        //남꺼
        while (!ground[loser].empty()) {
            deck[winner].push_back(ground[loser].back());
            ground[loser].pop_back();
        }
        //내꺼
        while (!ground[winner].empty()) {
            deck[winner].push_back(ground[winner].back());
            ground[winner].pop_back();
        }
        turn = abs(turn - 1);
    }
    if (deck[0].size() > deck[1].size()) {
        cout << "do\n";
        return 0;
    }
    if (deck[1].size() > deck[0].size()) {
        cout << "su\n";
        return 0;
    }
    cout << "dosu\n";
    return 0;
}
