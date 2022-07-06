#include<iostream>
#include<queue>
using namespace std;
queue<int> q;

void sub(int k){
    while(k--){
        int t = q.front();
        q.pop();
        q.push(t);
    }
}

int main(){
    int n,k,i=0;cin>>n>>k;
    for(int i=0;i<n;i++) q.push(i+1);
    cout<<"<";
    while(!q.empty()){
        sub(k-1);
        if(q.size()==1) break;
        cout<<q.front()<<", ";
        q.pop();
    }
    cout<<q.front()<<">";
}