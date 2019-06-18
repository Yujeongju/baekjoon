//1018 체스판 다시 칠하기
#include <iostream>
#include <cstdio>

#define INFI 2<<18

int N, M;
int chess[60][60], re_chess[60][60];
void make_chess(int key);
int cnt_check(int x, int y);

int main(void)
{
	int result=INFI, cnt=0;
	char c[50];

	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		scanf("%s", c);
		for(int j=0; j<M; j++){
			if(c[j] == 'B')
				chess[i][j] = 0;
			else
				chess[i][j] = 1;
		}
	}

	/*
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			printf("%d ", chess[i][j]);
		}
		printf("\n");
	}*/
	make_chess(0);
	for(int i=0; i<=N-8; i++){
		for(int j=0; j<=M-8; j++){
			cnt = cnt_check(i, j);
			if(result > cnt)
				result = cnt;
		}
	}

	make_chess(1);
	for(int i=0; i<=N-8; i++){
		for(int j=0; j<=M-8; j++){
			cnt = cnt_check(i, j);
			if(result > cnt)
				result = cnt;
		}
	}

	printf("%d\n", result);
}

void make_chess(int key)
{
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			if(key==0){
				re_chess[i][j] = key;
				key++;
			}
			else{
				re_chess[i][j] = key;
				key--;
			}
		}
		if(key==0)
			key++;
		else
			key--;
	}
}

int cnt_check(int x, int y)
{	
	int cnt=0;
	for(int i=x; i<x+8; i++){
		for(int j=y; j<y+8; j++){
			if(re_chess[i-x][j-y] != chess[i][j])
				cnt++;
		}
	}

	return cnt;
}
