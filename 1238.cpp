//1238 파티
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>

#define INF 2<<28

using namespace std;

int N, M, X;
vector<pair<int, int> > graph[1010];
int dist[1010];

void dijkstra(int s){
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
	int from, to, cost;
	int result=0;
	scanf("%d %d %d", &N, &M, &X);

	for(int i=0; i<M; i++){
		scanf("%d %d %d", &from, &to, &cost);
		graph[from].push_back(make_pair(to, cost));
	}
	
	for(int i=0; i<=N; i++){
		dist[i] = INF;
	}

	for(int s=1; s<=N; s++){
		for(int i=0; i<=N; i++){
			dist[i] = INF;
		}
		dijkstra(s);
		to = dist[X];

		for(int i=0; i<=N; i++){
			dist[i] = INF;
		}
		dijkstra(X);
		from = dist[s];

		result = max(result, (to+from));
	}

	printf("%d\n", result);
}
