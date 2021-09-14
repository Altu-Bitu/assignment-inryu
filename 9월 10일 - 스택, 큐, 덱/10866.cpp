#include <string>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

/*
 * 이렇게 모두 조건 거는 게 맞나요....?!
 */
int main() {
    deque<int> dq;
    int N, val;
    string cmd;

    cin >> N;
    while (N--) {
        cin >> cmd;
        if (cmd == "push_front") {
            cin >> val;
            dq.push_front(val);
        } else if (cmd == "push_back") {
            cin >> val;
            dq.push_back(val);
        } else if (cmd == "pop_front") {
            if (!dq.empty()) {
                cout << dq.front() << "\n";
                dq.pop_front();
            } else cout << "-1\n";
        } else if (cmd == "pop_back") {
            if (!dq.empty()) {
                cout << dq.back() << "\n";
                dq.pop_back();
            } else cout << "-1\n";
        } else if (cmd == "size") {
            cout << dq.size() << "\n";
        } else if (cmd == "empty") {
            cout << dq.empty() << "\n";
        } else if (cmd == "front") {
            if (!dq.empty())
                cout << dq.front() << "\n";
            else cout << "-1\n";
        } else if (cmd == "back") {
            if (!dq.empty())
                cout << dq.back() << "\n";
            else cout << "-1\n";
        }
    }
    return 0;
}