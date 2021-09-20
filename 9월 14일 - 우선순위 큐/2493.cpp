#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, input;
    cin >> N;
    vector<int> arr;

    /* 스택에는 신호 수신 가능성이 있는 탑만, top에서부터 우선순위가 큰 순서로 들어가있음.*/
    stack<int> st; //인덱스

    while (N--) {
        cin >> input;
        arr.push_back(input);
    }

    // 제일 왼쪽에 있는 탑
    st.push(0);
    cout << 0 << " ";

    for (int i = 1; i < arr.size(); i++) {
        while (!st.empty()) {
            if (arr[st.top()] < arr[i]) { //우선순위가 큰 것부터 비교해서 수신할 수 없는 것들은 모두 pop
                st.pop();
            } else break; //수신할 수 있는 경우
        }
        if (st.empty()) cout << 0 << " "; // 수신할 탑이 없었을 경우
        else cout << st.top() + 1 << " "; // 있는 경우 수신 탑의 인덱스 출력
        st.push(i); //현재 탑 Push (다음 탑의 왼쪽으로 가장 가까운 탑으로, 우선순위 1등)
    }
    return 0;
}

