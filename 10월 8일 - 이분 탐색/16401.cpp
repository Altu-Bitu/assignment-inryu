/*
 * 과자 나눠주기 : https://www.acmicpc.net/problem/16401
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> cookie;

// 막대의 길이가 len일 때 몇 명의 조카에게 줄 수 있는 가.
int giveCookies(int len) {
    int cnt = 0; //줄 수 있는 총 조카 수
    for (auto c : cookie) {
        while (true) {
            if (c - len >= 0) { //최대한 자를 수 있을만큼 자르면서 개수 세기.
                c -= len;
                cnt++;
            } else break;
        }
    }
    return cnt;
}

//가능한 막대 길이
int upperSearch(int left, int right, int target) {
    int ans = 0;
    while (left <= right) {
        // 막대의 길이 mid
        int mid = (left + right) / 2;
        // 막대의 길이가 mid일 때 몇 명의 조카에게 줄 수 있는 가.
        int kid_num = giveCookies(mid);
        //mid 길이로 target만큼 아이에게 주고도 남음 -> 막대 길이 늘리기
        if (kid_num >= target) {
            ans = mid;
            left = mid + 1;
        } else { //mid길이로 줄 수 없음 -> 막대 길이 줄이기
            right = mid - 1;
        }
    }
    return ans;
}


int main() {
    int m, n;
    cin >> m >> n;
    cookie.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> cookie[i];
    }
    sort(cookie.begin(), cookie.end());

    // 막대의 최소 길이 : 1
    // 막대의 최대 길이 : cookie[n-1]
    // m : target 조카 수
    cout << upperSearch(1, cookie[n - 1], m) << "\n";
}

