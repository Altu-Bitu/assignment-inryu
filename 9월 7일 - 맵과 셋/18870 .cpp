#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    //이거 안해줘서 시간 초과 남 . . ^_^
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, num;
    map<int, int> m;
    vector<int> arr;

    cin >> N;
    while (N--) {
        cin >> num;
        m[num]++; //좌표마다 key값으로 넣어주고 자동으로 오름차순 정렬
        arr.push_back(num); //좌표 순서 기억
    }

    int i = 0;
    for (auto it = m.begin(); it != m.end(); it++) {
        it->second = i++; //it->first 보다 작은 좌표가 몇개 있는지
    }

    for (auto j:arr)
        cout << m[j] << " ";

    return 0;

}
