#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n,m; cin>>n>>m;
    int card[n];
    for(int i=0;i<n;i++) cin>>card[i];
    sort(card,card+n,greater<>());
    int sum=0,fir=0,sec=1,thi=2,temp=0;
    //for(int i=0;i<n;i++) cout<<card[i]<<" ";
    do{
        sum = card[fir] + card[sec] + card[thi];
        if(sum<=m && temp<sum) temp = sum;
        if(thi < n-1) thi++;
        else if(sec<n-2) {
            sec++; thi = sec+1;
        }
        else if(fir<n-3) {
            fir++; sec = fir+1; thi = sec + 1;
        }
    }
    while(fir<n-3);
    //cout<<"\nfir= "<<card[fir]<<" sec= "<<card[sec]<<" thi= "<<card[thi]<<"\n";
    cout<<temp;
}