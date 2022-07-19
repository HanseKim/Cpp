/**
 * @file 1780 종이의 개수.cpp
 * @author your name (you@domain.com)
 * @brief 분할정복 알고리즘 어느정도 감 잡은 것 같아서 기분 좋당~ ^^
 * @version 0.1
 * @date 2022-07-18
 * @see https://www.acmicpc.net/problem/1780
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream>
using namespace std;
int n;
int** arr;
typedef struct P{
    int minus =0;
    int zero =0;
    int one = 0;
}P;

P p;

void F(int paper,int x,int y){
    int f = arr[x][y];
    int state=0;
    for(int i=x;i<x+paper;i++){
        for(int j=y;j<y+paper;j++){
            if(arr[i][j] != f){
                state=1; break;
            }
        }
        if(state) break;
    }
    if(state){
        for(int i=0;i<paper;i+=paper/3){
            for(int j=0;j<paper;j+=paper/3){
                F(paper/3,x+i,y+j);
            }
        }
    }
    else{
        if(f==0) p.zero++;
        else if(f==-1) p.minus++;
        else p.one++;
    }
    
}

int main(){
    cin>>n;
    arr = new int*[n];
    for(int i=0;i<n;i++){
        arr[i] = new int[n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    F(n,0,0);
    cout<<p.minus<<"\n"<<p.zero<<"\n"<<p.one;   
}