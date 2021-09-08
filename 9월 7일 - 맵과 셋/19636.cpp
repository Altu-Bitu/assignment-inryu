#include <iostream>

using namespace std;

int main() {
    int D, T, w, before_base, after_eat, after_base, A;
    int e; //에너지 소비량 = (에너지 섭취량 + 활동 대사량)

    cin >> w >> before_base >> T;
    cin >> D >> after_eat >> A;
    after_base = before_base;

    //1. 기초대사량 고려하지 않은 다이어트
    int w1 = w + D * (after_eat - (after_base + A));
    if (w1 <= 0) cout << "Danger Diet\n";
    else cout << w1 << " " << before_base << "\n";

    //2. 기초대사량 고려
    int flag = 0;

    while (D--) {
        e = after_base + A; //에너지 소비
        w += (after_eat - e);

        //기초 대사량 변화.
        if (abs(after_eat - e) > T) {
            if ((after_eat - e) < 0 && (after_eat - e) % 2 != 0) //홀수 음수.
                after_base += ((after_eat - e) / 2 - 1);
            else after_base += (after_eat - e) / 2;
        }

        if (w <= 0 || after_base <= 0) {
            cout << "Danger Diet\n";
            flag = 1;
            break;
        }
    }

    if (!flag) {
        cout << w << " " << after_base << " ";
        if (before_base - after_base > 0) cout << "YOYO\n";
        else cout << "NO\n";
    }
}