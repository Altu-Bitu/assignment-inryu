/*
 * 주유소 : https://www.acmicpc.net/problem/13305
 */
#include <vector>
#include <iostream>

using namespace std;
typedef long long ll; // 도시간 거리와, 리터당 가격이 1,000,000,000 이하

ll solution(vector<ll> cost, vector<bool> visited, vector<ll> road_length) {
    ll ans = 0;
    //주유소 기름 가격들을 앞에서 차례로 보면서
    //뒤에 나보다 비싼 곳이 있으면 현재 주유소에서 미리 충전
    for (int i = 0; i < cost.size() - 1; i++) {
        if (visited[i]) continue; //이미 충전된 곳ㅍ ㅐ스
        ll liter = road_length[i]; //현재 충전할 곳의 거리

        // 뒤쪽에 나보다 비싼 주유소
        for (int j = i + 1; j < cost.size() - 1; j++) {
            if (cost[j] >= cost[i] && !visited[j]) {
                liter += road_length[j]; //거리
                visited[j] = 1; //방문 표시
            } else break;
        }
        ans += liter * cost[i];
    }
    return ans;
}

int main() {
    int n;
    //도로의 길이
    cin >> n;
    vector<ll> road_length(n - 1);
    vector<ll> cost(n);
    vector<bool> visited(n, false);
    for (int i = 0; i < n - 1; i++) {
        cin >> road_length[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }
    cout << solution(cost, visited, road_length) << "\n";
    return 0;
}