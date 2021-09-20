#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int M, input;
    string cmd;
    set<int> s;
    cin >> M;

    while (M--) {
        cin >> cmd;
        if (cmd == "all") {
            for (int i = 1; i <= 20; i++) s.insert(i);
        } else if (cmd == "empty") {
            s.clear();
        } else if (cmd == "add") {
            cin >> input;
            s.insert(input);
        } else if (cmd == "remove") {
            cin >> input;
            if (s.count(input)) s.erase(input);
        } else if (cmd == "check") {
            cin >> input;
            cout << s.count(input) << "\n";
        } else if (cmd == "toggle") {
            cin >> input;
            if (s.count(input)) s.erase(input); //존재하면
            else s.insert(input);
        }
    }
}