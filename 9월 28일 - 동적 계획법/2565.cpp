//전기줄 (LIS로)
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int ans = 0;
    int n, a, b;
    cin >> n;
    vector<pair<int, int>> arr(n);
    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        arr[i] = {a, b};
    }
    sort(arr.begin(), arr.end()); //왼쪽 전봇대 기준으로 정렬

    //왼쪽 전봇대는 오름차순으로 정렬되어있다고 생각하고, 오른쪽 전봇대에서 최장 증가 부분수열이어야 겹치지 않음.
    //dp[i] : arr[i]가 내가 만들고 있는 증가수열의 마지막 원소일때, 그 중 가장 긴 수열의 길이.
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        int max_val = 0;
        for (int j = i - 1; j >= 0; j--) {
            //앞이 더 작으면 해당 원소를 arr[i]바로 앞에 두고 증가수열을 만들 수 있으면)
            if (arr[j].second < arr[i].second && dp[j] > max_val) { //그리고 앞에 원소들 중, 해당 원소를 마지막 원소로 하는 증가수열의 최대 길이값
                max_val = dp[j];
            }
        }
        dp[i] = max_val + 1; // max가 되는 j뒤에 자신을 둠.
        ans = max(ans, dp[i]); //최장 길이 갱신.
    }

    cout << n - ans << "\n"; //최장 길이를 만들 수 없는 나머지 삭제
}
