#include<iostream>
using namespace std;

int square[128][128] = {{0}}, white=0,blue=0;

void cut(int x,int y,int n){
    int f = square[x][y];
    for(int i=x;i<x+n;i++){
        for(int j=y;j<y+n;j++){
            if(square[i][j] != f){
                cut(x,y,n/2);
                cut(x+n/2,y,n/2);
                cut(x,y+n/2,n/2);
                cut(x+n/2,y+n/2,n/2);
                return;
            }
        }
    }
    if(f == 0) white++;
    else blue++;
}

int main(){
    int n; scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&square[i][j]);
        }
    }
    cut(0,0,n);
    printf("%d\n%d",white,blue);
}