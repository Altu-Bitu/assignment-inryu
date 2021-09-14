#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int T, n;
    string p, arr;

    cin >> T;
    while (T--) {

        vector<int> num_arr;
        cin >> p >> n >> arr;

        string str = "";
        for (auto i:arr) {
            if (i == '[') continue;
            if (i == ',' && str.size() > 0) {
                num_arr.push_back(stoi(str));
                str = "";
            } else if (i == ']' && str.size() > 0) num_arr.push_back(stoi(str));
            else str += i;
        }

        cout << "\n==num arr==\n";
        for (auto i:num_arr) cout << i << " ";
        cout << "\n";

        bool flag = 0;
        for (auto function:p) {
            if (function == 'R' && num_arr.size() > 0) {
                reverse(num_arr.begin(), num_arr.end());
            } else if (function == 'D') {
                if (num_arr.size() == 0) {
                    cout << "error\n";
                    flag = 1;
                    break;
                }
                num_arr.erase(num_arr.begin());
            }
        }

        if (flag) continue;
        cout << "[";
        for (int i = 0; i < num_arr.size() - 1; i++) {
            cout << num_arr[i] << ",";
        }
        cout << num_arr[num_arr.size() - 1] << "]\n";
    }

    return 0;

}

