//1916 최소비용 구하기
#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

#define INF 2<<28

using namespace std;

int dist[100100];
vector<pair<int, int> > graph[1010];

void bus_node(int s){
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
	int city, bus;
	int s, e, w;
	int bus_s, bus_e;
	scanf("%d %d", &city, &bus);

	for(int i=0; i<bus; i++){
		scanf("%d %d %d", &s, &e, &w);
		graph[s].push_back(make_pair(e, w));
	}

	for(int i=0; i<=city; i++)
		dist[i] = INF;

	scanf("%d %d", &bus_s, &bus_e);
	bus_node(bus_s);

	printf("%d\n", dist[bus_e]);

}
