#include<iostream>
#include<cmath>
using namespace std;

long long z(long long n,long long r, long long c)
{
	if(n==1) return 0;
	if(r < n/2 && c < n/2) return z(n/2,r,c);
	
	else if(r >= n/2 && c < n/2 && r<n) 
		return n*n/2 + z(n/2,r-n/2,c);
	
	else if(r< n/2 && c>= n/2 && c<n)
		return n*n/4 + z(n/2,r,c - n/2);
	
	else if(r>=n/2 && c>=n/2 && r<n && c<n)
		return 3*n*n/4 + z(n/2,r-n/2,c-n/2);
}

int main(){
	long long n,r,c;
	cin>>n>>r>>c;
	cout<<z(pow(2,n),r,c);
	return 0;
}
