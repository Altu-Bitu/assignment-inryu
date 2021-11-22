/*
 * 14675 : 단절점과 단절섬
 */
#include <iostream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q, a, b, t, k;
    map<int, int> m;
    cin >> n;
    n--;
    while (n--) {
        cin >> a >> b;
        m[a]++;
        m[b]++;
    }
    cin >> q;
    while (q--) {
        cin >> t >> k;
        if (t == 1) { //k가 단절점인지
            if (m[k] >= 2) cout << "yes\n";
            else cout << "no\n";
        } else if (t == 2) { //k가 단절선인지
            cout << "yes\n"; //사이클 없으니까 당연히..?
        }
    }
}
