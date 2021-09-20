#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


int main() {
    int N;
    int cnt = 1; //처음엔 배정.

    vector<pair<int, int>> Class; //(시작 시간, 끝나는 시간)

    cin >> N;
    for (int i = 0; i < N; i++) {
        int s, t;
        cin >> s >> t;
        Class.push_back(make_pair(s, t));
    }

    sort(Class.begin(), Class.end()); //시작시간 기준으로 오름차순 정렬.

    priority_queue<int, vector<int>, greater<>> T; //최소 힙
    T.push(0); //끝나는 시간 저장.

    for (int i = 0; i < N; i++) {
        int s = Class[i].first; //시작 시간
        int t = Class[i].second; //끝나는 시간

        if (T.top() <= s) { //수업을 바로 들을 수 있으면
            T.pop();
        } else { //아니면
            cnt++; // 강의실 더 필요
        }
        T.push(t); //끝나는 시간 push

    }
    cout << cnt << "\n";
}