/*
 * 삼각형 만들기 : https://www.acmicpc.net/problem/1448
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    //최대값부터 탐색
    //가장긴변<(다른두변의 합)
    for (int i = 0; i < arr.size() - 2; i++) {
        if (arr[i] < arr[i + 1] + arr[i + 2]) return arr[i] + arr[i + 1] + arr[i + 2];
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //삼각형 조건 : 가장 긴 변의 길이는 다른 두 변의 길이의 합보다 작아야
    sort(arr.begin(), arr.end(), greater<>()); //내림차순 정렬
    cout << solution(arr) << "\n";
}
