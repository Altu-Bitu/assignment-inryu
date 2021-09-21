#include <iostream>
#include <map>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T, k;
    cin >> T;
    while (T--) {
        map<long long, int> m; //키 값으로 자동 오름차순 정렬
        char op;
        long long n;
        cin >> k;
        while (k--) {
            cin >> op >> n;

            if (op == 'I') {
                m[n]++;
            } else if (op == 'D') {
                if (m.empty()) continue;
                if (n == 1) {
                    auto it = m.end();
                    it--;
                    if (it->second > 1) it->second--; //1개 이상 있으면 value --
                    else m.erase(it->first); //하나면 키 자체를 지우기
                } else if (n == -1) {
                    auto it = m.begin();
                    if (it->second > 1) it->second--; //1개 이상 있으면 value --
                    else m.erase(it->first); //하나면 키 자체를 지우기
                }
            }
        }
        if (m.empty()) {
            cout << "EMPTY\n";
            continue;
        }

        auto it = m.end();
        it--;
        cout << it->first << " " << m.begin()->first << "\n";
    }
}