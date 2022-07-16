#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<pair<int,int>> v;
vector<pair<int,int>> v2;

bool cmp_n(pair<int,int> v1,pair<int,int> v2){
	if(v1.first < v2.first) return v1.first < v2.first;
	else return v1.first > v2.first;
}
bool cmp_idx(pair<int,int> v1,pair<int,int> v2){
	if(v1.second < v2.second) return v1.second < v2.second;
	else return v1.second > v2.second;
}
int main(){
	int n; scanf("%d",&n);
	for(int i=0;i<n;i++){
		int k; scanf("%d",&k);
		v.push_back({k,i});
	}
	sort(v.begin(),v.end());
	/*
	for(int i=0;i<n;i++){
		printf("<f:%d s:%d> ",v[i].first,v[i].second);
	}
	cout<<"\n";
	*/
	int cnt=0;
	for(int i=0;i<n;i++){
		if(i==0){
			v2.push_back({v[i].second,cnt});
		}
		else if(v[i-1].first == v[i].first){
			v2.push_back({v[i].second,cnt});
		}
		else if(v[i-1].first < v[i].first){
			v2.push_back({v[i].second,cnt+1});
			cnt++;
		}
	}
	

	sort(v2.begin(),v2.end());
	for(int i=0;i<n;i++){
		printf("%d ",v2[i].second);
	}
	cout<<"\n";
}