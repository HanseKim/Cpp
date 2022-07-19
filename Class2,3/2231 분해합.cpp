#include<iostream>

using namespace std;
int arr[1000000] = {0,};

int hap(int i){
    int t = i;
    while(t){
        int n = t%10;
        i+=n;
        t/=10;
    }
    return i;
}

int main(){
    int n;cin>>n;
    int i=0,idx=0;
    while(i<=n){
        idx = hap(i);
        if(arr[idx]==0) arr[idx] = i;
        i++;
    }

    cout<<arr[n];
    return 0;
}