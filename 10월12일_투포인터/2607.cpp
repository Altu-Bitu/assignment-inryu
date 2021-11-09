/*
 * 비슷한 단어 : https://www.acmicpc.net/problem/2607
 */

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
map<char, int> target_map;

bool check(string input) {
    map<char, int> cur_map;
    cur_map = target_map; //맵 복사
    int cnt_one = 0, cnt_minus_one = 0;
    for (auto c: input) { //현재 문자 사용하기
        cur_map[c]--;
    }
    for (auto it = cur_map.begin(); it != cur_map.end(); it++) {
        if (it->second == 1) { //한 문자를 뺀 경우
            cnt_one++;
            continue;
        }
        if (it->second == -1) { //한 문자를 더하거나, 하나의 문자를 다른 문자로 바꿨을 때
            cnt_minus_one++;
            continue;
        }
        if (abs(it->second) > 1) {  //한 개 이상 추가했거나, 한 개 이상 뺐을 때
            return false;
        }
    }
    if (cnt_one == 1 && cnt_minus_one == 1) return true; // 한 문자를 빼고, 한 문자를 추가했을 때 == 하나의 문자를 다른 문자로 바꿨을 때
    if (cnt_one > 1 || cnt_minus_one > 1) return false; // 조건이 여러개 있을 때
    return true; //나머지 경우
}

int main() {
    int n, ans = 0;
    string target, input;

    cin >> n >> target;
    for (auto c: target) {
        target_map[c]++;
    }
    n--;
    while (n--) {
        cin >> input;
        if (check(input)) ans++;
    }
    cout << ans << "\n";
}



