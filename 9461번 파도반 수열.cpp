#include<iostream>
using namespace std;

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		//이 부분이 long long int가 되어야 한다.
		//더해질수록 숫자가 기하급수적으로 커지기 때문 
		long long int arr[n] = {0};
		arr[0] = arr[1] = arr[2] = 1;
		for(int j=3;j<n;j++){
			arr[j] = arr[j-2] + arr[j-3];
		}
		cout<<arr[n-1]<<endl;
	}
}
