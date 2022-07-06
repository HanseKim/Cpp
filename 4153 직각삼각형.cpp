#include<iostream>
#include<algorithm>
using namespace std;

int main(){

    long long triangle[3];
    while(triangle[0]!=0&&triangle[1]!=0&&triangle[2]!=0)
    {
        cin>>triangle[0]>>triangle[1]>>triangle[2];
        if(triangle[0]==0&&triangle[1]==0&&triangle[2]==0)
        {break;}
        sort(triangle,triangle+3);
        for(int i=0;i<3;i++){
            triangle[i] *= triangle[i];
            //cout<<triangle[i]<<" ";
        }
        if(triangle[2] == triangle[0] + triangle[1]) cout<<"right\n";
        else cout<<"wrong\n";
    }
    return 0;
}