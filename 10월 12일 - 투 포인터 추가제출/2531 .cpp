/*
 * 초밥 : https://www.acmicpc.net/problem/2531
 */

#include <iostream>
#include <vector>

using namespace std;

int chooseSushi(vector<int> &belt, int n, int d, int k, int c) {
    vector<int> sushi(d + 1, 0); // d: 초밥 가짓수 , 즉 각 종류별로 먹은 초밥 개수 카운트용

    //쿠폰으로 먹은 초밥
    int section_sushi = 1; // 초밥 가짓수
    sushi[c]++; //쿠폰 번호에 있는 초밥 먹은 걸로

    //윈도우 초기화
    for (int i = 0; i < k; i++) { // 0~k-1까지 k개 먹기
        sushi[belt[i]]++; //해당 벨트에 있는 초밥 먹기
        if (sushi[belt[i]] == 1) // 처음 먹은 거라면
            section_sushi++; // 초밥 가짓수 올려주기
    }

    int ans = section_sushi; // 초기 윈도우에서 먹을 수 있는 초밥 가짓수
    int left = 0, right = k - 1; // 윈도우를 이용할 투 포인터 변수
    do { //원형태로 윈도우를 옮겨야 하기 때문에 종료조건은 left가 초기값(=0)이 됐을 때
        sushi[belt[left]]--; //왼쪽꺼 안먹기
        if (!sushi[belt[left]]) //왼쪽 초밥 종류 하나 안먹었더니 카운트가 0이 됐으면
            section_sushi--; //아예 못먹는 종류니깐 하나 빼주기

        //윈도우의 양 끝 이동
        left = (left + 1) % n; //원형 배열이므로 모듈러로 계산
        right = (right + 1) % n;

        sushi[belt[right]]++; // 오른쪽 스시 먹기
        if (sushi[belt[right]] == 1) //동일하게, 처음 먹은 거면
            section_sushi++; //스시 개수 늘려주기

        ans = max(ans, section_sushi); // 최대 스시 종류 수 값 갱신
    } while (left);
    return ans; //최대 스시 종류 수 값 리턴
}


//1. 벨트 임의의 한 위치부터 k개의 접시를 연속해서 먹을 경우 할인된 정액 가격
//2. 1의 경우 쿠폰에 쓰여진 초밥 하나 추가 무료 제공. (현재 벨트에 없어도 만들어서 제공)
/**
 * 1. 연속해서 먹어야 할 접시가 k로 고정됐기 때문에 슬라이딩 윈도우
 * 2. 직선이 아니라 원 형태의 배열! 모듈러 연산을 통해 윈도우의 양 끝 위치 조절하기
 * 3. 쿠폰으로 먹은 초밥을 먼저 고려해놓기
 * 4. 초밥의 종류가 최대 3000개로 많지 않음. 보석 쇼핑 문제처럼 각 종류별 먹은 초밥의 개수를 세어주기
 */
int main() {
    int n, d, k, c; //순서대로 벨트에 놓인 접시 수, 초밥 가짓수, 연속 접시 수, 쿠폰 번호

    //입력
    cin >> n >> d >> k >> c;
    vector<int> belt(n, 0);
    for (int i = 0; i < n; i++)
        cin >> belt[i]; //초밥 종류

    //연산 & 출력
    cout << chooseSushi(belt, n, d, k, c);
}