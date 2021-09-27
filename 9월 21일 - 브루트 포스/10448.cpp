//유레카 이론
#include <iostream>
#include <vector>

using namespace std;
vector<int> tri_num;

//1000 이하의 삼각수 계산
void calTrinum() {
    tri_num.push_back(1); //첫 값 명시
    int idx = 1; // dp 시작
    while (tri_num[idx - 1] + (idx + 1) <= 1000) { // 1000 이하의 삼각수까지
        tri_num.push_back(tri_num[idx - 1] + (idx + 1)); // 이전 배열값 + (idx+1);
        idx++;
    }
}

bool checkSum(int n) {
    // 작은 수 부터 모든 tri_num 수를 다 넣어보며 확인
    // n(n+1)/2<1000 일 때 n의 최대값은 50이하이므로
    // 3중 포문을 이용해도 50*50*50 < 1억
    for (int i = 0; i < tri_num.size(); i++) {
        for (int j = 0; j < tri_num.size(); j++) {
            for (int k = 0; k < tri_num.size(); k++) {
                if (tri_num[i] + tri_num[j] + tri_num[k] == n) return true;
            }
        }
    }
    return false;
}


int main() {
    calTrinum();

    int T, n;
    while (T--) {
        cin >> n;
        cout << checkSum(n) << "\n";
    }
}
