//10026 적록색약
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
char arr[110][110];
int visit[110][110];
int N, result1, result2;

void dfs(int x, int y, char c){
	visit[x][y] = 1;

	for(int i=0; i<4; i++){
		int nxtx = x+dx[i];
		int nxty = y+dy[i];

		if(visit[nxtx][nxty] == 0 && arr[nxtx][nxty] == c){
			dfs(nxtx, nxty, c);
		}
	}
}

void bfs(int x, int y){
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	arr[x][y] = 'R';
	visit[x][y] = 1;

	while(!q.empty()){
		int new_x = q.front().first;
		int new_y = q.front().second;
		q.pop();
		
		for(int i=0; i<4; i++){
			int nxtx = new_x + dx[i];
			int nxty = new_y + dy[i];
			if(nxtx >=0 && nxtx<N && nxty>=0 && nxty<N){
				if(arr[nxtx][nxty] == 'G'){
					visit[nxtx][nxty] = 1;
					arr[nxtx][nxty] = 'R';
				}
			}
		}
	}
}

int main(void)
{
	char input[110];
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%s", input);
		getchar();
		for(int j=0; j<N; j++){
			arr[i][j] = input[j];
		}
	}

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(visit[i][j] == 0){
				result1++;
				dfs(i, j, arr[i][j]);
			}
		}
	}

	memset(visit, 0, sizeof(visit));
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(arr[i][j] == 'G' && visit[i][j] == 0){
				bfs(i, j);
			}
		}
	}
	
	memset(visit, 0, sizeof(visit));

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(visit[i][j] == 0){
				result2++;
				dfs(i, j, arr[i][j]);
			}
		}
	}

	printf("%d %d\n", result1, result2);
}
