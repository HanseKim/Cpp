#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool compare(string s,string s2){
	if(s.length() == s2.length()) {
		return s<s2;
	}
	
	else return s.length() < s2.length();
}

int main(){
	int n; cin>>n;
	string s[n]; 
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	sort(s,s+n,compare);
	for(int i=0;i<n;i++){
		if(i>0 && s[i] == s[i-1]) continue;
		else cout<<s[i]<<endl;
	}
}
