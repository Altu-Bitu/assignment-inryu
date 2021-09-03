#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int T,N;
    int a,b;
    cin>>T;
    while(T){
        vector<pair<int,int>> score; //서류, 면접
        cin>>N;
        for(int i=0;i<N;i++){
            cin>>a>>b;
            score.push_back({a,b});
        }

        sort(score.begin(), score.end()); //서류 기준으로 오름차순
        int cnt=1;
        int interview_score=score[0].second; ///1위의 면접 점수

        // 그 뒤부턴 면접 순위가 무조건 더 높아야 채용
        for(int i=1;i<N;i++){
            if(score[i].second<interview_score) cnt++;
            interview_score=min(interview_score,score[i].second); // 앞 순위들 중 가장 높은 면접 순위 업데이
        }

        cout<<cnt<<"\n";
        T--;
    }

    return 0;
}
