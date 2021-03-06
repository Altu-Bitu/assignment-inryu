#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int N, M;
string name;

int main() {
    cin >> N >> M;
    set<string> s;
    vector<string> res;
    int cnt = 0;
    //듣도 못한 사람
    for (int i = 0; i < N; i++) {
        cin >> name;
        s.insert(name);
    }

    //보도 못한 사람
    for (int i = 0; i < M; i++) {
        cin >> name;
        if (s.count(name)) { // key값의 value가 있는지 확인!
            res.push_back(name);
            cnt++;
        }
    }

    sort(res.begin(), res.end());
    cout << cnt << "\n";
    for (auto i: res) cout << i << "\n";

}

