//4963 섬의 개수
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int arr[51][51];
int visit[51][51];
int w, h, cnt;

int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
void dfs(int x, int y)
{
	visit[x][y] = 1;
	
	for(int i=0; i<8; i++){
		int nxtx = x+dx[i];
		int nxty = y+dy[i];

		if(nxtx < 0 || nxty < 0 || nxtx >= h || nxty >= w)
			continue;

		if(visit[nxtx][nxty] == 0 && arr[nxtx][nxty] == 1){
			dfs(nxtx, nxty);
		}
	}
}

int main(void)
{
	while(1){
		memset(arr, 0, sizeof(arr));
		memset(visit, 0, sizeof(visit));
		cnt = 0;
		scanf("%d %d", &w, &h);
		if(w == 0 && h == 0)
			return 0;

		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				scanf("%d", &arr[i][j]);
			}
		}

		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				if(visit[i][j] == 0 && arr[i][j] == 1){
					cnt++;
					dfs(i, j);
				}
			}
		}

		printf("%d\n", cnt);
	}
}
