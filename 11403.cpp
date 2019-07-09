//11403 경로찾기
#include <cstdio>
#include <cstring>

using namespace std;

int input[110][110];
int visit[110][110];
int N, e;

void dfs(int start, int dest){
	input[start][dest] = 1;
	visit[start][dest] = 1;
	for(int i=0; i<N; i++){
		if(visit[start][i]==0 && input[dest][i]==1)
			dfs(start, i);
	}
}

int main(void)
{

	scanf("%d", &N);
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			scanf("%d", &input[i][j]);
		}
	}

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(visit[i][i] == 0 && input[i][j] == 1){
				dfs(i, j);
			}
		}
	}

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			printf("%d ", input[i][j]);
		}
		printf("\n");
	}

}
