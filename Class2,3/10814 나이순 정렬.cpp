#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct member
{
    int age;
    int idx;
    string name;
}member;
vector<member> v;
bool comp(member a,member b){
    if(a.age == b.age) return a.idx < b.idx;
    return a.age<b.age;
}
int main(){
    int n,age;cin>>n;
    string name;
    
    for(int i=0;i<n;i++){
        cin>>age>>name;member m;
        m.age = age;m.name = name;m.idx=i;
        v.push_back({m.age,m.idx,m.name});
    }
    sort(v.begin(),v.end(),comp);
    for(int i=0;i<n;i++){
        cout<<v[i].age<<" "<<v[i].name<<"\n";
    }
}