//15655 N과M(6)
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M;
int pick[10], arr[10], visit[10];
void pickme(int cnt, int x)
{
	if(x == M){
		for(int i=0; i<M; i++)
			printf("%d ", pick[i]);
		printf("\n");
		return;
	}

	for(int i=cnt; i<N; i++){
		if(visit[i] == 0){
			visit[i] = 1;
			pick[x] = arr[i];
			pickme(i, x+1);
			visit[i] = 0;
		}
	}
}

int main(void)
{
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++)
		scanf("%d", &arr[i]);

	sort(arr, arr+N);
	pickme(0, 0);
}
