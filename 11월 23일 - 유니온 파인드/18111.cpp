/*
 * 마인크래프트 : https://www.acmicpc.net/problem/18111
 */

#include <iostream>

using namespace std;
#define MAX 500+1
int map[MAX][MAX];
int N, M, B;
int minTime = 2147000000;
int maxHeigt;

int main() {
    cin >> N >> M >> B;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    //높이 0~256까지
    for (int h = 0; h <= 256; h++) {
        int plus = 0;
        int minus = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int sub = map[i][j] - h; //추가해야 되는지 제거해야 되는지
                //제거
                if (sub > 0) {
                    minus += sub;
                } else if (sub < 0) {  //추가
                    plus += -1 * sub;
                }

            }
        }

        if (minus + B >= plus) {
            int time = plus + minus * 2; //소요시간
            if (time <= minTime) {
                minTime = time;
                maxHeigt = h;
            }
        }

    }
    cout << minTime << " " << maxHeigt << "\n";
}

