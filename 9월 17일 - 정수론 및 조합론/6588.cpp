/* 골드바흐의 추측*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX = 1000000;
vector<bool> is_prime;
vector<int> prime_num;

using namespace std;

//에라토스네테스의 채  (MAX까지 만들어놓기)
void setPrime() {
    is_prime.assign(MAX + 1, true); //처음엔 모두 소수라고 가정

    //소수의 배수들 제거
    for (int i = 2; i <= sqrt(MAX); i++) {
        if (is_prime[i]) { //소수라면
            for (int j = i * i; j <= MAX; j += i) { //왜 i+i가 아니라 i*i일까 근데 이전에 i+i는 제거가 되는 거 같다.
                is_prime[j] = false; //i의 배수 제거
            }
        }
    }
    //소수 저장 (홀수 소수인 3부터 시작)
    for (int i = 3; i <= MAX; i++) {
        if (is_prime[i]) prime_num.push_back(i);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    setPrime();
    while (cin >> n) {
        //소수 중에
        for (int i = 0; i < prime_num[i] < n; i++) {
            int a = prime_num[i]; //작은 소수
            int b = n - a; // 큰 소수

            // a는 소수이고, a+b=n이되는 b가 소수라면
            if (is_prime[b]) {
                cout << n << " = " << a << " + " << b << "\n";
                break; //방법이 여러가지면 하나만.
            }
        }
    }
    return 0;
}
