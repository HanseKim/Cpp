#include<iostream>
#include<queue>
using namespace std;
queue<pair<int,int>> q;
int field[51][51] ={{0}};

void zero(){
    for(int i=0;i<51;i++){
        for(int j=0;j<51;j++){
            field[i][j] = 0;
        }
    }
}

int find(int m, int n){
    int cnt=0,i=0,j=0;
    while(i<m){
        if(field[i][j]==1){
            cnt++;
            field[i][j] = 0;
            q.push({i,j});
            while(!q.empty()){
                int x = q.front().first,y = q.front().second;
                if(field[x+1][y] ==1 && x+1<m){
                    field[x+1][y] = 0;
                    q.push({x+1,y});
                }
                if(field[x][y+1] ==1 && y+1<n){
                    field[x][y+1] = 0;
                    q.push({x,y+1});
                }
                if(field[x][y-1] ==1 && y-1>=0){
                    field[x][y-1] = 0;
                    q.push({x,y-1});
                }
                if(field[x-1][y] ==1 && x-1>=0){
                    field[x-1][y] = 0;
                    q.push({x-1,y});
                }
                q.pop();
            }
        }
        j++;
        if(j>=n){
            j=0;i++;
        }
    }
    return cnt;
}

int main(){
    cin.tie(0);
    int t; scanf("%d",&t);
    for(int o=0;o<t;o++){
        zero();
        int m,n,k; scanf("%d %d %d",&m,&n,&k);
        while(k--){
            int x,y;scanf("%d %d",&x,&y);
            field[x][y] = 1;
        }
        printf("%d\n",find(m,n));
    }
}