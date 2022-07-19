#include<iostream>

using namespace std;

int main(){
    int n; scanf("%d",&n);
    int ten=1,zero=0;
    for(int i=1;i<=n;i++){
        ten*=i;
        while(ten%10==0){
            zero++;
            ten/=10;
        }
        ten%=1000;
    }
    printf("%d",zero);
}