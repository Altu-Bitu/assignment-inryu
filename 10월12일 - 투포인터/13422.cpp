/*
 * 도둑 : https://www.acmicpc.net/problem/13422
 */

#include <iostream>
#include <vector>

using namespace std;


int steal(vector<int> &house, int n, int m, int k) {
    //윈도우 초기화
    int money = 0; //훔칠 돈
    for (int i = 0; i < m; i++) // m크기의 슬라이딩 윈도우므로, 0~m-1까지
        money += house[i]; // 훔칠 수 있는 돈 초기화

    if (n == m) //훔칠 수 있는 경우 딱 1개인 경우 (집의 개수 == 연속된 집의 개수)
        return money < k; // 방법 장치가 작동하지 않으면 방법 1개, 작동하면 0개

    int ans = 0; // 도둑이 붙잡히지 않고 무사히 마을을 빠져나가기 위해 돈을 훔칠 M개의 연속된 집을 고르는 방법의 수
    int left = 0, right = m - 1; // 슬라이딩 윈도우용 투 포인터 변수
    do { //원형태로 윈도우를 옮겨야 하기 때문에 종료조건은 left가 초기값(=0)이 됐을 때
        if (money < k) //훔칠 수 있음
            ans++; //방법 수 +1

        money -= house[left]; //왼쪽 집 빼주고

        //윈도우의 양 끝 이동
        left = (left + 1) % n; //원형이므로 모듈 연산으로 이동
        right = (right + 1) % n;

        money += house[right]; //오른쪽 집 더해줌
    } while (left);
    return ans; // 방법 수 리턴
}

/**
 * 1. 연속해서 훔쳐야 할 집이 m으로 고정됐기 때문에 슬라이딩 윈도우
 * 2. 직선이 아니라 원 형태의 배열! 모듈러 연산을 통해 윈도우의 양 끝 위치 조절하기
 * !주의! 마을에 있는 집의 개수와 도둑이 훔칠 집의 개수가 같을 때(n==m) 도둑이 훔칠 수 있는 경우의 수 1개!
 */
int main() {
    int t, n, m, k; //순서대로 테스트케이스, 집의 개수, 연속 집의 개수, 방법장치 작동유발 최소 돈의 양.

    cin >> t;
    while (t--) { //테스트케이스만큼
        //입력
        cin >> n >> m >> k;
        vector<int> house(n, 0); //집 베열
        for (int i = 0; i < n; i++)
            cin >> house[i]; //각 집안에 있는 돈의 금액

        //연산 & 출력
        cout << steal(house, n, m, k) << '\n';
    }
}