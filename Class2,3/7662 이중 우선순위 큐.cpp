/**
 * @file 7662 이중 우선순위 큐.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-17
 * @see https://www.acmicpc.net/problem/7662
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream>
#include<queue>
#include<vector>
#include<set>   //multiset
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    multiset<int> ms;  //중복이 허용되는 걸 사용하기 위해 multiset을 사용
    int t; cin>>t;
    while(t--){
        ms.clear();
        int cnt=0;
        int k; cin>>k;
        while(k--){
            char c; int n;
            cin>>c>>n;
            if(c=='I'){
                ms.insert(n);
                cnt++;
            }
            else if(c=='D'){
                if(!ms.size()){
                    continue;
                }
                else if(n == 1){
                    ms.erase(--ms.end());
                    //m.end()가 마지막 원소가 끝나는 주소값을 반환하기 때문에 --를 붙인다.
                }
                else if(n==-1){
                    ms.erase(ms.begin());
                }
            }
        }
        if(!ms.size()) cout<<"EMPTY\n";
        else{
            cout<<*--ms.end()<<' '<<*ms.begin()<<"\n";
        }
    }
}