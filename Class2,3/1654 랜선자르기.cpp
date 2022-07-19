#include<iostream>
using namespace std;
int n,k;
long long *a;


long long f(long long b,long long e){
	if(b>=e) return b;
	long long sum=0;
	long long mid = (b+e+1)/2;
	for(int i=0;i<k;i++){
		sum += a[i]/mid;
	}
	if(sum>=n) return f(mid,e);
	if(sum<n) return f(b,mid-1);
}

int main(){
	
	cin>>k>>n;
	a =new long long[k];
	long long max=0;
	for(int i=0;i<k;i++){
		cin>>a[i];
		if(max<a[i]) max = a[i];
	}
	long long begin = 1;
	long long end = max;
	long long mid = max;
	cout<<f(begin,end);
}
