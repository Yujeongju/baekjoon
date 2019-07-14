//1504 특정한 최단 경로
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

#define INF 2<<28

using namespace std;

int dist[810];
vector<pair<int, int> > graph[810];
int N, E;
int dot1, dot2;
void dijkstra(int s){
	for(int i=0; i<=N; i++)
		dist[i] = INF;
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
	int sto1=0, sto2=0, otot=0, ttoo=0, otoe=0, ttoe=0;
	long long result=0;
	scanf("%d %d", &N, &E);
	for(int i=1; i<=E; i++){
		scanf("%d %d %d", &from, &to, &cost);
		graph[from].push_back(make_pair(to, cost));
		graph[to].push_back(make_pair(from, cost));
	}

	scanf("%d %d", &dot1, &dot2);

	dijkstra(1);
	sto1 = dist[dot1];
	sto2 = dist[dot2];

	dijkstra(dot1);
	otot = dist[dot2];
	otoe = dist[N];

	dijkstra(dot2);
	ttoo = dist[dot1];
	ttoe = dist[N];

	result = min(sto1+otot+ttoe, sto2+ttoo+otoe);
	if(result >= INF)
		printf("-1\n");
	else
		printf("%lld\n", result);

}
