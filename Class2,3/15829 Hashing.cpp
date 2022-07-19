#include<iostream>
#include<string>
#define M 1234567891
using namespace std;

int main(){
    int l; scanf("%d",&l);
    string s;
    cin>>s;
    unsigned long p=1,hash=0;
    for(int i=0;i<l;i++){
        hash += (s[i] - 'a' + 1) *p;
        hash%=M;
        p*=31;
        p%=M;
    }
    hash %= M;
    cout<<hash;
}