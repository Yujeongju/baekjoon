//1389 케빈 베이컨의 6단계 법칙
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>

#define INF 2<<29
using namespace std;

vector<int> graph[110];
int result=INF, visit[110];
int N, M, sum;

void bfs(int v)
{
	queue<pair<int, int> > q;
	q.push(make_pair(v, 0));
	visit[v] = 1;

	while(!q.empty()){
		int tmp = q.front().first;
		int cnt = q.front().second;
		q.pop();

		for(int i=0; i<graph[tmp].size(); i++){
			int nxt = graph[tmp][i];
			if(visit[nxt] == 0){
				int new_cnt = cnt+1;	
				q.push(make_pair(nxt, new_cnt));
				sum += new_cnt;
				visit[nxt] = 1;
			}
		}
	}
}
int main(void)
{
	int from, to, index=0;
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		scanf("%d %d", &from, &to);
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	for(int i=1; i<=N; i++)
		sort(graph[i].begin(), graph[i].end());

	for(int i=1; i<=N; i++){
		memset(visit, 0, sizeof(visit));
		sum = 0;
		bfs(i);
		if(result > sum){
			result = sum;
			index = i;
		}
	}

	printf("%d\n", index);
}
