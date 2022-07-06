#include<iostream>

using namespace std;

int GCD(int n,int m){
    for(int i=n;i>1;i--){
        if(m%i==0){
            if(n%i==0) return i;
        }
    }
    return 1;
}

int LCM(int n, int m,int g){
    return n*m/g;
}

int main(){
    int n,m,g,l;cin>>n>>m;
    if(n<m){
        g = GCD(n,m);
        l = LCM(n,m,g);
    }
    else {
        g = GCD(m,n);
        l = LCM(m,n,g);
    }
    cout<<g<<"\n"<<l;
}