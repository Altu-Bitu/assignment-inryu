/*
 *  킹 : https://www.acmicpc.net/problem/1063
 */
#include <iostream>

using namespace std;

bool map[9][9];
//R,L,B,T,RT,LT,RB,LB 순으로 방향벡터
int dr[8] = {0, 0, 1, -1, -1, -1, 1, 1};
int dc[8] = {1, -1, 0, 0, 1, -1, 1, -1};

int direction(string op) {
    if (op == "R") {
        return 0;
    } else if (op == "L") {
        return 1;
    } else if (op == "B") {
        return 2;
    } else if (op == "T") {
        return 3;
    } else if (op == "RT") {
        return 4;
    } else if (op == "LT") {
        return 5;
    } else if (op == "RB") {
        return 6;
    } else if (op == "LB") {
        return 7;
    }
}

int main() {
    char king_alpha, rock_alpha;
    int king_r, king_c, rock_r, rock_c;
    int num;
    cin >> king_alpha >> king_r >> rock_alpha >> rock_r >> num;

    king_r = abs(9 - king_r);
    rock_r = abs(9 - rock_r);
    king_c = king_alpha - 'A' + 1;
    rock_c = rock_alpha - 'A' + 1;

    while (num--) {
        string op;
        int d;
        cin >> op;
        d = direction(op); //방향 인덱스 결정
        int king_nr = king_r + dr[d];
        int king_nc = king_c + dc[d];
        if (king_nr > 8 || king_nr < 1 || king_nc > 8 || king_nc < 1) continue; //범위 확인
        //이동
        king_r = king_nr;
        king_c = king_nc;

        //돌이 있는 곳으로 갔는지 확인
        if (king_r == rock_r && king_c == rock_c) {
            int rock_nr = rock_r + dr[d];
            int rock_nc = rock_c + dc[d];
            if (rock_nr > 8 || rock_nr < 1 || rock_nc > 8 || rock_nc < 1) continue; //범위 확인
            //이동
            rock_r = rock_nr;
            rock_c = rock_nc;
        }

        //여기선 마지막 좌표 출력이 잘 되는데 왜 어떤 테케에서만.... 정답 출력에서 값이 다르지?
//        cout << "king :" << king_r << " " << king_c << "\n";
//        cout << "rock :" << rock_r << " " << rock_c << "\n\n";
    }

    // while문 빠져나오고 이거 값이 달라짐
//    cout << "king :" << king_r << " " << king_c << "\n";
//    cout << "rock :" << rock_r << " " << rock_c << "\n\n";

    cout << char(king_c + 64) << abs(9 - king_r) << "\n" << char(rock_c + 64) << abs(9 - rock_r) << "\n";
}
