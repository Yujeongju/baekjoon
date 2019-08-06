//15650 N과M(2)
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int pick[10], visit[10];
int N, M;
void pickme(int cnt, int x)
{
	if(x == M){
		for(int i=0; i<M; i++)
			printf("%d ", pick[i]);
		printf("\n");
		return;
	}

	for(int i=cnt; i<=N; i++){
		if(visit[i] == 0){
			visit[i] = 1;
			pick[x] = i;
			pickme(i, x+1);
			visit[i] = 0;
		}
	}
}

int main(void)
{
	scanf("%d %d", &N, &M);
	pickme(1, 0);
}
