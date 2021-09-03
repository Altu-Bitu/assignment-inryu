#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, B, C;
    vector<int> A;

    cin>>N;
    for(int i=0;i<N;i++){
        int val; cin>>val;
        A.push_back(val);
    }
    cin>>B>>C;

    long long cnt=0;

    for(int i=0;i<N;i++){
        if(B>=A[i]) cnt++; //감독관만 있어도 되는 경우
        else{
            int num=(A[i]-B)/C; // 필요한 부감독 수
            if((A[i]-B)%C>0) num++; // 나누어 떨어지지 않으면 한 명 더 필요
            cnt=cnt+1+num; //감독 + 부감독
        }
    }
    cout<<cnt<<"\n";
    return 0;
}