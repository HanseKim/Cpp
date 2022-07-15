#include<iostream>
#include<queue>

using namespace std;

priority_queue<int,vector<int>,greater<int>> pq;

int main(){
    int t; scanf("%d",&t);
    while(t--){
        int x; scanf("%d",&x);
        if(x==0){
            if(pq.empty()) printf("0\n");
            else {
                printf("%d\n",pq.top());
                pq.pop();
            }
        }
        else pq.push(x);
    }
}