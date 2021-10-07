//RGB 거리 2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 2147000000;
vector<vector<int>> dp;
vector<vector<int>> arr;

void paintColor(int house) {
    dp[house][0] = min(dp[house - 1][1], dp[house - 1][2]) + arr[house][0]; //빨간색-> 이전집이 초, 파
    dp[house][1] = min(dp[house - 1][0], dp[house - 1][2]) + arr[house][1]; //초록색 -> 이전집이 빨, 파
    dp[house][2] = min(dp[house - 1][0], dp[house - 1][1]) + arr[house][2]; //파란색 -> 이전집이 빨, 초
}

int main() {
    int n;
    int ans = MAX;
    cin >> n;
    //🌟 dp[i][j] : i번째 집을 j번째 색깔로 칠할 때 최소비용.
    dp.assign(n + 1, vector<int>(4, MAX));
    arr.assign(n + 1, vector<int>(4, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j]; //i번재 집 j번재 컬러 가격
        }
    }

    //첫 번째 집 색깔 고정, N번째 집에선 첫 번째 집 색 제외
    for (int i = 0; i < 3; i++) { //0,1,2 순으로 첫번재 집 색깔을 고정해봄.
        for (int j = 0; j < 3; j++) {
            if (j == i) dp[1][j] = arr[1][j]; // i번째 색깔을 고정
            else dp[1][j] = MAX; //나머진 min에서 선택 못하도록
        }

        //2번 집부터
        for (int j = 2; j <= n; j++) {
            paintColor(j);
        }

        //첫 집을 색깔 i로 고정했을 때, 마지막 집은 i색 빼고
        for (int j = 0; j < 3; j++) {
            if (i == j) continue;
            ans = min(ans, dp[n][j]); //나머지 색의 경우에서 최소값
        }

    }

    cout << ans << "\n";
}
