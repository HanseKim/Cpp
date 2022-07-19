#include<iostream>

using namespace std;

long long int arr[1001];

long long int dp(int n){
    if(n==0) return 0;
    else if(arr[n]==0){
        arr[n] = dp(n-1) + dp(n-2);
    }
    return arr[n]%10007;
}

int main(){
    int n; scanf("%d",&n);
    arr[0] = 0; arr[1] = 1; arr[2] = 2;
    printf("%lld",dp(n));
}