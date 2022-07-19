#include<iostream>
#include<algorithm>
using namespace std;
/*
void QuickSort(int* array, int start, int end) {
	if (start >= end)
		return;

	int pivot = start;
	int i = start + 1, j = end, temp;

	while (i <= j) {
			while (i <= end && (array[i] <= array[pivot])) { // �Ǻ����� ū ���� ã�� ������
			i++;
		}
		while (j > start && (array[j] >= array[pivot])) { // �Ǻ����� ���� ���� ã�� ������
			j--;
		}

		if (i > j) {
			temp = array[j];
			array[j] = array[pivot];
			array[pivot] = temp;
		}
		else {
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}

	QuickSort(array, start, j - 1);
	QuickSort(array, j + 1, end);
}
*/

int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    //QuickSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\n";
    }
}