//2667 단지번호 붙이기
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int arr[30][30];
int visit[30][30], house[1010];
int N, cnt;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
void dfs(int y, int x)
{
	visit[y][x] = 1;
	cnt++;

	for(int k=0; k<4; k++){
		int new_x = x+dx[k];
		int new_y = y+dy[k];
		if(new_x>=0 && new_x<N && new_y>=0 && new_y<N){
			if(visit[new_y][new_x] == 0 && arr[new_y][new_x] == 1){
				dfs(new_y, new_x);
			}
		}
	}
}

int main(void)
{
	int h_cnt=0;
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			scanf("%1d", &arr[i][j]);

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(visit[i][j] == 0 && arr[i][j] == 1){
				cnt = 0;
				dfs(i, j);
				if(cnt > 0)
					house[h_cnt++] = cnt;
			}
		}

	}

	printf("%d\n", h_cnt);
	sort(house, house+h_cnt);
	for(int i=0; i<h_cnt; i++)
		printf("%d\n", house[i]);
}
