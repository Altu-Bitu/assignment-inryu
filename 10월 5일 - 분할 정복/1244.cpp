/*
 *  [스위치 켜고 끄기] : https://www.acmicpc.net/problem/1244
 */
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<bool> btn;

void changeMale(int num) {
    for (int i = num; i <= n; i += num) { //배수
        btn[i] = !btn[i]; //반대로
    }
}

void changeFemale(int num) {
    btn[num] = !btn[num]; //자기 자신
    int size = 0;
    while (true) {
        size++;
        if (num + size > n || num - size < 1) break; //범위 벗어나면
        if (btn[num + size] != btn[num - size]) break; //같지 않으면
        btn[num + size] = !btn[num + size];
        btn[num - size] = !btn[num - size];
    }

}

int main() {
    cin >> n;
    btn.assign(n + 1, false); //스위치 인덱스 : 1~n

    bool val;
    for (int i = 1; i <= n; i++) {
        cin >> val;
        btn[i] = val;
    }

    cin >> m;
    int gender, num;
    while (m--) {
        cin >> gender >> num;
        //입력되는 순서대로 차례대로
        if (gender == 1) {
            changeMale(num);
        } else {
            changeFemale(num);
        }
    }

    // 20개씩 출력
    for (int i = 1; i <= n; i++) {
        cout << btn[i] << " ";
        if (i % 20 == 0) cout << "\n";
    }

}