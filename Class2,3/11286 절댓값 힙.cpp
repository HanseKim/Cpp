/**
 * @file 11286 절댓값 힙.cpp
 * @author HanseKim (kimbird2002@naver.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-25
 * @see https://www.acmicpc.net/problem/11286
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

int main(){
    int n; cin>>n;
    while(n--){
        int x; cin>>x;
        if(x==0){
            if(pq.empty()) cout<<0<<"\n";
            else{
                cout<<pq.top().second<<"\n";
                pq.pop();
            }
        }
        else{
            pq.push(make_pair(abs(x),x));
        }
    }
}