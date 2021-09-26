//퇴사
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> days(16);
int maxVal = -1;

// day에 상담을 할 것이냐 말 것이냐.
void dfs(int day, int sum) { //(현재 따지고 있는 날짜, 현재까지의 수익)
    if (day > N) {
        maxVal = max(sum, maxVal); //최대 수익 갱신.
        return;
    }

    //1. day 포함
    if (day + days[day].first <= N + 1) {
        dfs(day + days[day].first, sum + days[day].second);
    }

    //2. day 포함X -> 바로 다음날을 따져봄
    dfs(day + 1, sum);
}

int main() {

    cin >> N;
    for (int i = 1; i <= N; i++) {
        int t, p;
        cin >> t >> p;
        days[i] = {t, p};
    }

    dfs(1, 0); //1일부터 상담을 할 것인지 말 것인지 판단
    cout << maxVal << "\n";

}