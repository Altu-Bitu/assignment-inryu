#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s_A, s_B;
    vector<int> res;
    int A[10001], B[10001];
    cin >> s_A >> s_B;
    //역방향으로 삽입 (ex) 123 -> 321)
    for (int i = 0; i < s_A.size(); i++)
        A[i] = s_A[s_A.size() - 1 - i] - '0';
    for (int i = 0; i < s_B.size(); i++)
        B[i] = s_B[s_B.size() - 1 - i] - '0';

    int i = 0;
    int sum = 0;
    for (i = 0; i < max(s_A.size(), s_B.size()); i++) {
        sum = sum + A[i] + B[i];
        if (sum >= 10) {
            res.push_back(sum % 10);
            sum = 1; // 올림수(?) 설정
        } else {
            res.push_back(sum);
            sum = 0; // 올림수(?) 0으로 초기화
        }
    }
    if (sum == 1) res.push_back(1); // 마지막 연산에서 10이 넘었다면.
    for (int j = res.size() - 1; j >= 0; j--) {
        cout << res[j];
    }
    return 0;
}
