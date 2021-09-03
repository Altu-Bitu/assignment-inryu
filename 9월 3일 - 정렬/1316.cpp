#include <iostream>
#include <vector>
using namespace std;
int N;
int main(){
    cin>>N;
    int cnt=0;
    string str;
    while(N){
        vector<bool> visited(26,0); //알파벳 개수만큼.
        cin>>str;
        cnt++;
        visited[str.at(0)-'a']=true; //맨 첫 캐릭터 체크 // -'a'를 이용해 0인덱스부터 들어가도록.
        for(int i=1;i<str.size();i++){
            if(str.at(i)==str.at(i-1)) continue; //이전 캐릭터와 같다면(연속) continue
            if(visited[str.at(i)-'a']) { //연속해 있지 않고, 이미 방문한 캐릭터
                cnt--;
                break;
            }
            visited[str.at(i)-'a']=true; //처음 본 캐릭터 방문 체크
        }
        N--;
    }
    cout<<cnt<<"\n";
    return 0;
}