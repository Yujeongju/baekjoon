//2583 영역 구하기
#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

int M, N, K;

int arr[110][110], visit[110][110];
int cnt_arr[10010];
int cnt, result;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y){
	visit[y][x] = 1;
	for(int i=0; i<4; i++){
		int new_x = x+dx[i];
		int new_y = y+dy[i];
		if(new_x >= 0 && new_x<N && new_y>=0 && new_y<M){
			if(visit[new_y][new_x] == 0 && arr[new_y][new_x] == 0){
				visit[new_y][new_x] = 1;
				cnt++;
				dfs(new_x, new_y);
			}
		}
	}
}

int main(void)
{
	int x1, y1, x2, y2;
	scanf("%d %d %d", &M, &N, &K);
	for(int i=0; i<K; i++){
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for(int y=y1; y<y2; y++){
			for(int x=x1; x<x2; x++){
				arr[y][x] = 1;
			}
		}
	}

	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			if(visit[i][j] == 0 && arr[i][j] == 0){
				cnt = 1;
				dfs(j, i);
				if(cnt > 0)
					cnt_arr[result++] = cnt;
			}
		}
	}

	sort(cnt_arr, cnt_arr+result);
	printf("%d\n", result);
	for(int i=0; i<result; i++)
		printf("%d ", cnt_arr[i]);
	printf("\n");
}
