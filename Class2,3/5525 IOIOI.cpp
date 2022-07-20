/**
 * @file 5525 IOIOI.cpp
 * @author HanseKim (kimbird2002@naver.com)
 * @brief kmp 알고리즘을 써야 100점 받는 문제,kmp 알고리즘 복습하기
 * @version 0.1
 * @date 2022-07-20
 * @see https://www.acmicpc.net/problem/5525
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream>
#include<cstring>

using namespace std;

char s[1100000], ioi[1100000];
int pi[1100000];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,sum=0; cin>>n>>m>>s;
    ioi[0] = 'I';
    for(int i=1;i<=2*n;i+=2){
        ioi[i] = 'O';
        ioi[i+1] = 'I';
    }
    
    //pi
    
        int num = strlen(ioi);
        int i=-1,j=0; 
        pi[j] = i;
        while(j<num){
            if(i==-1||(i>=0 && ioi[i]==ioi[j] )){
                i++;j++;
                pi[j] = i;
            }
            else i= pi[i];
        }
    
    //find_pattern
    
         num = strlen(s);
         m = strlen(ioi);
         i=0,j=0;
        while(i<num){
            if(j==-1 || (j>=0 && s[i]==ioi[j])) i++,j++;
            else if(s[i]!=ioi[j]) j = pi[j];
            if(j==m){
                sum++;
                j = pi[j];
            }
        }
    cout<<sum; 
}