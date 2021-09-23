/* GCD 합*/
#include <iostream>
#include <vector>

using namespace std;

//재귀 유클리드 호제
int GCD(int a, int b) {
    if (b == 0) return a; //b가 0이면 a가 최대공약수
    return GCD(b, a % b); //자리 바꾸고 호출
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, n, val;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; i++) {
            cin >> val;
            arr.push_back(val);
        }

        //가능한 모든 쌍

        // 주어지는 수가 모두 1,000,000이고 100개 있으면
        // 1,000,000* (100*99/2) > 2,147,___,___ (int형)
        // 따라서 long long 형 필요!
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                sum += GCD(arr[i], arr[j]);
            }
        }
        cout << sum << "\n";
    }
    return 0;
}

