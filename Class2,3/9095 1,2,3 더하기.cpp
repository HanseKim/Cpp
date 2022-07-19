#include<iostream>
using namespace std;
int arr[12];

int dp(int n){
    if(arr[n]==0){
        arr[n] = dp(n-1) + dp(n-2) + dp(n-3);
    }
    return arr[n];
}

int main(){
    int t; scanf("%d",&t);
    arr[1] = 1; arr[2] = 2; arr[3] = 4;
    for(int i=0;i<t;i++){
        int n; scanf("%d",&n);
        printf("%d\n",dp(n) );
    }
}