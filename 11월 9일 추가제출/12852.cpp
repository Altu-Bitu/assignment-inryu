/*
 * 1로 만들기 2 : https://www.acmicpc.net/problem/12852
 */

#include <iostream>
#include <vector>

using namespace std;

//역추적
vector<int> back(int x, vector<int> &path) { //x = n부터 역추적 시작
    vector<int> result(0); // 역추적한 루트 저장
    while (x != 0) { //맨 처음 시작 경로가 나올 때 까지
        result.push_back(x); // 역추적한 값 넣고
        x = path[x]; //x는 다음 패스값으로 갱신
    }
    return result; //역추적 루트 리턴
}

//1로 만드는 최소 연산 횟수 리턴
int makeOne(int n, vector<int> &path) {
    vector<int> dp(n + 1, 0); //dp용 배열 dp[i] = (i에 가능한 연산을 적용한 수 중 최소 연산 횟수) + 1
    for (int i = 2; i <= n; i++) { //dp 1~n까지!! 1부터 시작해서 n까지 간다.
        int min_value = dp[i - 1]; //우선 i - 1 연산 적용한 것으로 최소 연산 횟수 저장
        path[i] = i - 1; //i-1 연산 적용한 것으로 생각하고 바로 1 작은 수
        if (!(i % 3) && min_value > dp[i / 3]) { //3으로 나눌 수 있고, 현재 가정해 놓은 최소 연산 회수보다 더 적게 가능하면
            min_value = dp[i / 3]; //min_value 갱신
            path[i] = i / 3; //path 갱신
        }
        if (!(i % 2) && min_value > dp[i / 2]) { //2 나눌 수 있고, 현재 가정해 놓은 최소 연산 회수보다 더 적게 가능하면
            min_value = dp[i / 2];  //min_value 갱신
            path[i] = i / 2;//path 갱신
        }
        dp[i] = min_value + 1; // min_value에서 연산 하나 적용해서 바로 온 거니깐. min_value+1
    }
    return dp[n]; //n에 가능한 연산을 적용한 수 중 최소 연산 횟수
}

/**
 * 기본 문제: 1로 만들기
 *
 * [점화식]
 * dp[i] = (i에 가능한 연산을 적용한 수 중 최소 연산 횟수) + 1
 * dp[i] = min(dp[i / 3], dp[i / 2], dp[i - 1]) + 1
 *
 * [역추적]
 * path: 인덱스가 정수를 나타냄, 해당 수에서 연산을 적용한 다음 수를 저장
 * n부터 역추적 시작
 */

int main() {
    int n;
    //입력
    cin >> n;
    vector<int> path(n + 1, 0); //경로 저장

    //연산
    int ans = makeOne(n, path); //n을 1로 만드는 최소 연산 횟수 //path에 연산 적용한 수 계속 쌓으면서
    vector<int> result = back(n, path); // path를 n부터 역추적해서 벡터에 담기.

    //출력
    cout << ans << '\n'; //최소 연산 횟수
    for (int i = 0; i < result.size(); i++) //역추적한 경로
        cout << result[i] << ' ';
    return 0;
}