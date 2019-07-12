//14502 연구소
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

int N, M, cnt;
int arr[10][10], visit[10][10];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
pair<int, int> index_arr[100];

void dfs(int x, int y){
	visit[x][y] = 1;
	cnt++;

	for(int i=0; i<4; i++){
		int nxtx = x+dx[i];
		int nxty = y+dy[i];

		if(nxtx>=0 && nxtx<N && nxty>=0 && nxty<M){
			if(visit[nxtx][nxty] == 0 && arr[nxtx][nxty] == 0){
				dfs(nxtx, nxty);
			}
		}
	}
}

void bfs(int x, int y){
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	visit[x][y] = 1;

	while(!q.empty()){
		int new_x = q.front().first;
		int new_y = q.front().second;
		q.pop();

		for(int i=0; i<4; i++){
			int nxtx = new_x+dx[i];
			int nxty = new_y+dy[i];

			if(nxtx>=0 && nxtx<N && nxty>=0 && nxty<M){
				if(visit[nxtx][nxty] == 0 && arr[nxtx][nxty] == 0){
					q.push(make_pair(nxtx, nxty));
					arr[nxtx][nxty] = 2;
					visit[nxtx][nxty] = 1;
				}
			}
		}
	}
}

int main(void)
{
	int tmp[10][10], result=0, zcnt=0;
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			scanf("%d", &arr[i][j]);
			if(arr[i][j] == 0)
				index_arr[zcnt++] = make_pair(i, j);
		}
	}

	pair<int, int> first_k, second_k, third_k;
	memcpy(tmp, arr, sizeof(arr));
	for(int i=0; i<zcnt; i++){
		for(int j=i+1; j<zcnt; j++){
			for(int k=j+1; k<zcnt; k++){
				memcpy(arr, tmp, sizeof(tmp));
				memset(visit, 0, sizeof(visit));
				cnt = 0;

				first_k = index_arr[i];
				second_k = index_arr[j];
				third_k = index_arr[k];

				arr[first_k.first][first_k.second] = 1;
				arr[second_k.first][second_k.second] = 1;
				arr[third_k.first][third_k.second] = 1;

				for(int x=0; x<N; x++){
					for(int y=0; y<M; y++){
						if(arr[x][y] == 2 && visit[x][y]==0)
							bfs(x, y);
					}
				}

				for(int x=0; x<N; x++){
					for(int y=0; y<M; y++){
						if(arr[x][y] == 0 && visit[x][y] == 0)
							dfs(x, y);
					}
					result = max(cnt, result);
				}

			}
		}
	}	

	printf("%d\n", result);
}
