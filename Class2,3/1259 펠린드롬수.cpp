#include<iostream>
#include<string>

using namespace std;

bool Is_pelindrom(string s){
	int len = s.length(),left = 0, right = len-1;
	while(left<=right){
		if(s[left] == s[right]){
			left++;
			right--;
		}
		else return false;
	}
	return true;
}

int main(){
	string s;
	do{
		cin>>s;
		if(s=="0") return 0;
		if(Is_pelindrom(s)){
			cout<<"yes"<<endl;
		}
		else cout<<"no"<<endl;
	}
	while(s !="0");
}