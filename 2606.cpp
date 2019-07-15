//2606 바이러스
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> graph[110];
int visit[110];
int result;

void bfs(int s){
	visit[s] = 1;
	queue<int> q;
	q.push(s);

	while(!q.empty()){
		int tmp = q.front();
		q.pop();

		for(int i=0; i<graph[tmp].size(); i++){
			int current = graph[tmp][i];
			if(visit[current] == 0){
				result++;
				q.push(current);
				visit[current] = 1;
			}
		}

	}
}

int main(void)
{
	int from, to;
	int n, t;
	scanf("%d %d", &n, &t);
	
	for(int i=1; i<=t; i++){
		scanf("%d %d", &from, &to);
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	bfs(1);

	printf("%d\n", result);
}
