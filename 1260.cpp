//1260 DFS와 BFS
#include <cstdio>
#include <cstring> // memset
#include <queue> //bfs
#include <stack> //dfs
#include <vector> //graph
#include <algorithm>

using namespace std;

vector<int> graph[1010];
int visit[1010];
int n, m, v;

void dfs(int v){
	stack<int> st;
	st.push(v);
	visit[v] = 1;
	printf("%d ", v);

	while(!st.empty()){
		int current_node = st.top();
		st.pop();
		for(int i=0; i<graph[current_node].size(); i++){
			int next_node = graph[current_node][i];

			if(visit[next_node] == 0){
				printf("%d ", next_node);
				visit[next_node] = 1;
				st.push(current_node);
				st.push(next_node);
				break;
			}
		}
	}
}

void bfs(int v){
	queue<int> q;
	q.push(v);
	visit[v] = 1;

	while(!q.empty()){
		int tmp = q.front();
		q.pop();
		printf("%d ", tmp);
		for(int i=0; i<graph[tmp].size(); i++){
			if(visit[graph[tmp][i]] == 0){
				q.push(graph[tmp][i]);
				visit[graph[tmp][i]] = 1;
			}
		}
	}
}

int main(void)
{
	int x, y;
	scanf("%d %d %d", &n, &m, &v);

	//인접리스트 -> 인접행렬보다 효율적
	for(int i=0; i<m; i++){
		scanf("%d %d", &x, &y);
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	//node에 순차적으로 접근해야하기 때문에 sort
	//1~n인 이유는 정점의 숫자가 1~n
	for(int i=1; i<=n; i++)
		sort(graph[i].begin(), graph[i].end());

	dfs(v);
	memset(visit, 0, sizeof(visit));
	printf("\n");
	bfs(v);
	printf("\n");

	return 0;
}
