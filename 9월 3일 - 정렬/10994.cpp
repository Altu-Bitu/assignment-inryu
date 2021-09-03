#include <iostream>
using namespace std;
string map[500][500];

//시작 좌표 r,c  / 기준 n
void make_star(int r, int c,int n){
    if(n==0) return;
    //테두리 그리기
    for(int i=0;i<1+4*(n-1);i++){ //행
        for(int j=0;j<1+4*(n-1);j++){ //열
            if(i==0||i==1+4*(n-1)-1) {map[r+i][c+j]="*"; continue;}
            if(j==0||j==1+4*(n-1)-1){map[r+i][c+j]="*"; continue;}
            map[r+i][c+j]=" ";
        };
    }
    make_star(r+2,c+2,n-1);
}

int main(){
    int N; cin>>N;
    make_star(0,0,N); //시작 좌표, 기준 n;

   for(int i=0;i<1+4*(N-1);i++){
       for(int j=0;j<1+4*(N-1);j++) {
           cout<<map[i][j];
       }
       cout<<"\n";
   }
}