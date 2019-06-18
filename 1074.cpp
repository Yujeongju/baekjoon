//1074 Z
//분할정복 / 재귀

#include <cstdio>
#include <math.h>

void func(int, int, int);

int N, cnt, result;
int r, c;

int main(void)
{
	scanf("%d %d %d", &N, &r, &c);
	
	int input = pow(2, N);

	func(0, 0, input);
}

void func(int x, int y, int N)
{
	if(y==r && x==c){
		printf("%d\n", result);
		return;
	}
	if(N == 1){
		result++;
		return;
	}

	if(!(x<=c && c<x+N && y<=r && r<y+N)){
		result += N*N;
		return;
	}

	func(x, y, N/2); //좌상
	func(x+N/2, y, N/2); //우상
	func(x, y+N/2, N/2); //좌하
	func(x+N/2, y+N/2, N/2); //우하
}
