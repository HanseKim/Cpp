#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int,int>> v;

bool compare(pair<int,int>a, pair<int,int>b){
    if(a.first==b.first) return a.second<b.second;
    else return a.first<b.first;
}

int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(),v.end(),compare);
    for(int i=0;i<n;i++){
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    }
}