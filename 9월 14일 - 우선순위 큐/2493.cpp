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
    stack<pair<int, int>> st; //값, 인덱스

    while (N--) {
        cin >> input;
        arr.push_back(input);
    }

    // 제일 왼쪽에 있는 탑
    st.push({arr[0], 0});
    cout << 0 << " ";

    for (int i = 1; i < arr.size(); i++) {
        bool flag = 0;
        while (!st.empty()) {
            if (st.top().first >= arr[i]) { //우선순위가 큰 것부터 비교해서, 수신할 수 있으면
                cout << st.top().second + 1 << " "; // 수신 탑의 인덱스 출력
                flag = 1; // 수신 할 탑이 있을 경우
                break;
            } else { //수신할 수 없는 경우
                st.pop();
            }
        }
        if (!flag) cout << 0 << " "; // 수신할 탑이 없었을 경우
        st.push({arr[i], i}); //현재 탑 Push (다음 탑의 왼쪽으로 가장 가까운 탑으로, 우선순위 1등)
    }

    return 0;
}

