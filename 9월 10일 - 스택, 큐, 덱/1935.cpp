#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    string str;
    stack<double> s;
    vector<double> number;
    double val, res = 0;

    cin >> N >> str;
    while (N--) {
        cin >> val;
        number.push_back(val);
    }

    for (int i = 0; i < str.size(); i++) {
        //문자인 경우
        if (str.at(i) >= 'A' && str.at(i) <= 'Z') {
            s.push(number[str.at(i) - 'A']); //A~Z가 number의 0인덱스부터 순서대로 들어잇음  //스택 삽입
        } else { //연산자인 경우
            //스택에서 2개 꺼내서 계산
            double num1 = s.top();
            s.pop();
            double num2 = s.top();
            s.pop();

            switch (str.at(i)) {
                case '*':
                    res = num2 * num1;
                    break;
                case '/':
                    res = num2 / num1;
                    break;
                case '+':
                    res = num2 + num1;
                    break;
                case '-':
                    res = num2 - num1;
                    break;
            }
            s.push(res); //계산 후 스택에 넣기.
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << res << "\n";
}

