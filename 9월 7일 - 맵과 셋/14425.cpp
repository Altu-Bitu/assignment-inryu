#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    int cnt = 0;
    string str;
    map<string, int> m;
    cin >> N >> M;

    while (N--) {
        cin >> str;
        m[str]++;
    }
    while (M--) {
        cin >> str;
        if (m.count(str)) cnt++; //주어진 key의 요소 개수를 반환 (0또는 1)
    }

    cout << cnt << "\n";
    return 0;
}
