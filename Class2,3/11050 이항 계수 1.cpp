#include<iostream>

using namespace std;

int factorial(int n,int k){
    int mul=1;
    for(int i=n;i>0;i--){
        mul*=i;
    }
    return mul;
}

int main(){
    int n,k;cin>>n>>k;
    double up = factorial(n,n-k);
    double down = factorial(k,k)*factorial(n-k,n-k);
    cout<<up/down;
}