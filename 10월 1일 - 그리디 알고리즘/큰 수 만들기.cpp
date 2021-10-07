#include <vector>
#include <iostream>
#include <deque>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    deque<int> dq;

    // 앞쪽 숫자가 커야 함.
    // 제한된 k개를 제거해야하므로, 제거대상 1순위는 앞쪽에 있는 작은 수.
    // 일단 다 넣어보는데 넣을 때 앞에 숫자와 비교해서 앞에 더 작은 것이 있었으면 다 빼
    for (int i = 0; i < number.size(); i++) {
        //일단 넣기 전에
        //앞에서 저장된 수가 더 작으면 큰 게 나올 때 까지 다 뺀다.
        while (!dq.empty() && k > 0 && dq.back() < number[i]) {
            dq.pop_back();
            k--;
        }
        //일단 넣기.
        dq.push_back(number[i]);
    }

    //제거가 다 되지 않은 경우.. ex) 7654321 -> 뒤에서 k개 빼주기
    while (k) {
        dq.pop_back();
        k--;
    }

    //앞에서부터 차례로 정답 만들기.
    while (!dq.empty()) {
        answer += dq.front();
        dq.pop_front();
    }
    return answer;
}


int main() {
    string number = "4177252841";
    int k = 4;

    //연산 &출력
    cout << solution(number, k);

    return 0;
}