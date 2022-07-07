#include<iostream>

using namespace std;

int main(){
    int n;scanf("%d",&n);
    int weight[n] = {0,}, height[n] = {0,},rank[n] = {0,};
    for(int i=0;i<n;i++){
        scanf("%d %d",&weight[i],&height[i]);
    }
    for(int i=0;i<n;i++){
        rank[i] = 1;
        for(int j=0;j<n;j++){
            if(i==j) continue;
            if(weight[i]<weight[j]&&height[i]<height[j]){
                rank[i]++;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ",rank[i]);
    }
}