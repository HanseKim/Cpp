#include<iostream>
#include<algorithm>

using namespace std;
int *a;

int b_search(int x,int begin, int end){
	if(begin>end) return 0;
	int mid = (begin+end)/2;
	if(x < a[mid]) return b_search(x,begin,mid-1);
	else if (x> a[mid]) return b_search(x,mid+1,end);
	else if(x == a[mid]) return 1;
}

int main(){
	int n,m;
	cin>>n;
	a = new int[n];
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	cin>>m;
	int b[m];
	for(int i=0;i<m;i++)
		scanf("%d",&b[i]);
	for(int i=0;i<m;i++){
		cout<<b_search(b[i],0,n-1)<<"\n";
	}
}
