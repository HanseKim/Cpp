#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main(){
    int n,m; cin>>n>>m;
    vector<string> a,b,ans;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        a.push_back(s);
    }
    sort(a.begin(),a.end());
    for(int i=0;i<m;i++){
        string s;
        cin>>s;
        if(binary_search(a.begin(),a.end(),s)){
            ans.push_back(s);
        }
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<"\n";
    }
}