/**
 * @file 11727 2xn 타일링 2.cpp
 * @author HanseKim (kimbird2002@naver.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-17
 * @see https://www.acmicpc.net/problem/11727
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream>

using namespace std;

long long int arr[1001];

long long int dp(int n){
    if(n==0) return 0;
    else if(arr[n]==0){
        arr[n] = dp(n-1) + 2*dp(n-2);
    }
    return arr[n]%10007;
}

int main(){
    int n; scanf("%d",&n);
    arr[0] = 0; arr[1] = 1; arr[2] = 3;
    printf("%lld",dp(n));
}