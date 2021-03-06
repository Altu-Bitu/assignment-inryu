/*
 * ๋กค์ผ์ดํฌ : https://www.acmicpc.net/problem/16206
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

        //๐คจ์ํ์ ์ธ ๋ฐฉ๋ฒ
        if (now == 10) ans++;
        else if (now > 10) {
            ans++;
            cake.push_front(now - 10); //์๋ฅด๊ณ  ๋ ๊ฑด ์์ ๋ถ์ด๊ธฐ.
            m--;
        }
    }

    //10์ผ๋ก ์๋ฆฌ๊ณ  ๋จ์๋๋ฐ ์ ์ธ์ค ๊ฒ.
    for (auto i: cake) {
        if (i == 10) ans++;
    }

    return ans;
}

bool cmp(int &a, int &b) {
    if (a % 10 == 0 && b % 10 == 0) return a < b; //๋๋ค 10์ ๋ฐฐ์ -> ์ค๋ฆ์ฐจ์
    else if (a % 10 == 0) return true; //a๋ง 10์ ๋ฐฐ์๋ฉด true (a๊ฐ ์)
    else if (b % 10 == 0) return false; //b๋ง 10์ ๋ฐฐ์๋ฉด false (b๊ฐ ์)
}

int main() {
    int n, m, val;
    cin >> n >> m;
    deque<int> cake; //ํ ๋ฒ์..
    for (int i = 0; i < n; i++) {
        cin >> val;
        cake.push_back(val);
    }
    sort(cake.begin(), cake.end(), cmp);
    cout << solution(cake, m);
    return 0;
}