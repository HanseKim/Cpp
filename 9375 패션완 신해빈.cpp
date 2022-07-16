/**
 * @file 9375 패션완 신해빈.cpp
 * @author HanseKim (kimbird2002@naver.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-17
 * @see https://www.acmicpc.net/problem/9375
 * @copyright Copyright (c) 2022
 * 
 */

//ios::sync_with_stdio(false);
//cin.tie(NULL);
//위 두개는 c,c++의 stream의 동기화를 끊는 역할을 해서
//c++에서 위 두개를 쓴다면 C의 입출력을 쓰지않도록 조심해야한다.

#include<iostream>
#include<map>
using namespace std;

map<string,int> m;

int main(){
    int t; scanf("%d",&t);
    while(t--){
        m.clear();
        int n,result=1; scanf("%d",&n);
        for(int i=0;i<n;i++){
            string a,b; cin>>a>>b;
            if(m.find(b)!=m.end()){
                m[b]++;
            }
            else{
                m.insert({b,1});
            }
        }
        for(auto i:m){
            result*= (i.second + 1);
        }
        cout<<result - 1<<"\n";
    }
}