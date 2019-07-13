//11404 플로이드
#include <cstdio>
#include <algorithm>

#define INF 2<<28

using namespace std;

int N, M;
int graph[110][110];

void floyd(void){
	//from -> to 보다 from -> i -> to가 더 짧을 경우를 찾음
	for(int i=1; i<=N; i++){
		for(int from=1; from<=N; from++){
			//from->i 가 불가능할 경우 continue
			if(graph[from][i] == 0)
				continue;
			//갈 수 있는 정점 모두 탐색
			for(int to=1; to<=N; to++){
				//i와 to가 미연결이거나 from == to라면 continue
				if(graph[i][to] == 0 || from == to)
					continue;

				//한 번도 가지 않은 간선이거나
				//i를 통해 from->i->to가 더 짧을 경우 갱신
				if(graph[from][to] == 0 || graph[from][to] > graph[from][i] + graph[i][to])
					graph[from][to] = graph[from][i] + graph[i][to];
			}
		}
	}
}

int main(void)
{
	int from, to, cost;
	scanf("%d %d", &N, &M);

	for(int i=0; i<M; i++){
		scanf("%d %d %d", &from, &to, &cost);
		if(graph[from][to] == 0)
			graph[from][to] = cost;
		else
			graph[from][to] = min(graph[from][to], cost);
	}

	floyd();

	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}
}
