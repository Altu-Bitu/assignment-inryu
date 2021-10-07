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

int main() {
    int n, m, val;
    cin >> n >> m;
    deque<int> cake1; //10의 배수
    deque<int> cake2; //10의 배수 아닌 것.
    for (int i = 0; i < n; i++) {
        cin >> val;
        if (val % 10 == 0) cake1.push_back(val);
        else cake2.push_back(val);
    }
    sort(cake1.begin(), cake1.end()); //10의 배수중에서도 작은거부터 처리해야 남는 거 없이 최대한 많이.
    sort(cake2.begin(), cake2.end());

    cake1.insert(cake1.end(), cake2.begin(), cake2.end()); //10의 배수 뒤에 10의 배수 아닌 것 붙이기

    cout << solution(cake1, m);
    return 0;
}