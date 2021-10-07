/*
 * 롤케이크 : https://www.acmicpc.net/problem/16206
 */

#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int solution(deque<int> cake, int m) {
    int ans = 0;
    while (!cake.empty() && m > 0) {
        int now = cake.front();
        cake.pop_front();

        //🤨수학적인 방법
        if (now == 10) ans++;
        else if (now > 10) {
            ans++;
            cake.push_front(now - 10); //자르고 난 건 앞에 붙이기.
            m--;
        }
    }

    //10으로 잘리고 남았는데 안 세준 것.
    for (auto i: cake) {
        if (i == 10) ans++;
    }

    return ans;
}

bool cmp(int &a, int &b) {
    if (a % 10 == 0 && b % 10 == 0) return a < b; //둘다 10의 배수 -> 오름차순
    else if (a % 10 == 0) return true; //a만 10의 배수면 true (a가 앞)
    else if (b % 10 == 0) return false; //b만 10의 배수면 false (b가 앞)
}

int main() {
    int n, m, val;
    cin >> n >> m;
    deque<int> cake; //한 번에..
    for (int i = 0; i < n; i++) {
        cin >> val;
        cake.push_back(val);
    }
    sort(cake.begin(), cake.end(), cmp);
    cout << solution(cake, m);
    return 0;
}