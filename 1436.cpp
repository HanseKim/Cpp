#include<iostream>

using namespace std;

int main(){
    int n; scanf("%d",&n);
    int cnt=0,movie=0;
    while(cnt!=n){
        movie++;
        int temp = movie;
        while(temp){
            if(temp%1000 == 666){
                cnt++;
                break;
            }
            else{
                temp/=10;
            }
        }
    }
    printf("%d",movie);
}