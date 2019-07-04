//11724 연결 요소의 개수
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> graph[1010];
int visit[1010];
int cnt, v;

void dfs(int v)
{
	stack<int> st;
	st.push(v);
	visit[v] = 1;
	cnt++;

	while(!st.empty()){
		int current_node = st.top();
		st.pop();
		for(int i=0; i<graph[current_node].size(); i++){
			int next_node = graph[current_node][i];
			if(visit[next_node] == 0){
				visit[next_node] = 1;
				st.push(current_node);
				st.push(next_node);
				break;
			}
		}
	}

}

int main(void)
{
	int n, m;
	int u,v;
	scanf("%d %d", &n, &m);

	for(int i=0; i<m; i++){
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for(int i=1; i<=n; i++){
		sort(graph[i].begin(), graph[i].end());
	}

	for(int i=1; i<=n; i++){
		if(visit[i] == 0)
			dfs(i);
	}

	printf("%d\n", cnt);

}
