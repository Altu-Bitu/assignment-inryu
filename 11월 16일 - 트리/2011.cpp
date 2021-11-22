/*
 * 암호코드 : https://www.acmicpc.net/problem/2011
 */
//참고 : https://mygumi.tistory.com/137
#include <iostream>
#include <vector>

const int MAX = 5000 + 1;

using namespace std;

/* 1. 5000자리 이하 암호 (숫자)
 * 2. 0은 문자로 바꿀 수 없음
 * 3. 숫자는 1~26
 * 4. d[i] : i번째 자리까지 경우의 수
 *  -> i번째 수 까지 볼 때, 한자리 또는 두 자리 수로 볼 수 있음!
 *  -> 한 자리로 봤을 때 d[i]=d[i-1]
 *  -> (바로 앞 숫자까지 합쳐서) 두 자리로 봤을 때 d[i]=d[i-2]+d[i]
 *
 */

int main() {
    string str;
    cin >> str;
    vector<int> arr(str.size() + 1);
    for (int i = 1; i <= str.size(); i++) //인덱스 1부터 채우기
        arr[i] = str[i - 1] - '0';
    vector<int> dp(MAX + 1, 0); //dp[i] : i번째 자리까지 경우의 수

    dp[0] = 1;

    for (int i = 1; i <= str.size(); i++) {
        if (arr[i] >= 1 && arr[i] <= 9) //한 자리 수
            dp[i] = (dp[i - 1] + dp[i]) % 1000000;

        int num = arr[i - 1] * 10 + arr[i];
        if (num >= 10 && num <= 26) { // 전꺼까지 합쳐서 두자리 숫자로 봤을 때
            dp[i] = (dp[i - 2] + dp[i]) % 1000000;
        }
    }
    cout << dp[str.size()];
}