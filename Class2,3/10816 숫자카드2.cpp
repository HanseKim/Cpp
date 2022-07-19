#include<iostream>
#include<map>

using namespace std;
map<int,int> my;

int main(){
    int n,m;  scanf("%d",&n);
    for(int i=0;i<n;i++){
        int c; cin>>c;
        if(my.find(c)!=my.end()) my[c]++;
        else my.insert({c,1});
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        int num;  scanf("%d",&num);
        if(my.find(num)!=my.end()) 
            printf("%d ",my[num]);
        else printf("0 ");
    }
}