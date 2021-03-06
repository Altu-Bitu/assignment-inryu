#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int n;
    cin >> n;
    //๐ dp[i][j] : i๋ฒ์งธ ์ง์ j๋ฒ์งธ ์๊น๋ก ์น ํ  ๋ ์ต์๋น์ฉ.
    vector<vector<int>> dp(n + 1, vector<int>(4, 0));

    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;

    int red, green, blue;
    for (int i = 1; i <= n; i++) {
        cin >> red >> green >> blue; //-> ์์๋๋ก ๋นจ, ์ด, ํ
        //์ด์  ์ง ์๊น๊ณผ ๋ฌ๋ผ์ผ ํจ.
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + red; //๋นจ๊ฐ์-> ์ด์ ์ง์ด ์ด, ํ
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + green; //์ด๋ก์ -> ์ด์ ์ง์ด ๋นจ, ํ
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + blue; //ํ๋์ -> ์ด์ ์ง์ด ๋นจ, ์ด
    }

    cout << min(min(dp[n][0], dp[n][1]), dp[n][2]); // n๋ฒ์งธ ์ง์์ ๋นจ,ํ,์ด์ ๊ฒฝ์ฐ์ค์ ์ต์์ธ ๊ฒ.

}
