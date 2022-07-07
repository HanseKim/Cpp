#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int> s;
    int k;scanf("%d",&k);
    for(int i=0;i<k;i++){
        int n; scanf("%d",&n);
        if(!s.empty()&&n==0) s.pop();
        else if(n!=0){
            s.push(n);
        }
    }
    int sum=0;
    while(!s.empty()){
        int m = s.top();
        sum+=m;
        s.pop();
    }
    printf("%d",sum);
}