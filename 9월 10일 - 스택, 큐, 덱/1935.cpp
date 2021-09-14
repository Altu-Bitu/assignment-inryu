#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;

double compute(double num2, double num1, char op) {
    double res;
    switch (op) {
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
    return res;
}

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
        if (isupper(str.at(i))) {
            s.push(number[str.at(i) - 'A']); //A~Z가 number의 0인덱스부터 순서대로 들어잇음  //스택 삽입
            continue;
        }
        //연산자인 경우 스택에서 2개 꺼내서 계산
        double num1 = s.top();
        s.pop();
        double num2 = s.top();
        s.pop();
        s.push(compute(num2, num1, str.at(i))); //계산 후 스택에 넣기.
    }

    cout << fixed;
    cout.precision(2);
    cout << s.top() << "\n";

    return 0;
}



