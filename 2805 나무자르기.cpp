#include<iostream>
using namespace std;

int main(){
	int n,m,max=0,left=0,right=0,mid,num=0;
	cin>>n>>m;
	long long sum=0;
	int tree[n];
	for(int i=0;i<n;i++) {
		cin>>tree[i];
		if(max<tree[i]) 
			max = tree[i];
	}
	right=max;
	do{
		mid = (right+left)/2;
		sum=0;
		for(int i=0;i<n;i++){
			if(tree[i]>mid){
				sum+=(tree[i]-mid);
			}
		}
		if(sum>=m){
			if(num<mid) num = mid;
			left = mid+1;
		}
		else right = mid-1;
	}
	while(left<=right);
	cout<<num;
}
