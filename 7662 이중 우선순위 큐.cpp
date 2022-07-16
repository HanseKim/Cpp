#include<iostream>
#include<queue>
#include<vector>
#include<set>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    multiset<int> ms;
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