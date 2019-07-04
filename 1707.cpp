//1707 이분그래프
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[20010];
int visit[20010];
int flag = 1;

void dfs(int v, int c)
{
	visit[v] = c;
	for(int i=0; i<graph[v].size(); i++){
		int next = graph[v][i];
		if(visit[next] == 0){
			dfs(next, 3-c);
		}
	}
}

int main(void)
{
	int t, v, e;
	int dot1, dot2;
	int result_flag = 1;
	scanf("%d", &t);

	while(t--){
		flag = 1;
		result_flag = 1;
		memset(visit, 0, sizeof(visit));
		for(int i=0; i<20010; i++){
			graph[i].clear();
		}

		scanf("%d %d", &v, &e);

		for(int i=0; i<e; i++){
			scanf("%d %d", &dot1, &dot2);
			graph[dot1].push_back(dot2);
			graph[dot2].push_back(dot1);
		}

		for(int i=1; i<=v; i++){
			sort(graph[i].begin(), graph[i].end());
		}

		for(int i=1; i<=v; i++){
			if(visit[i] == 0)
				dfs(i,1);
		}

		
		for(int i=1; i<=v; i++){
			for(int j=0; j<graph[i].size(); j++){
				int next_node = graph[i][j];
				printf("%d:%d | %d %d\n", i, j, visit[i], visit[next_node]);
				if(visit[next_node] == visit[i])
					result_flag = 0;
			}
		}

		if(result_flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
}
