/**
 * @file 18870 좌표압축.cpp
 * @author HanseKim
 * @brief 
 * @version 0.1
 * @date 2022-07-17
 * @see https://www.acmicpc.net/problem/18870
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<pair<int,int>> v;
vector<pair<int,int>> v2;

int main(){
	int n; scanf("%d",&n);
	for(int i=0;i<n;i++){
		int k; scanf("%d",&k);
		v.push_back({k,i});
	}
	sort(v.begin(),v.end());
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