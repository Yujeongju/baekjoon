//15652 N과M(4)
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M;
int pick[10];
void pickme(int cnt, int x)
{
	if(x == M){
		for(int i=0; i<M; i++){
			printf("%d ", pick[i]);
		}
		printf("\n");
		return;
	}

	for(int i=cnt; i<=N; i++){
		pick[x] = i;
		pickme(i, x+1);
	}
}

int main(void)
{
	scanf("%d %d", &N, &M);
	pickme(1, 0);
}
