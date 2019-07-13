//1261 알고스팟
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

#define INF 2<<28
using namespace std;

typedef struct Node{
	int x;
	int y;
	int wall;
}Node;

Node set_node(int x, int y, int wall){
	Node node = {x, y, wall};
	return node;
}

//struct를 우선순위큐에 넣을 경우 operator 재정의
bool operator<(Node a, Node b){
	return a.wall < b.wall;
}

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int dist[110][110], arr[110][110];
int result, N, M; // N : 세로, M : 가로

void dijkstra(int x, int y){
	dist[x][y] = 0;
	priority_queue<Node> pq;
	pq.push(set_node(x, y, 0));

	while(!pq.empty()){
		int cost = -pq.top().wall;
		int new_x = pq.top().x;
		int new_y = pq.top().y;
		pq.pop();

		if(new_x == N && new_y == M){
			result = cost + arr[N][M];
			return;
		}

		if(dist[new_x][new_y] < cost){
			continue;
		}

		for(int i=0; i<4; i++){
			int nxtx = new_x + dx[i];
			int nxty = new_y + dy[i];
			int next_dist = cost + arr[nxtx][nxty];

			if(nxtx > 0 && nxtx <= N && nxty > 0 && nxty <= M){
				if(dist[nxtx][nxty] > next_dist){
					dist[nxtx][nxty] = next_dist;
					pq.push(set_node(nxtx, nxty, -next_dist));
				}
			}
		}
	}
}

int main(void)
{
	scanf("%d %d", &M, &N);

	for(int i=1; i<=N; i++)
		for(int j=1; j<=M; j++)
			scanf("%1d", &arr[i][j]);

	for(int i=1; i<=N; i++)
		for(int j=1; j<=M; j++)
			dist[i][j] = INF;

	dijkstra(1, 1);

	printf("%d\n", result);
}
