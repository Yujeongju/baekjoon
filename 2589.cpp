//2589 보물섬
#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

#define INF 2<<29
using namespace std;

typedef struct boat{
	int x;
	int y;
	int cost;
}Boat;

Boat set_boat(int x, int y, int cost){
	Boat bot = {x, y, cost};
	return bot;
}

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int N, M, cnt, result;
char arr[60][60];
int visit[60][60];
void bfs(int x, int y){
	int new_cost;
	memset(visit, 0, sizeof(visit));
	queue<Boat> q;
	q.push(set_boat(x, y, 0));
	visit[x][y] = 1;
	while(!q.empty()){
		int tmp_x = q.front().x;
		int tmp_y = q.front().y;
		int cost = q.front().cost;
		int new_cost;
		q.pop();

		for(int i=0; i<4; i++){
			int nxtx = tmp_x + dx[i];
			int nxty = tmp_y + dy[i];

			if(nxtx < 0 || nxty < 0 || nxtx >= N || nxty >= M)
				continue;

			if(arr[nxtx][nxty] == 'L' && visit[nxtx][nxty] == 0){
				new_cost = cost+1;
				visit[nxtx][nxty] = 1;
				q.push(set_boat(nxtx, nxty, new_cost));
			}
			cnt = max(cnt, new_cost);
		}
	}

}

int main(void)
{
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			scanf(" %1c", &arr[i][j]);
		}
	}

	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(arr[i][j] == 'L'){
				cnt = 0;
				bfs(i, j);
				result = max(cnt, result);
			}
		}
	}

	printf("%d\n", result);

}
