#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int T, n;
    string name, ctg;
    cin >> T;

    while (T--) {
        map<string, int> m; //의상종류, 개수
        cin >> n;
        while (n--) {
            cin >> name >> ctg;
            m[ctg]++;
        }
        int res = 1;

        for (auto it = m.begin(); it != m.end(); it++) {
            res *= (it->second) + 1; // 종류의 각 의상을 한번씩 입는 경우의 수 + 해당 종류를 아예 안 입는 경우의 수
        }
        cout << res - 1 << "\n"; // 알몸인 경우
    }
    return 0;
}

