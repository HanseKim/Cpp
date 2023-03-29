#include<bits/stdc++.h>
using namespace std;

pair<int,int> shark;
queue<pair<int,int>> q, start, eat;
int T=0,n,**fish,time_[21][21],fish_size=2,eat_cnt=0,dx[4] = {-1,0,0,1}, dy[4] = {0,-1,1,0};

pair<int,int> near(int X,int Y){
    int x,y,min=99999,min_x=0,min_y=0;
    while(!eat.empty()){
        x = eat.front().first; y = eat.front().second;
        if(time_[x][y] < min){
            min = time_[x][y];
            min_x = x; min_y = y;
        }
        else if(time_[x][y] == min){
            if(x < min_x){
                min_x = x; min_y = y;
            }
            else if(x == min_x && y < min_y){
                min_x = x; min_y = y;
            }
        }
        eat.pop();
    }
    return {min_x,min_y};
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin>>n;
    fish = new int*[n]; for(int i=0;i<n;i++) fish[i] = new int[n];
    //input
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>fish[i][j];
            if(fish[i][j]==9) {
                shark = {i,j};
                fish[i][j] = 0;
            }
        }
    }
    start.push(shark);//시작점체크용
    q.push(shark);//처음 bfs용
    while(!start.empty()){
        int X=start.front().first,Y=start.front().second;
        start.pop();
        //initialize
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++) time_[i][j] = 0;
        //bfs
        while(!q.empty()){
            int x = q.front().first, y = q.front().second;
            for(int i=0;i<4;i++){
                if(x+dx[i]>=0 && x+dx[i]<n && y+dy[i]>=0 && y+dy[i]<n){
                    if(fish[x+dx[i]][y+dy[i]] > 0 && fish[x+dx[i]][y+dy[i]] < fish_size){
                        if(time_[x+dx[i]][y+dy[i]]==0){
                            time_[x+dx[i]][y+dy[i]] = time_[x][y] + 1;
                            eat.push({x+dx[i],y+dy[i]});
                        }
                    }
                    else if(fish[x+dx[i]][y+dy[i]] == 0 || fish[x+dx[i]][y+dy[i]] == fish_size){
                        if(time_[x+dx[i]][y+dy[i]]==0){
                            q.push({x+dx[i],y+dy[i]});
                            time_[x+dx[i]][y+dy[i]] = time_[x][y]+1;
                        }
                    }
                }
            }
            q.pop();
        }
        if(!eat.empty()) {
            pair<int,int> near_point = near(X,Y);
            start.push(near_point);
            q.push(near_point);
            fish[near_point.first][near_point.second] = 0;
            T+=time_[near_point.first][near_point.second];
            eat_cnt++;
            if(eat_cnt == fish_size){
                fish_size++;
                eat_cnt=0;
            }
        }
    }
    cout<<T;
}