//1325 효율적인 해킹
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int visit[10010];
pair<int, int> result[10010];
vector<int> graph[10010];
int N, M;
void bfs(int x){
	queue<int> q;
	visit[x] = 1;
	q.push(x);
	result[x] = make_pair(0, x);

	while(!q.empty()){
		int tmp = q.front();
		q.pop();

		for(int i=0; i<graph[tmp].size(); i++){
			int nxtx = graph[tmp][i];
			if(visit[nxtx] == 0){
				visit[nxtx] = 1;
				q.push(nxtx);
				result[x] = make_pair(result[x].first+1, x);
			}
		}
	}
}

bool comp(pair<int,int> x, pair<int, int> y){
	if(x.first != y.first)
		return x.first > y.first;
	else
		return x.second < y.second;
}

int main(void)
{
	int from, to;
	scanf("%d %d", &N, &M);

	for(int i=0; i<M; i++){
		scanf("%d %d", &to, &from);
		graph[from].push_back(to);
	}

	for(int i=1; i<=N; i++){
		memset(visit, 0, sizeof(visit));
		bfs(i);
	}

	sort(result, result+N+1, comp);

	for(int i=0; i<N; i++){
		if(result[0].first != result[i].first)
			break;
		printf("%d ", result[i].second);
	}
}
