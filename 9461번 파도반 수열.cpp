#include<iostream>
using namespace std;

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		//�� �κ��� long long int�� �Ǿ�� �Ѵ�.
		//���������� ���ڰ� ���ϱ޼������� Ŀ���� ���� 
		long long int arr[n] = {0};
		arr[0] = arr[1] = arr[2] = 1;
		for(int j=3;j<n;j++){
			arr[j] = arr[j-2] + arr[j-3];
		}
		cout<<arr[n-1]<<endl;
	}
}
