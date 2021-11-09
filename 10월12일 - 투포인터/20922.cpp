/*
 * 겹치는 건 싫어 : https://www.acmicpc.net/problem/20922
 */

#include <iostream>
#include <vector>

using namespace std;
const int MAX = 100000; // 100,000이하의 양의 정수로 이루어진 수열

int findLen(vector<int> &arr, int n, int k) {
    vector<int> cnt(MAX + 1, 0); //각 원소의 최댓값이 100,000이기 때문에 1~100,000까지 카운트 가능
    int ans = 0, left = 0, right = 0;
    //left는 항상 right의 왼쪽 또는 같은 위치에 있어야 함
    while (left <= right && right < n) {
        if (cnt[arr[right]] + 1 <= k) { //현재 right가 가리키는 원소의 카운트 개수 + 포함했을 때의 개수 <= k번
            cnt[arr[right]]++; // right를 포함시켜 줄 것이므로 현재 right가 가리키는 원소의 카운트 값을 늘려줌
            ans = max(ans, (right - left) + 1); //최장 길이 갱신
            right++; // right 포함
        } else { //현재 right가 가리키는 원소를 포함하면 등장 횟수가 k번을 초과
            cnt[arr[left]]--; // 현재 left가 가리키고 있는 원소를 빼줄 것
            left++; //left 오른쪽으로 하나 더해주기
        }
    }
    return ans; //최장길이 return
}

/**
 * 1. 최장 연속 부분 수열의 '길이'를 구해야 함 -> 구간 내의 모든 원소를 고려하기 때문에 한쪽에서 시작하는 투 포인터
 * 2. 각 원소의 최댓값이 100,000이기 때문에 배열로 등장 횟수 체크할 수 있음
 * 3. right를 옮기고 바로 원소를 추가했던 기존 방법과 달리, 일단 포인터만 옮겨놓고 원소를 추가해도 되는지 확인
 */
int main() {
    int n, k; //길이가 n인 수열에서 같은 정수를 k개 이하로 포함한 최장 연속 부분 수열

    //입력
    cin >> n >> k;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    //연산 & 출력
    cout << findLen(arr, n, k);
}