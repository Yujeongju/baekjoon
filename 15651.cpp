//15651 N과M(3)
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int pick[10], visit[10];
int N, M;
void pickme(int x)
{
	if(x == M){
		for(int i=0; i<M; i++)
			printf("%d ", pick[i]);
		printf("\n");
		return;
	}

	for(int i=1; i<=N; i++){
		pick[x] = i;
		pickme(x+1);
	}
}

int main(void)
{
	scanf("%d %d", &N, &M);
	pickme(0);
}
