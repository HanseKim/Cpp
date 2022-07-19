#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
queue<int> q;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n=0,m=0,count=0;
		cin>>n>>m;
		int a[101];
		for(int i=0;i<n;i++){
			cin>>a[i];
			q.push(i);
			q.push(a[i]);
		}
		sort(a,a+n);
		int p,index,k=n-1;
		while(k>=0){
			index = q.front();q.pop();
			p = q.front();q.pop();
			//cout<<"k: "<<k<<" a[k]: "<<a[k]<<" index: "<<index<<" p: "<<p<<endl;
			//cout<<count<<endl;
			if(k>=0 && p == a[k]){
				k--;
				count++;
				if(p == a[k+1] && index ==m ) break;
				continue;
			}
			if(k>=0 && p<a[k]){
				q.push(index);q.push(p);
			}
		}
		cout<<count<<"\n";
		while (!q.empty()) q.pop();
	}
	
}
