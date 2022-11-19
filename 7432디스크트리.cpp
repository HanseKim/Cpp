#include<bits/stdc++.h>
#define FOR(N) for(int i=0;i<n;i++)
using namespace std;

int n;

typedef struct {
    string name;
    Dir * next;
}Dir;

int main(){
    cin>>n;
    Dir dir[n];
    string str;
    string sep="\\";
    FOR(n){
        string parant;
        cin>>str;
        int cur_pos = 0;
        int pos,idx=0;
        while((pos = str.find(sep, cur_pos)) != std::string::npos){
            if(idx==0) {

            }
        }
    }
}