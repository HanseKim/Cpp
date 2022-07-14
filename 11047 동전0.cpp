#include<iostream>

using namespace std;

int main(){
    int n,k; scanf("%d %d",&n,&k);
    int money[n];
    for(int i=0;i<n;i++){
        scanf("%d",&money[i]);
    }
    int idx=n-1,cnt=0;
    while(k>0 && idx>=0){
        if(k/money[idx] > 0){
            cnt += k/money[idx];
            k%=money[idx];
        }
        else {
            idx--;
        }
    }
    printf("%d",cnt);
}