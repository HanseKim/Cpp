#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	int n,sum=0;
	cin>>n;
	int arr[n],time[n],total=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	//sort
	sort(arr,arr+n);
	for(int i=0;i<n;i++){
		if(i==0) sum = arr[i];
		else {
			sum += arr[i];
		}
		time[i] = sum;
		total += time[i];
	}
	cout<<total;
}
