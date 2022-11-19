#include<iostream>
#include<algorithm>
using namespace std;

typedef struct People{
    int number;
    int rate=0;
    int pi;
    int qi;
    int ri;
    int gop ;
    int hap ;
    void set(){
        gop = pi*qi*ri;
        hap = pi+qi+ri;
    }
}P;

bool cmp(P p1, P p2){
    if(p1.rate < p2.rate) return true;
    else return false;
}

int main(){
    int n;
    cin>>n;
    P p[n];
    for(int i=0;i<n;i++){
        cin>>p[i].number>>p[i].pi>>p[i].qi>>p[i].ri;
        p[i].set();
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)continue;
            if(p[i].gop > p[j].gop) p[i].rate++;
            if(p[i].gop == p[j].gop && p[i].hap > p[j].hap) p[i].rate++;
            if(p[i].gop == p[j].gop && p[i].hap == p[j].hap && p[i].number > p[j].number) p[i].rate++;
        }
    }
    
    sort(p,p+n,cmp);

    for(int i=0;i<3;i++){
        cout<<p[i].number<<" ";
    }

}