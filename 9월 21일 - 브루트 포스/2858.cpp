//기숙사 바닥
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int R, B;
    int L, W; //가로, 세로

    cin >> R >> B;

    /*
     * 1) 2L+2W-4=R
     * 2) (L-2)(W-2)=B
     */

    //2) 식에서 B의 약수를 찾아서 1)이 되는지 확인
    for (int i = 1; i <= B; i++) {
        if (B % i != 0) continue;

        L = i + 2;
        W = B / i + 2;

        if (2 * L + 2 * W - 4 == R) {
            cout << max(L, W) << " " << min(L, W) << "\n";
            break;
        }


    }

    return 0;
}