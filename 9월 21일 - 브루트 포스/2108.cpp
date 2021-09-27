// 통계학
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

double avg(vector<int> &arr) {
    int sum = 0;
    for (auto i: arr) sum += i;
    double avg = sum / (double) arr.size();
    return round(avg); //소수 첫째자리에서 반올림
}

int med(vector<int> &arr) {
    return arr[arr.size() / 2];
}

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    if (a.second != b.second)
        return a.second > b.second; //쓰인 횟수가 많은 순서대로 정렬
    return a.first < b.first; // 쓰인 횟수가 같을 경우, key 오름차순 정렬.
}

int mode(vector<int> &arr) {
    map<int, int> m;
    for (auto i:arr) m[i]++; //횟수 세기

    //횟수 기준 정렬하기 위해 벡터로 assign
    vector<pair<int, int>> vec(m.begin(), m.end());
    sort(vec.begin(), vec.end(), cmp); //정렬

    // 가장 많은 횟수
    int max_val = vec[0].second;

    // 두 번째 값의 횟수도 동일하다면
    if (vec[1].second == max_val) return vec[1].first;
    return vec[0].first;
}

int range(vector<int> &arr) {
    return arr[arr.size() - 1] - arr[0];
}

int main() {
    int N, val;
    cin >> N;
    vector<int> arr;

    for (int i = 0; i < N; i++) {
        cin >> val;
        arr.push_back(val);
    }
    sort(arr.begin(), arr.end());

    cout << avg(arr) << "\n" << med(arr) << "\n" << mode(arr) << "\n" << range(arr) << "\n";
    return 0;

}
