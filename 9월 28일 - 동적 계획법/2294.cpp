//동전2

#include <iostream>
#include <vector>

const int MAX = 2147000000;

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    //dp[i] : i원을 만들기 위해 사용한 동전의 최소 개수
    vector<int> dp(k + 1, MAX);
    vector<int> coin(n);

    for (int i = 0; i < n; i++) cin >> coin[i];

    dp[0] = 0; //얜 직관적으로.
    //코인 종류 하나씩 넣어보면서 dp
    for (int i = 0; i < n; i++) {
        for (int j = coin[i]; j <= k; j++) {
            //사용하거나, 사용하지 않거나
            //dp[j-coin[i]]+1  : 포함되기 전 + 포함시켜서 1
            dp[j] = min(dp[j], dp[j - coin[i]] + 1);
        }
    }

    if (dp[k] == MAX) cout << "-1\n";
    else cout << dp[k] << "\n";
    return 0;
}