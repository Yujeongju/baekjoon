//5719 거의 최단경로
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

#define INF 2<<28

using namespace std;

vector<pair<int, int> > graph[510];
vector<pair<int, int> > fastest[510];
int N, M, dist[510];
int visit[510];
void dijkstra(int s){
	fill(dist, dist+N+1, INF);
	dist[s] = 0;
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, s));

	while(!pq.empty()){
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if(dist[here] < cost)
			continue;

		for(int i=0; i<graph[here].size(); i++){
			int current = graph[here][i].first;
			int next_cost = cost + graph[here][i].second;

			if(graph[here][i].second == -1){
				continue;
			}

			//printf("dist[current] : %d\nnext_cost : %d\n", dist[current], next_cost);
			if(dist[current] > next_cost){
				dist[current] = next_cost;
				pq.push(make_pair(-next_cost, current));

				fastest[current].clear();
				fastest[current].push_back(make_pair(here, next_cost));
			}
			else if(dist[current] == next_cost){
				fastest[current].push_back(make_pair(here, next_cost));
			}
		}
	}
}

void del_fastest(int e){
	memset(visit, 0, sizeof(visit));
	queue<int> q;
	q.push(e);

	while(!q.empty()){
		int here = q.front();
		q.pop();

		for(int i=0; i<fastest[here].size(); i++){
			int current = fastest[here][i].first;

			//거꾸로 추적하는 것이므로 graph[current]를 확인
			for(int i=0; i<graph[current].size(); i++){
				if(graph[current][i].first == here)
					graph[current][i].second = -1;
			}
			q.push(current);
		}
	}
}

int main(void)
{
	int from, to, cost;
	int start, end;
	while(1){
		scanf("%d %d", &N, &M);
		if(N == 0  && M == 0)
			break;

		for(int i=0; i<=N; i++){
			graph[i].clear();
			fastest[i].clear();
		}

		scanf("%d %d", &start, &end);

		for(int i=0; i<M; i++){
			scanf("%d %d %d", &from, &to, &cost);
			graph[from].push_back(make_pair(to, cost));
		}

		dijkstra(start);
		del_fastest(end);
		dijkstra(start);

		if(dist[end] == INF)
			printf("-1\n");
		else
			printf("%d\n", dist[end]);

	}
}
