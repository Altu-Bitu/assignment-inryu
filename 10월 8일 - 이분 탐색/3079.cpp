/*
 * μκ΅­μ¬μ¬ : https://www.acmicpc.net/problem/3079
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll; //π m * need_time[n - 1]μ int λ²μ μ΄κ³Όνλ―λ‘ long long μ¨μ£ΌκΈ°... λ€λ₯Έ κ²λ€λ κ³μ°ν΄μ£Όλ€κ° νλ²ν λ¨ΈμκΈ° λλ©΄μ λ­κ° μλλ κ±° κ°λ€.
vector<ll> need_time;


//time λμ μΌλ§λ λ§μ μΉκ΅¬ μ¬μ¬ κ°λ₯?
ll immigration(ll time) {
    ll cnt = 0;
    //κ° μ¬μ¬λμμ timeλμ μ¬μ¬ν  μ μλ λͺ μ λν΄μ£ΌκΈ°
    for (int i = 0; i < need_time.size(); i++) {
        cnt += time / need_time[i];
    }
    return cnt;
}

//κ°λ₯ν μ΅λ μκ° μ€ μ΅λ κ°
ll upperSearch(ll left, ll right, ll target) {
    ll ans = 0;
    while (left <= right) {
        // midμ΄ μμ μ΅λ λͺ λͺμ μΉκ΅¬λ€μ μ¬μ¬ν  μ μλμ§
        ll mid = (left + right) / 2;
        ll cnt = immigration(mid);
        //midμκ° μμ μΆ©λΆν targetμ μ¬μ¬ν  μ μμΌλ©΄ -> μκ° μ€μ¬λ³΄κΈ°
        if (cnt >= target) {
            ans = mid;
            right = mid - 1;
        } else { //midμκ° μμ target μλ₯Ό μ¬μ¬ν  μ μμΌλ©΄ -> μκ° λλ¦¬κΈ°
            left = mid + 1;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m; //μκ΅­μ¬μ¬λ, μΉκ΅¬ μ
    need_time.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> need_time[i];
    }
    sort(need_time.begin(), need_time.end()); //μ΄λΆ νμ μ  μ€λ¦μ°¨μ μ λ ¬ νμ

    //μ΅λ¨ μκ° : 0
    //μ΅λ μκ° : λͺ¨λκ° μ μΌ μκ° λ§μ΄ κ±Έλ¦¬λ κ³³μμ μ¬μ¬νλ κ²½μ°
    cout << upperSearch(0, m * need_time[n - 1], m) << "\n";
}