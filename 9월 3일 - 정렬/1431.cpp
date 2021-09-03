#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sum(string str) {
    int res = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str.at(i) - '0' >= 0 && str.at(i) - '0' <= 9) res += str.at(i) - '0'; //char to int
    }
    return res;
}

bool cmp(string a, string b) {
    if (a.size() != b.size()) return a.size() < b.size();
    // 모든 자리 수 합
    int sum_a = sum(a);
    int sum_b = sum(b);
    if (sum_a != sum_b) return sum_a < sum_b;
    return a < b;
}

int main() {
    int N;
    cin >> N;
    string str;
    vector<string> sn;
    for (int i = 0; i < N; i++) {
        cin >> str;
        sn.push_back(str);
    }
    sort(sn.begin(), sn.end(), cmp);
    for (auto i:sn) cout << i << "\n";
    return 0;
}