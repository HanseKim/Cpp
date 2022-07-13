#include<iostream>
#include<string.h>
using namespace std;

int main(){
    int m; scanf("%d",&m);
    int s=0;
    for(int i=0;i<m;i++){
        int n; char text[7];
        scanf("%s",text);
        if(!strcmp(text,"all")){
            s = (1<<21) - 1;
        }
        else if(!strcmp(text,"empty")){
            s = 0;
        }
        else{
            scanf("%d",&n);
            if(!strcmp(text,"add")){
                s|=(1<<(n));
            }
            else if(!strcmp(text,"remove")){
                //s = s|~(1<<(n));
                s &= ~(1 << n);
            }
            else if(!strcmp(text,"toggle")){
                s^=(1<<(n));
            }
            else if(!strcmp(text,"check")){
                printf("%d\n",(s>>n) & 1);
            }
        }
    }
    return 0;
}