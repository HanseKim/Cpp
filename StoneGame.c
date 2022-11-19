#include <stdio.h> 
#include <time.h> 
#include <stdlib.h> 

#define MAX_STONES	10000
// Global Variable - The number of current stones remained
int gn_stones;

/**
* @brief : Determine whether a player can win when the number of stones remained is n 
*          and the number of stones removed in the previous opponent's turn is p
* @return : return 1 if a player can win, 0 otherwise
			return 0 if n == 0
			return 1 if n < 0
* @param : n - the number of stones remained, 
*          p - the number of stones removed in the previous opponent's turn
*/
int win(int n, int p) {
	static int b_win[4][MAX_STONES+1] = {0};
	static int n_max_determined = -1;
	
	if (n<0) return 1;
	if (n_max_determined < 0) {
		//b_win[0][0] = b_win[1][0] = b_win[2][0] = b_win[3][0] = 0;
		b_win[0][1] = b_win[2][1] = b_win[3][1] = 1;
		//b_win[1][1] = 0;
		b_win[0][2] = b_win[1][2] = b_win[2][2] = b_win[3][2] = 1;
		b_win[0][3] = b_win[1][3] = b_win[2][3] = 1;
		//b_win[3][3] = 0;
		n_max_determined = 3;
	}
	
	if (n > n_max_determined) {
		int ni;
		for (ni = n_max_determined+1; ni <= n; ni++) {
            //Enter Your Code
            //배열의 값이 0이면 패배, 1이면 승리
            //Alice_Move2()함수에서 !win()이므로 0값이 리턴이 돼야함

			int i;
            for(i=0; i<=3; i++){            // i 번째 행에 접근하기 위해 0-3범위
	            int j=1;
	            for(j=1; j<=3; j++){        //제거할 돌의 갯수 j -> 1-3 범위
                    if(i==j) continue;      //아래에서 Bob이 제거할 돌의 수와 같으면 안되므로
                    if(!b_win[j][ni-j]){    //다음 턴에서 Bob이 질 경우
                        b_win[i][ni] =1;    //Alice가 이기므로 1로 설정
                        printf("i=%d ni=%d\n",i,ni);
                        break;
                    }
                }
            }
            n_max_determined++;             //4부터 하나하나 체크하면서 올라감 4 전부 체크하고 5로 넘어가는 느낌
		}
	}		
	return b_win[p][n];
}

int Alice_Move2(int n_x) {      //n_x는 Bob이 제거한 돌의 갯수 -> Alice는 n_x만큼 돌을 제거할 수 없다.
    //Alice가 이 상황에서 이길 수 있는지 판단
	if(win(gn_stones,n_x)){     //이길 수 있다면 이기는 상황이 유지되는 최대 값 반환 (문제 조건)
		int i;
		for(i=3;i>=1;i--){      //최대 값을 구해야 하므로 3부터 1까지
			if(i!=n_x){         //Bob이 제거한 돌의 수가 아닐 때만
				if(!win(gn_stones-i,i)) return i; // 다음 시행은 Bob의 차례이므로 Bob이 져야 Alice가 이긴다
                //!win()으로 적은 이유 (엘리스가 이기는 상황을 계속 가져가야하는 문제 조건) , 그때의 제거할 돌의 수를 반환
			}
		}
	}
    //이길 수 없다면 제거할 수 있는 최소 값을 반환(문제에 적혀있는 조건)
    int j=0;
    for(j=1; j<=3; j++){
        if(j!=n_x){     //n_x가 아니면서 최소값을 반환
            return j; 
        }
    }
}
/**
* @brief :  the number of stones to remove in Bob's turn
*		Possble numbers are either 1, 2 or 3
*		In this function, Bob decides his number randomly
* @return : return the decided number 
* @param : The number of stones removed by Alice in the previous turn.
*/
int Bob_Move2(int n_x) {
/*	int n_remove;
	scanf("%d",&n_remove);*/
	int n_remove = rand()%3+1;
	if (n_remove == n_x)
		n_remove = (n_x+1)%3+1;

	return n_remove;
}

/**
* @brief :  Determine whether a further move is possible or not
* @return : return 1 if a further move is possible, 0 otherwise
* @param: none
*/
int can_move2(int n_x) {
	return (gn_stones < 1 || (gn_stones == 1 && n_x == 1)) ? 0 : 1;
}

/**
* @brief :  Determine whether it is legal to remove "n_remove" stones from the current stones
* @return : return 1 if legal, 0 otherwise 
* @param : n_remove - the number of stones that a player try to remove
*	n_x - the number of stones removed by the previous turn.
*/
int is_legal_move2(int n_remove, int n_x) {
	int is_legal = 0;

	if  (n_remove <= gn_stones && n_remove <= 3 && n_remove != n_x)
		is_legal = 1;
	return is_legal;
}

int main(void) {
	int is_alice_turn = 1;
	int n_remove, n_x = 0;
	
	scanf("%d", &gn_stones);
//	gn_stones = 10;
	srand(gn_stones);

	printf("The starting number of stones %d\n", gn_stones);
	while (can_move2(n_x)) {
		if (is_alice_turn) {
			printf("Alice> ");
			n_remove = Alice_Move2(n_x);
		}
		else {
			printf("Bob>>> ");
			n_remove = Bob_Move2(n_x);
		}

		if (is_legal_move2(n_remove, n_x)) {
			printf("%d removed : [%d => %d stones remained]\n", 
				n_remove, gn_stones, gn_stones-n_remove);
			gn_stones -= n_remove;
			n_x = n_remove;
			is_alice_turn = !is_alice_turn;
		}
		else 
			printf("You can't remove %d stones, Try again\n", n_remove);		
	}

	if (is_alice_turn)
		printf("Congratulations Bob, You Win !!!");
	else
		printf("Congratulations Alice, You Win !!!");

	return 0;
}