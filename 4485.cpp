//4485 녹색 옷 입은 애가 젤다지?
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

#define INF 2<<28
using namespace std;

typedef struct Node{
	int x;
	int y;
	int cost;
}Node;

bool operator<(Node a, Node b){
	return a.cost < b.cost;
}

Node set_node(int x, int y, int cost){
	Node node = {x, y, cost};
	return node;
}

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int arr[130][130], dist[130][130];
int N;

void dijkstra(int x, int y){
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			dist[i][j] = INF;
	
	dist[x][y] = arr[x][y];
	priority_queue<Node> pq;
	pq.push(set_node(x, y, -arr[x][y]));

	while(!pq.empty()){
		int cost = -pq.top().cost;
		int here_x = pq.top().x;
		int here_y = pq.top().y;
		pq.pop();

		if(dist[here_x][here_y] < cost)
			continue;


		for(int i=0; i<4; i++){
			int nxtx = here_x+dx[i];
			int nxty = here_y+dy[i];
			int next_dist = cost + arr[nxtx][nxty];

			if(nxtx < 0 || nxtx >= N || nxty < 0 || nxty >= N)
				continue;

			if(dist[nxtx][nxty] > next_dist){
				dist[nxtx][nxty] = next_dist;
				pq.push(set_node(nxtx, nxty, -next_dist));
			}
		}
	}
}

int main(void)
{
	int cnt = 1;
	while(1){
		memset(arr, 0, sizeof(arr));
		memset(dist, 0, sizeof(dist));
		scanf("%d", &N);

		if(N == 0)
			break;

		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				scanf("%d", &arr[i][j]);
		
		dijkstra(0, 0);
		printf("Problem %d: %d\n", cnt++, dist[N-1][N-1]);
	}
}
