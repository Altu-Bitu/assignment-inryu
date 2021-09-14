#include <vector>
#include <stack>
#include <map>
#include <iostream>

using namespace std;


int main() {
    //우선순위
    map<char, int> m;
    //우선순위 지정. 숫자가 클 수록 큼
    m['+'] = 1;
    m['-'] = 1;
    m['*'] = 2;
    m['/'] = 2;
    string str;
    stack<char> s;
    cin >> str;

    for (auto i:str) {
        //피연산자는 바로 출력
        if (i >= 'A' && i <= 'Z') {
            cout << i;
            continue;
        }

        //연산자
        switch (i) {
            case '(':
                s.push(i);
                break;
            case ')':
                while (s.top() != '(') { //'('가 나올 때까지 들어간 연산자 모두 출력
                    cout << s.top();
                    s.pop();
                }
                s.pop(); //여는 괄호까지 삭제
                break;
            default:
                while (!s.empty() && m[s.top()] >= m[i]) { //현재 스택 top과 비교해서, 우선수위가 이상인 게 있었으면 전부 출력
                    cout << s.top();
                    s.pop();
                }
                s.push(i);
                break;
        }
    }

    //끝까지 출력되지 못한 연산자들
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }

}