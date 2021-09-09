#include <iostream>
#include <vector>
#include <map>
#include <algorithm>


//시간초과
using namespace std;

int N, K, val;
vector<int> A;
int res;
int cnt;

void dfs(int start, int end, int sum) {

    if (sum == K) {
        res++;
        // return하지 않고 더 해봐도 된다.
    }
    if (end == N - 1) {
        return;
    }
    dfs(start, end + 1, sum + A[end + 1]);
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> val;
        A.push_back(val);
    }

    for (int i = 0; i < N - 1; i++) {
        dfs(i, i, A[i]); //시작인덱스 , 끝인덱스, 합
    }

    cout << res << "\n";
}

