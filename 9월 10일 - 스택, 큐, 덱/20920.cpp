#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

//맵 정렬 함수
bool cmp(pair<string, int> &a, pair<string, int> &b) {
    if (a.second != b.second) return a.second > b.second; //등장 횟수
    if (a.first.size() != b.first.size()) return a.first.size() > b.first.size(); //단어 길이
    return a.first < b.first; // 알파벳 사전 순
}

int main() {
    int N, M;
    string word;
    map<string, int> m; // 단어, 등장 횟

    cin >> N >> M;
    while (N--) {
        cin >> word;
        if (word.size() >= M)
            m[word]++;
    }

    // 맵을 벡터로 이동시킨 후 정렬
    vector<pair<string, int>> sort_map(m.begin(), m.end());
    sort(sort_map.begin(), sort_map.end(), cmp);

    for (auto w:sort_map) cout << w.first << "\n";
}

