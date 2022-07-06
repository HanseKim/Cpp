#include<iostream>
#include<string.h>
using namespace std;

int main(){
    int n;cin>>n;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        int idx=0,l=0,r=0;
        while(s[idx]){
            if(s[idx]=='(') l++;
            else if(s[idx]==')')r++;
            idx++;
            if(r>l) break;
        }
        if(l!=r) cout<<"NO\n";
        else cout<<"YES\n";
    }
}