#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int cnt = 0;
    map<string, double> m;
    string tree_name;

    while (getline(cin, tree_name)) {  //한 줄씩 입력받기.
        m[tree_name]++;
        cnt++;
    }

    //소숫점 출력 자리수 고정
    cout << fixed;
    cout.precision(4);

    for (auto it = m.begin(); it != m.end(); it++) {
        cout << it->first << " " << (it->second / cnt) * 100 << "\n";
    }
    return 0;
}
