/*
 * IF문 좀 대신 써줘 : https://www.acmicpc.net/problem/19637
 */

// 참고 : https://velog.io/@doontagi/C-map-%ED%81%B4%EB%9E%98%EC%8A%A4%EC%99%80-upperbound-lowerbound-%EB%A9%94%EC%84%9C%EB%93%9C

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<int, string> power;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); //너도 범인이었구나
    int n, m, val;
    string str;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> str >> val;
        power.insert({val, str}); //insert로 안하면 넣은 순서대로 안 됨..
    }

    while (m--) {
        cin >> val;
        //upper_bound : 오른쪽(?) 원소중 val보다 큰 값 중 가장 왼쪽에 있는 원소의 iterator return
        //lower_bound : 오른쪽(?) 원소중 val보다 같거나 큰 값 중 가장 왼쪽에 있는 원소의 iterator return -> 같은 값도 포함!
        cout << power.lower_bound(val)->second << "\n";
    }
}