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
    vector<bool> visited(21);
    cin >> M;

    while (M--) {
        cin >> cmd;
        if (cmd == "all") {
            for (int i = 1; i <= 20; i++)
                if (!visited[i]) visited[i] = 1;
        } else if (cmd == "empty") {
            for (int i = 1; i <= 20; i++)
                if (visited[i]) visited[i] = 0;
        } else if (cmd == "add") {
            cin >> input;
            if (!visited[input]) visited[input] = 1;
        } else if (cmd == "remove") {
            cin >> input;
            if (visited[input]) visited[input] = 0;
        } else if (cmd == "check") {
            cin >> input;
            cout << visited[input] << "\n";
        } else if (cmd == "toggle") {
            cin >> input;
            if (visited[input]) visited[input] = 0; //존재하면 제거
            else visited[input] = 1; //없으면 추가
        }
    }
}
