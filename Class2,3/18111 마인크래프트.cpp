#include <iostream>

using namespace std;

int main(){
	int N,M,B; scanf("%d %d %d", &N, &M, &B);
	int arr[N][M];
	int num[257];
	int gap[2]={0};
	int flag=0;
	int min=192000000,min_num=0,B_temp=B;
	for(int i =0; i<N; i++) {for(int j=0; j<M; j++)  
			scanf("%d",&arr[i][j]);
	}

	for( int i=0; i<=256; i++) {
		for(int j=0; j<N; j++){	for(int k=0; k<M; k++) { //땅 파기
				if(arr[j][k] >i) {
					gap[0]+= arr[j][k]-i;
					B += arr[j][k] -i;
				}
			}
		}
		for(int j=0; j<N; j++){ for(int k=0; k<M; k++) { //땅 채우기
				if(arr[j][k] <=i){
					gap[1] += i-arr[j][k];
					B -= i-arr[j][k];
				} 
				if(B <0) { gap[1]=64000000; gap[0]=64000000; flag =1; break;}
				
			}
			if (flag ==1) {flag=0; break;}
		}
		num[i] = (gap[0]*2) + (gap[1]);  
		if(num[i] <= min) { min = num[i]; min_num=i; }
        gap[0]=0; gap[1]=0; B = B_temp;
	}
	printf("%d %d",min, min_num);
	
}