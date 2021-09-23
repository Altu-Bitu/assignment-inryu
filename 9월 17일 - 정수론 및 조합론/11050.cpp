/* 이항계수 1*/
#include <iostream>

using namespace std;

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    int n, k;
    cin >> n >> k;
    /*
     * 이항계수 공식 : nCr = n! / ((n-k)! * k!)
     */
    cout << factorial(n) / (factorial(n - k) * factorial(k));
}
