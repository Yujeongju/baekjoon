//2573 빙산
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int N, M, ice_cnt, year;
int arr[310][310], visit[310][310];

void bfs(int x, int y){
	visit[x][y] = 1;
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));

	while(!q.empty()){
		int tmp_x = q.front().first;
		int tmp_y = q.front().second;
		q.pop();

		for(int i=0; i<4; i++){
			int new_x = tmp_x + dx[i];
			int new_y = tmp_y + dy[i];
			if(new_x < 0 || new_x >= N || new_y < 0 || new_y >= M)
				continue;
			if(arr[new_x][new_y] != 0)
				arr[new_x][new_y]--;
			else if(arr[new_x][new_y] == 0 && visit[new_x][new_y]==0){
				q.push(make_pair(new_x, new_y));
			}
			visit[new_x][new_y] = 1;
		}
	}
}

void dfs(int x, int y){
	visit[x][y] = 1;

	for(int i=0; i<4; i++){
		int new_x = x + dx[i];
		int new_y = y + dy[i];
		if(new_x < 0 || new_x >= N || new_y < 0 || new_y >= M)
			continue;

		if(arr[new_x][new_y] != 0 && visit[new_x][new_y] == 0){
			dfs(new_x, new_y);
		}
	}
}

int main(void)
{
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			scanf("%d", &arr[i][j]);
		}
	}

	int	zero_cnt=0;
	while(1){
		memset(visit, 0, sizeof(visit));
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				if(visit[i][j] == 0 && arr[i][j] == 0){
					bfs(i, j);
				}
			}
		}

		memset(visit, 0, sizeof(visit));
		ice_cnt = 0;
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				if(visit[i][j] == 0 && arr[i][j] != 0){
					ice_cnt++;
					dfs(i, j);
				}
			}
		}

		year++;
		zero_cnt=0;
		if(ice_cnt >= 2){
			zero_cnt++;
			break;
		}
		else{
			for(int i=0; i<N; i++){
				for(int j=0; j<M; j++){
					if(arr[i][j] != 0){
						zero_cnt++;
						break;
					}
				}
			}

			if(!zero_cnt)
				break;
		}
	}

	if(!zero_cnt){
		printf("0\n");
	}
	else{
		printf("%d\n", year);
	}
}
