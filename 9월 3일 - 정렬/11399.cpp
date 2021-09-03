#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N,val;
    vector<int> time;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>val;
        time.push_back(val);
    }
    sort(time.begin(), time.end()); //각각 걸리는 시간 오름차순

    vector<int> require(N);
    require[0]=time[0];

    // 줄 선 순서대로, 각 사람이 돈을 인출하는 데 필요한 시간
    //  -> 앞 사람이 기다린 시간 + 내가 인출하는 데 걸리는 시간
    for(int i=1;i<time.size();i++){
        require[i]=require[i-1]+time[i];
    }

    int res=0;
    for(auto i:require) res+=i;
    cout<<res<<"\n";
    return 0;
}
