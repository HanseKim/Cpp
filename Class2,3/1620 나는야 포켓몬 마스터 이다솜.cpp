#include<iostream>
#include<map>
#include<vector>
using namespace std;
map<string,int> poketmon;
vector<string> v;
int main(){
    cin.tie(0);
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        string name; cin>>name;
        poketmon.insert({name,i});
        v.push_back(name);
    }
    for(int i=0;i<m;i++){
        string find; cin>>find;
        if(find[0] >= '0' && find[0] <= '9'){
            int num = stoi(find);
            printf("%s\n",v[num-1].c_str());
        }
        else{
            printf("%d\n",poketmon[find]);
        }
    }
}