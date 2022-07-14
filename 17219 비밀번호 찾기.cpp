#include<iostream>
#include<string>
#include<map>

using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int n,m; cin>>n>>m;
    string site,pass;
    map<string,string> memo;
    for(int i=0;i<n;i++){
        cin>>site>>pass;
        memo.insert({site,pass});
    }
    string find;
    for(int i=0;i<m;i++){
        cin>>find;
        cout<<memo[find]<<"\n";
    }
}