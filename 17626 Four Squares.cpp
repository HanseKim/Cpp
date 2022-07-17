/**
 * @file 17626 Four Squares.cpp
 * @author HanseKim (kimbird2002@naver.com)
 * @brief i*i 전의 dp의 값과 i-1의 dp의 값과 비교하여 작은 값을 가져온다
 * 즉 i^2 전의 수에 + 1 한 값이 더 작을 수 밖에 없으므로 
 * 1 + 1 + 1 + 1 --> 2^2이니까 이런 식으로 진짜 숫자가 + i*i 만큼 될때 +1 을 해준다
 * @version 0.1
 * @date 2022-07-17
 * @see https://www.acmicpc.net/problem/17626
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int n; cin>>n;
    int dp[n+1] = {0};
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        int m = dp[i-1] + 1;
        for(int j=1;j*j<=i;j++){
            m = min(m,dp[i-j*j]);
        }
        dp[i] = m+1;
    }
    cout<<dp[n];
}