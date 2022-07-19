/**
 * @file 1541 잃어버린 괄호.cpp
 * @author HanseKim (kimbird2002@naver.com)
 * @brief 파싱을 사용하는 거라고 적혀있지만 그냥 내맘대로 알고리즘 사용해서 품
 * @version 0.1
 * @date 2022-07-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream>
#include<string>

using namespace std;

int main(){
    string s;
    int state=0,n=0,i=0,sum=0;
    cin>>s;
    while(s[i]!='\0'|| i<s.size()){
        if(state==0 && s[i] == '+'){
            sum+=n;
            n=0;
            i++;
        }
        else if(state==0 && s[i] == '-'){
            state=1;
            sum+=n;
            n=0;
            i++;
        }
        else if(state && s[i] == '+'){
            sum-=n;
            n=0;
            i++;
        }
        else if(state && s[i] == '-'){
            state=0;
            sum-=n;
            n=0;
        }
        else{
            n*=10;
            n+=s[i] - '0';
            i++;
        }
        //cout<<"state: "<<state<< " sum="<<sum<<" n:"<<n<<"\n";
    }
    if(state){
        sum-=n;
    }
    else sum+=n;
    cout<<sum;
}