#include <string>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

deque<int> makeDq(string arr) {
    string str;
    deque<int> dq;

    //[, ,] 형태에서 숫자 추출하여 덱에 push
    for (auto i:arr) {
        if (i >= '0' && i <= '9') {
            str += i;
            continue;
        }
        if ((i == ']' || i == ',') && !str.empty()) {
            dq.push_back(stoi(str));
            str = "";
        }
    }
    return dq;
}

int main() {
    int T, n;
    string p, arr;
    cin >> T;
    while (T--) {

        cin >> p >> n >> arr;
        bool err = false;
        bool is_reversed = false; //실제로 뒤집지 않고, 변수를 통해 맨 앞문자를 지울 건지 맨 뒷문자를 지울 건지 결정

        deque<int> dq = makeDq(arr);

        for (auto function:p) {
            if (function == 'R') { //뒤집기
                is_reversed = !is_reversed;
            } else { //버리기
                if (dq.empty()) {
                    cout << "error\n";
                    err = true;
                    break;
                }
                if (!is_reversed) { //뒤집히지 않았다면 맨 앞문자 삭제
                    dq.pop_front();
                } else {
                    dq.pop_back(); //뒤집혔다고 가정하고 맨 뒷문자 삭제
                }
            }
        }

        if (err) continue;

        //출력
        cout << "[";
        while (!dq.empty()) {
            if (is_reversed) {
                cout << dq.back();
                dq.pop_back();
            } else {
                cout << dq.front();
                dq.pop_front();
            }
            if (!dq.empty()) cout << ",";

        }
        cout << "]\n";
    }
    return 0;
}

