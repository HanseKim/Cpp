#include<iostream>
#include<algorithm>

using namespace std;
/*
int min_num_cell_to_repaint(int m, int n, int* board[]) {
	// Enter your code
    int i,j,k,p;
    int b,count,min[100][100]={};
    for(i=0;i+7<m;i++){
        for(j=0;j+7<n;j++){ 
            b = board[i][j];
            count=0;
            for(k=0;k<8;k++){
                if(k%2==0){
                    for(p=0;p<8;p++){
                        if(p%2==0){ 
                            if(board[i+k][j+p] ==b) continue;
                            else count+=1;
                        }
                        else{ 
                            if(board[i+k][j+p]!=b) continue;
                            else count+=1;
                        }
                    }
                }
                else{
                    for(p=0;p<8;p++){
                        if(p%2==0){ 
                            if(board[i+k][j+p]!=b) continue;
                            else count+=1;
                        }
                        else{
                            if(board[i+k][j+p]==b) continue;
                            else count+=1;
                        }
                    }
                }
            }
            min[i][j]=count;
        }
    }
    int mi = min[0][0];
    for(i=0;i+7<m;i++){
        for(j=0;j+7<n;j++){
            if(mi>min[i][j]) mi = min[i][j];
        }
    }
    if(64-mi<mi) mi = 64-mi;
    return mi;
}
*/
int main(void) {
	
	int n,m, n_repaint;
	scanf("%d %d",&n,&m);
    char board[n][m];
	for(int i=0;i<n;i++){
        while (getchar() != '\n');
        for(int j=0;j<m;j++){
            scanf("%c",&board[i][j]);
        }
    }
    int i,j,k,p,c=0;
    char b;
    int count,min=64;
    for(i=0;i+7<n;i++){
        for(j=0;j+7<m;j++){ 
            b = board[i][j];
            count=0;
            for(k=0;k<8;k++){
                if(k%2==0){
                    for(p=0;p<8;p++){
                        if(p%2==0){ 
                            if(board[i+k][j+p] ==b) continue;
                            else count+=1;
                        }
                        else{ 
                            if(board[i+k][j+p]!=b) continue;
                            else count+=1;
                        }
                    }
                }
                else{
                    for(p=0;p<8;p++){
                        if(p%2==0){ 
                            if(board[i+k][j+p]!=b) continue;
                            else count+=1;
                        }
                        else{
                            if(board[i+k][j+p]==b) continue;
                            else count+=1;
                        }
                    }
                }
            }
            count = (count<64-count)?count:64-count;
			if(min>count)
			{
				min = count;
			}
        }
    }
    
    printf("%d",min);
	//n_repaint = min_num_cell_to_repaint(n,m,board);
	//printf("%d\n", n_repaint);
	return 0;
}