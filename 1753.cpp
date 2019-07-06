//1753 최단경로
#include <cstdio>
#include <vector>
#include <queue>

#define INF 2<<28

using namespace std;

vector<pair<int, int> > graph[20010];
int dist[20010];
int V,E;

void dijkstra(int src){
	dist[src] = 0;
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, src));

	while(!pq.empty()){
		printf("cost : %d\n", pq.top().first);
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if(dist[here] < cost)
			continue;

		for(int i=0; i<graph[here].size(); i++){
			int current_node = graph[here][i].first;
			int next_dist = cost + graph[here][i].second;

			if(dist[current_node] > next_dist){
				dist[current_node] = next_dist;
				pq.push(make_pair(-next_dist, current_node));
			}
		}
	}
}

int main(void)
{
	int u, v, cost, start;
	scanf("%d %d", &V, &E);

	scanf("%d", &start);
	for(int i=0; i<E; i++){
		scanf("%d %d %d", &u, &v, &cost);
		graph[u].push_back(make_pair(v, cost));
	}

	for(int i=0; i<=V; i++){
		dist[i] = INF;
	}

	dijkstra(start);
	for(int i=1; i<=V; i++){
		if(dist[i] != INF)
			printf("%d\n", dist[i]);
		else
			printf("INF\n");
	}
}
