#include<iostream>
using namespace std;

int main(){
	int x,y,w,h;
	cin>>x>>y>>w>>h;
	int min = x, w_x = w-x, h_y = h-y;
	if(min>y) min = y;
	if(min>w_x) min = w_x;
	if(min>h_y) min = h_y;
	cout<<min;
}
