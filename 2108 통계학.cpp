#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
vector<pair<int,int>> v;

bool compare(pair<int,int>a, pair<int,int>b){
    if(a.second == b.second) return a.first < b.first;
    return a.second>b.second;
}

bool is_used(int num){
    for(int i=0;i<v.size();i++){
        if(v[i].first == num) {
            v[i].second++;
            return true;
        }
    }
    return false;
}

//산술평균
int mean(){
    double sum=0;
    for(int i=0;i<v.size();i++){
        sum+= (v[i].first * v[i].second);
    }
    return round(sum/(double)n);
}

//중앙값
int middle(int * num){
    return num[n/2];
}

//최빈값
int mode(){
    if(v[0].second == v[1].second) return v[1].first;
    return v[0].first;
}

//범위
int range(int * num){
    return num[n-1] - num[0];
}

int main(){
    cin>>n;
    int num[n];
    for(int i=0;i<n;i++){
        cin>>num[i];
        if(is_used(num[i])){}
        else{
            v.push_back(make_pair(num[i],1));
        }
    }
    sort(num,num+n);
    sort(v.begin(),v.end(),compare);
    
    cout<<mean()<<"\n";
    cout<<middle(num)<<"\n";
    cout<<mode()<<"\n";
    cout<<range(num);
    return 0;
}