//7569 토마토
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

typedef struct Tom{
	int x;
	int y;
	int z;
	int cnt;
}Tom;

Tom set_tom(int x, int y, int z, int cnt){
	Tom tomato = {x, y, z, cnt};
	return tomato;
}

//상하좌우 위아래
int dz[6] = {0, 0, -1, 1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dx[6] = {0, 0, 0, 0, 1, -1};
int box[110][110][110], visit[110][110][110];
int M, N, H, result, tom_cnt;

void bfs(int x, int y, int z){
	queue<Tom> q;

	for(int i=0; i<H; i++){
		for(int j=0; j<N; j++){
			for(int k=0; k<M; k++){
				if(box[i][j][k] == 1){
					q.push(set_tom(i, j, k, 0));
					visit[i][j][k] = 1;
				}
			}
		}
	}

	while(!q.empty()){
		int new_x = q.front().x;
		int new_y = q.front().y;
		int new_z = q.front().z;
		int cnt = q.front().cnt;
		q.pop();
		if(cnt == tom_cnt){
			return;
		}
		
		for(int i=0; i<6; i++){
			int nxtx = new_x+dx[i];
			int nxty = new_y+dy[i];
			int nxtz = new_z+dz[i];
			int new_cnt = cnt+1;

			if(nxtx >= 0 && nxtx < H && nxty >= 0 && nxty < N && nxtz >=0 && nxtz < M){
				if(box[nxtx][nxty][nxtz] == 0 && visit[nxtx][nxty][nxtz] == 0){
					visit[nxtx][nxty][nxtz] = 1;
					q.push(set_tom(nxtx, nxty, nxtz, new_cnt));
				}

				result = max(result, new_cnt);
			}
		}
	}
}
int main(void)
{
	scanf("%d %d %d", &M, &N, &H);
	tom_cnt = M*N*H;
	for(int i=0; i<H; i++){
		for(int j=0; j<N; j++){
			for(int k=0; k<M; k++){
				scanf("%d", &box[i][j][k]);
				if(box[i][j][k] == -1){
					tom_cnt--;
					visit[i][j][k] = 1;
				}
			}
		}
	}

	bfs(0, 0, 0);

	tom_cnt = 0;
	for(int i=0; i<H; i++){
		for(int j=0; j<N; j++){
			for(int k=0; k<M; k++){
				if(visit[i][j][k] == 0){
					tom_cnt = 1;
				}
			}
		}
	}

	if(tom_cnt){
		printf("-1\n");
	}
	else
		printf("%d\n", result-1);
}
