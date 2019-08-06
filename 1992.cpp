//1992 쿼드트리
#include <cstdio>
#include <algorithm>

using namespace std;

int N, arr[100][100];

void print(int x, int y, int size)
{
	int ck = 1;
	int val = arr[x][y];

	for(int i=x; i<x+size && ck; i++){
		for(int j=y; j<y+size; j++){
			if(val != arr[i][j]){
				ck = 0;
				break;
			}
		}
	}

	if(ck == 0){
		printf("(");
		print(x, y, size/2);
		print(x, y+size/2, size/2);
		print(x+size/2, y, size/2);
		print(x+size/2, y+size/2, size/2);
		printf(")");
	}
	else
		printf("%d", val);
}

int main(void)
{
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			scanf("%1d", &arr[i][j]);

	print(0, 0, N);
	printf("\n");
}

