/**
 * @file 11659 구간 합 구하기 4.cpp
 * @author HanseKim (kimbird2002@naver.com)
 * @brief 시간초과 때문에 누적 합 an = S(n) - S(n-1)을 사용한다.
 * @version 0.1
 * @date 2022-07-17
 * @see https://www.acmicpc.net/problem/11659
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream>
using namespace std;

int main(){
    int n,m; scanf("%d %d",&n,&m);
    int arr[n],S[n+1] = {0};
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
        if(i==0) S[i] = arr[i];
        else S[i] = S[i-1] + arr[i];
    }
    while(m--){
        long long int sum=0;
        int a,b; scanf("%d %d",&a,&b);
        sum = S[b] - S[a-1];
        printf("%d\n",sum);
    }
}