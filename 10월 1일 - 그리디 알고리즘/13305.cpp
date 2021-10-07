/*
 * 주유소 : https://www.acmicpc.net/problem/13305
 */
#include <vector>
#include <iostream>
#include <queue>

using namespace std;
typedef long long ll; // 도시간 거리와, 리터당 가격이 1,000,000,000 이하

ll solution(queue<pair<ll, ll>> &road) {
    ll ans = 0;
    //주유소 기름 가격들을 앞에서 차례로 보면서
    //뒤에 나보다 비싼 곳이 있으면 현재 주유소에서 미리 충전
    while (!road.empty()) {
        ll liter = road.front().first; //length(km)
        ll cost = road.front().second; //현재 주유소의 1리터당 가격
        road.pop();
        while (!road.empty() && cost < road.front().second) {
            liter += road.front().first;
            road.pop();
        }
        ans += liter * cost;
    }
    return ans;
}


int main() {
    int n;
    //도로의 길이
    cin >> n;
    vector<ll> road_length(n - 1);
    queue<pair<ll, ll>> road;
    for (int i = 0; i < n - 1; i++) {
        cin >> road_length[i];
    }
    ll val;
    for (int i = 0; i < n - 1; i++) {
        cin >> val;
        road.push({road_length[i], val}); //length, cost
    }
    cin >> val;
    cout << solution(road) << "\n";
    return 0;
}