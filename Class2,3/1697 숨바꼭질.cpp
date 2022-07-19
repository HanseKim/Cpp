/**
 * @file 1697 숨바꼭질.cpp
 * @author HanseKim(kimbird2002@naver.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-17
 * @see https://www.acmicpc.net/problem/1697
 * @copyright Copyright (c) 2022
 * 
 */
#define MAX 100001
#include<iostream>
#include<queue>

using namespace std;

int main(){
    queue<int> q;
    int dp[MAX+100] = {0};
    int n,k;
    scanf("%d %d",&n,&k);
    q.push(n);

    if(n==k){
        printf("0\n");
        return 0;
    }
    dp[n] = 1;
    while(!q.empty()){
        int p = q.front();
        q.pop();
        int next=0;
        for(int i=0;i<3;i++){
            if(i==0){
                next = p+1;
            }
            else if(i==1){
                next = p-1;
            }
            else next = p*2;
            if(next <0 || next >MAX) continue;
            if(dp[next]) continue;
            dp[next] = dp[p] + 1;
            if(next == p) break;
            q.push(next);
        }
    }
    printf("%d\n",dp[k]-1);
}