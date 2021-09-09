#include <iostream>
#include <map>

using namespace std;
int p_sum[200001]; //prefix sum 누적합.

int main() {
    int N, K, val;
    long long res = 0; // 200000*200001/2 개 까지 가능하므로 long long!
    map<int, int> m; //<누적합, 누적합 개수>

    cin >> N >> K;

    //부분합 공식 p_sum[i]-p_sum[j]=K 에서 (j<=i) j는 0이 될 수 있음.
    m[0]++; //인덱스 0까지 누적합은 0이므로

    //인덱스 1부터 i까지의 누적합.
    for (int i = 1; i <= N; i++) {
        cin >> val;
        p_sum[i] = p_sum[i - 1] + val;

        // * 부분합 공식
        // p_sum[i]-K=p_sum[j]
        // 이 되는 p_sum[j]값이 이전에 존재했다면. map에 값이 들어있을 것.
        res += m[p_sum[i] - K];
        m[p_sum[i]]++; //현재까지 부분합 추가해주기.
    }

    cout << res << "\n";
}

