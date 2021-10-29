/*
 * 입국심사 : https://www.acmicpc.net/problem/3079
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll; //🌟 m * need_time[n - 1]은 int 범위 초과하므로 long long 써주기... 다른 것들도 계산해주다가 형번환 머시기 되면서 뭔가 안되는 거 같다.
vector<ll> need_time;


//time 동안 얼마나 많은 친구 심사 가능?
ll immigration(ll time) {
    ll cnt = 0;
    //각 심사대에서 time동안 심사할 수 있는 명 수 더해주기
    for (int i = 0; i < need_time.size(); i++) {
        cnt += time / need_time[i];
    }
    return cnt;
}

//가능한 최대 시간 중 최대 값
ll upperSearch(ll left, ll right, ll target) {
    ll ans = 0;
    while (left <= right) {
        // mid초 안에 최대 몇 명의 친구들을 심사할 수 있는지
        ll mid = (left + right) / 2;
        ll cnt = immigration(mid);
        //mid시간 안에 충분히 target을 심사할 수 있으면 -> 시간 줄여보기
        if (cnt >= target) {
            ans = mid;
            right = mid - 1;
        } else { //mid시간 안에 target 수를 심사할 수 없으면 -> 시간 늘리기
            left = mid + 1;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m; //입국심사대, 친구 수
    need_time.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> need_time[i];
    }
    sort(need_time.begin(), need_time.end()); //이분 탐색 전 오름차순 정렬 필수

    //최단 시간 : 0
    //최대 시간 : 모두가 제일 시간 많이 걸리는 곳에서 심사하는 경우
    cout << upperSearch(0, m * need_time[n - 1], m) << "\n";
}