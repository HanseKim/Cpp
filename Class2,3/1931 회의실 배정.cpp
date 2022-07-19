/*
 *@author sehankim
 *@date 24 June 2022
 *@see	https://www.acmicpc.net/problem/1931
 *
*/


#include<iostream>
using namespace std;

typedef struct Class{
	int * a;
	struct Class * Next;
}Class;

void QuickSort(Class*c, int start, int end) {
	if (start >= end) // 원소가 1개인 경우 그대로 두기
		return;

	int pivot = start; // 피봇은 첫번째 원소
	int i = start + 1, j = end, temp[2];

	while (i <= j) { // 엇갈릴 때까지 반복
		while (i <= end && (c[i].a[0] <= c[pivot].a[0])) { // 피봇보다 큰 값을 찾을 때까지
			i++;
		}
		while (j > start && (c[j].a[0] >= c[pivot].a[0])) { // 피봇보다 작은 값을 찾을 때까지
			j--;
		}
		

		if (i > j) { // 엇갈린 상태. 피봇보다 작은 값과 피봇과 교체
			temp[0] = c[j].a[0];temp[1] = c[j].a[1];
			c[j].a[0] = c[pivot].a[0]; c[j].a[1] = c[pivot].a[1];
			c[pivot].a[0] = temp[0]; c[pivot].a[1] = temp[1];
		}
		
		if(c[i].a[0] == c[j].a[0]){
			temp[0] = c[i].a[0]; temp[1] = c[i].a[1];
			c[i].a[0] = c[j].a[0]; c[i].a[1] = c[j].a[1];
			c[j].a[0] = temp[0]; c[j].a[1] = temp[1];
		}
		
		else { // 엇갈리지 않았다면 i와 j를 교체
			temp[0] = c[i].a[0]; temp[1] = c[i].a[1];
			c[i].a[0] = c[j].a[0]; c[i].a[1] = c[j].a[1];
			c[j].a[0] = temp[0]; c[j].a[1] = temp[1];
		}
	}

	QuickSort(c, start, j - 1);
	QuickSort(c, j + 1, end);
}

void check_next_class(Class *c,int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(c[i].a[1] <= c[j].a[0]){
				c[i].Next = &(c[j]);
				break;
			}
		}
	}
}

void max(Class*c,int n){
	int max=0,check=0;
	for(int i=0;i<n;i++){
		Class * ptr = &c[i];
		while(ptr){
			check++;
			ptr = ptr->Next;
		}
		if(max<check) max = check;
		check=0;
	}
	cout<<max;
}

int main(){
	int n;
	cin>>n;
	Class* c = new Class[n];
	for(int i=0;i<n;i++){
		c[i].a = new int[2];
		c[i].Next = NULL;
	}
	for(int i=0;i<n;i++) cin>>c[i].a[0]>>c[i].a[1];
	QuickSort(c,0,n-1);
	for(int i=0;i<n;i++) cout<<c[i].a[0]<<" "<<c[i].a[1]<<endl;
	check_next_class(c,n);
	max(c,n);
}
