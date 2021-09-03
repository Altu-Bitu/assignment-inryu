#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, val;
    vector<int> A, B;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> val;
        A.push_back(val);
    }
    for (int i = 0; i < N; i++) {
        cin >> val;
        B.push_back(val);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<>()); //근데 B를 재배열해도 되나..

    int res = 0;
    for (int i = 0; i < N; i++) {
        res += A[i] * B[i];
    }
    cout << res << "\n";
    return 0;
}
