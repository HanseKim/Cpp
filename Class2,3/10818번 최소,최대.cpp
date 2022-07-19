#include<iostream>

int main(){
	int n;
	std::cin>>n;
	int arr[n];
	int min,max;
	
	for(int i=0;i<n;i++){
		std::cin>>arr[i];
		if(i==0){
			min = arr[i];
			max = min;
		}
		else {
			if(min > arr[i]) min = arr[i];
			if(max < arr[i]) max = arr[i];
		}
	}
	
	std::cout<<min<<' '<<max;
}
