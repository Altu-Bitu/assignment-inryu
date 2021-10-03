#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int n;
    cin >> n;
    //🌟 dp[i][j] : i번째 집을 j번째 색깔로 칠할 때 최소비용.
    vector<vector<int>> dp(n + 1, vector<int>(4, 0));

    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;

    int red, green, blue;
    for (int i = 1; i <= n; i++) {
        cin >> red >> green >> blue; //-> 순서대로 빨, 초, 파
        //이전 집 색깔과 달라야 함.
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + red; //빨간색-> 이전집이 초, 파
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + green; //초록색 -> 이전집이 빨, 파
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + blue; //파란색 -> 이전집이 빨, 초
    }

    cout << min(min(dp[n][0], dp[n][1]), dp[n][2]); // n번째 집에서 빨,파,초의 경우중에 최소인 것.

}
