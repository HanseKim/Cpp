/**
 * @file 1389 케빈 베이컨의 6단계 법칙.cpp
 * @author HanseKim (kimbird2002@naver.com)
 * @brief BFS문제 한 노드에서 끝노드까지 길이의 총 합이 가장 작은 노드를 구하는 문제이다.
 * @version 0.1
 * @date 2022-07-19
 * @see https://www.acmicpc.net/problem/1389
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream>
#include<queue>

using namespace std;
queue<int> q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin>>n>>m;
    int arr[n+1][n+1]={{0}},connection[n+1][n+1] = {{0}};
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        connection[a][b] = 1; //friend
        arr[a][b] = 1;
        arr[b][a] = 1;
        connection[b][a] = 1;
    }
    for(int i=1;i<=n;i++){
        int visited[n+1] = {0};
        q.push(i);
        visited[i] = 1;
        //cout<<"i : "<<i<<"\n";
        while(!q.empty()){
            //cout<<"q.front() : "<<q.front();
            for(int j=1;j<=n;j++){
                if(j==i) continue;
                if(connection[q.front()][j]){
                    //cout<<" connect: "<<j<<"\n";
                    if(!visited[j]){
                        visited[j] = 1;
                        q.push(j);
                        if(!arr[i][j]){
                            arr[i][j] = arr[i][q.front()] + 1;
                        }
                        else if(arr[i][j] > arr[q.front()][j]){
                            arr[i][j] = arr[q.front()][j];
                        }    
                    }
                }
            }
            q.pop();
        }
    }
    int min,idx=0;
    for(int i=1;i<=n;i++){
        int sum=0;
        for(int j=1;j<=n;j++){
            sum+=arr[i][j];
        }
        if(i==1) {
            idx = i;
            min = sum;
        }
        else if(min > sum) {
            min = sum;
            idx = i;
        }
       // cout<<i<<": "<<sum<<"\n";
    }
    cout<<idx;
}