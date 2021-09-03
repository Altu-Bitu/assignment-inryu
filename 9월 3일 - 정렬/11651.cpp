#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    if (a.second != b.second) return a.second < b.second; //y좌표 오름차순
    return a.first < b.first; //x좌표 오름차순
}

int main() {
    int N, a, b;
    vector<pair<int, int>> location; //x좌표, y좌표
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        location.push_back({a, b});
    }
    sort(location.begin(), location.end(), cmp);

    for (auto i:location) cout << i.first << " " << i.second << "\n";
}

