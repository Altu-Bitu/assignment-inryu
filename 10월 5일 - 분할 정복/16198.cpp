/*
 *  [에너지 모으기] : https://www.acmicpc.net/problem/16198
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> energy;
vector<bool> visited;
int n;
int ans = -2147000000;

int computeEnergy(int x) { //구슬 x를 지웠을 때 얻을 수 있는 에너지
    int lower = x - 1, upper = x + 1;
    //이미 지워진 구슬은 제외시켜야 함.
    while (lower > 0) {
        if (visited[lower]) lower--;
        else break;
    }
    while (upper < n - 1) {
        if (visited[upper]) upper++;
        else break;
    }
    return energy[lower] * energy[upper];
}

void getEnergy(int size, int sum) {
    if (size == 2) { //맨 왼쪽, 맨 오른쪽 2개만 남았을 때
        ans = max(sum, ans);
        return;
    }

    //나머지 중 고르기
    for (int i = 1; i < n - 1; i++) {
        if (!visited[i]) {
            //얻을 수 있는 에너지
            int energy_mul = computeEnergy(i);
            visited[i] = 1;
            getEnergy(size - 1, sum + energy_mul);
            visited[i] = 0;
        }
    }
}

int main() {
    cin >> n;
    energy.assign(n, 0);
    visited.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> energy[i];
    }

    for (int i = 1; i < n - 1; i++) { //맨 처음, 맨 끝 빼고
        visited[i] = 1;
        getEnergy(n - 1, energy[i - 1] * energy[i + 1]); //i번째를 고름.
        visited[i] = 0;
    }
    cout << ans << "\n";
}