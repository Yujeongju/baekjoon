//2468 안전영역
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int arr[110][110];
int visit[110][110];
int N, cnt;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

typedef struct house{
	int x;
	int y;
}House;

House set_house(int x, int y){
	House hos = {x, y};
	return hos;
}

void bfs(int x, int y, int rain){
	queue<House> q;
	q.push(set_house(x, y));
	visit[y][x] = 1;

	while(!q.empty()){
		House hos = q.front();
		q.pop();

		int new_x = hos.x;
		int new_y = hos.y;
		for(int i=0; i<4; i++){
			int nxtx = new_x+dx[i];
			int nxty = new_y+dy[i];

			if(nxtx >= 0 && nxtx < N && nxty >= 0 && nxtx < N){
				if(visit[nxty][nxtx] == 0 && arr[nxty][nxtx] > rain){
					visit[nxty][nxtx] = 1;
					q.push(set_house(nxtx, nxty));
				}
			}
		}
	}
}

int main(void)
{
	int max_h=0, result=0;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			scanf("%d", &arr[i][j]);
			max_h = max(max_h, arr[i][j]);
		}
	}


	for(int i=0; i<=max_h; i++){
		cnt = 0;
		memset(visit, 0, sizeof(visit));
		for(int y=0; y<N; y++){
			for(int x=0; x<N; x++){
				if(visit[y][x] == 0 && arr[y][x] > i){
					cnt++;
					bfs(x, y, i);
				}
			}
		}

		result = max(result, cnt);
	}

	printf("%d\n", result);

}
