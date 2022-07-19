#include<iostream>
#include<queue>

using namespace std;
queue<int> q;

int main(){
    int n; cin>>n;
    int card;
    for(int i=1;i<=n;i++) q.push(i);
    for(int i=0;i<n;i++){
        if(q.size()==1){
            card = q.front();
            break;
        }
        q.pop();
        card = q.front();
        q.pop();
        q.push(card);
    }
    cout<<card;
    return 0;
}