#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n, m;
vector<int> res;
set<int> arr;  //숫자끼리는 중복 없이.//자동 오름차순

void DFS(int L) {
    if (L == m) {
        for (auto x: res) {
            cout << x << " ";
        }
        cout << "\n";
        return;
    }

    //썼던 수를 또 써도 되므로 visited 사용 안함.
    for (auto i : arr) {
        res[L] = i;
        DFS(L + 1);
    }
}

int main() {
    cin >> n >> m;
    res.assign(m, 0);
    int val;
    for (int i = 0; i < n; i++) {
        cin >> val;
        arr.insert(val);
    }

    DFS(0);
}