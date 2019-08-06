//15649 N과M(1)
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int pick[10], visit[10];
int N, M, cnt;
void pickme(int x)
{
	if(x == M){
		for(int i=0; i<M; i++)
			printf("%d ", pick[i]);
		printf("\n");
		return;
	}

	for(int i=1; i<=N; i++){
		if(visit[i] == 0){
			visit[i] = 1;
			pick[x] = i;
			pickme(x+1);
			visit[i] = 0;
		}
	}
}

int main(void)
{
	scanf("%d %d", &N, &M);

	pickme(0);
}
