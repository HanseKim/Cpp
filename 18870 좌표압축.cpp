#include	<iostream>
#include	<map>
using namespace std;

int main(){
	map <int, int> m;
	map <int, int> :: iterator iter;
	int n; cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		m.insert({a[i],i});
	}
	int index=0;
	for (iter = m.begin(); iter != m.end(); ++iter) {
        if(iter == m.begin()) iter->second = index++;
        else iter->second = index++;
	}
	for(int i=0;i<n;i++){
		cout<<m[a[i]]<<" ";
	}
}
