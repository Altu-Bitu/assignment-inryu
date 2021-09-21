#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string toCpp(string str) {
    string res;
    for (auto i:str) {
        if (islower(i)) res += i; //소문자
        else {
            res += "_";
            res += tolower(i);
        }
    }
    return res;
}

string toJava(string str) {
    string res;
    int idx = 0;
    while (idx < str.size()) {
        if (str[idx] != '_') res += str[idx++];
        else {
            res += toupper(str[++idx]);
            idx++;
        }
    }
    return res;
}

int isJava(string str) {
    bool java = false;
    bool cpp = false;

    //첫 글자가 소문자가 아니거나, 마지막이 '_'로 끝나면
    if (!islower(str[0]) || str[str.size() - 1] == '_') return 3;

    for (int i = 1; i < str.size(); i++) {
        if (islower(str[i])) continue; //소문자는 java, cpp 판단 불가
        if (isupper(str[i])) //대문자일 경우
            java = true; //자바
        else if (str[i] == '_') { //'-'가 있을 경우
            if (str[i - 1] != '_') cpp = true; //연속이 아니라면 cpp
            else return 3; // 오류
        }
    }

    if (!java && cpp) return 0; //cpp임
    if (java && !cpp) return 1; //java임
    if (!java && !cpp) return 2; //소문자 한 단어로만 이루어짐
    if ((java && cpp)) return 3; // 둘 다임 -> 오류
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    cin >> str;

    int check = isJava(str);

    if (check == 0) cout << toJava(str) << '\n'; //cpp
    else if (check == 1) cout << toCpp(str) << '\n'; //java
    else if (check == 2) cout << str << '\n'; // 소문자 한 단어
    else if (check == 3) cout << "Error!\n"; //에러
}