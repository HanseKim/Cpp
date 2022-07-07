#include<iostream>

using namespace std;

int main(){
    int n,m; scanf("%d",&n);
    int a[10001] = {0,};
    for(int i=0;i<n;i++){
        scanf("%d",&m);
        a[m]++;
    }
    int i=0,j=0;
    while(i<10001){
        j=0;
        if(a[i]>0){
            j = a[i];
            while(j--){
                printf("%d\n",i);
            }
        }
        i++;
    }
}