//퇴사2
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
vector<pair<int, int>> days;
vector<int> dp;

int main() {
    int n, t, p;
    cin >> n;
    days.assign(n + 1, {0, 0});
    dp.assign(n + 2, 0);

    for (int i = 1; i <= n; i++) {
        cin >> t >> p;
        days[i] = {t, p};
    }

    //dp[i] : i번째 날의 최대 금액.
    for (int i = 1; i <= n; i++) {
        //i번째 날에
        //상담 하기
        if (i + days[i].first <= n + 1) {
            dp[i + days[i].first] = max(dp[i + days[i].first], dp[i] + days[i].second);
        }
        //상담 안하기
        dp[i + 1] = max(dp[i + 1], dp[i]);
    }

    cout << dp[n + 1] << "\n";
}