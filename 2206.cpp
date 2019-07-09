//2206 벽부수고 이동하기
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

int result, N, M;
int arr[1010][1010];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

pair<int, int> visit[1010][1010];

typedef struct node{
	int x;
	int y;
	int day;
	int wall;
}Node;

Node set_node(int x, int y, int day, int wall){
	Node node = {x, y, day, wall};
	return node;
}

void bfs(int x, int y){
	queue<Node> q;
	visit[y][x] = make_pair(0,1);
	q.push(set_node(x, y, 0, 0));

	while(!q.empty()){
		Node tmp = q.front();
		q.pop();

		int new_x = tmp.x;
		int new_y = tmp.y;
		int new_day = tmp.day;
		int new_wall = tmp.wall;

		if(new_y == N-1 && new_x == M-1){
			if(new_wall == 1)
				visit[N-1][M-1].first = 1;
			else
				visit[N-1][M-1].second = 1;

			result = new_day + 1;
			return;
		}

		for(int i=0; i<4; i++){
			int nxtx = new_x + dx[i];
			int nxty = new_y + dy[i];

			if(nxtx>=0 && nxtx <= M-1 && nxty>=0 && nxty<=N-1){
				if((new_wall == 0 && visit[nxty][nxtx].second == 0) || (new_wall == 1 && visit[nxty][nxtx].first == 0)){
					if(arr[nxty][nxtx] == 0){
						new_day = tmp.day+1;
						if(new_wall == 1)
							visit[nxty][nxtx].first = 1;
						else
							visit[nxty][nxtx].second = 1;
						q.push(set_node(nxtx, nxty, new_day, new_wall));
					}
					else{
						if(new_wall == 0){
							new_day = tmp.day+1;
							visit[nxty][nxtx].second = 1;
							q.push(set_node(nxtx, nxty, new_day, 1));
						}
					}
				}	
			}
		}
		result = new_day;
	}
}

int main(void)
{
	memset(arr, -1, sizeof(arr));
	memset(visit, 0, sizeof(visit));
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			scanf("%1d", &arr[i][j]);
		}
	}

	bfs(0,0);

	if(visit[N-1][M-1].first == 1 || visit[N-1][M-1].second == 1)
		printf("%d\n", result);
	else
		printf("-1\n");
}
