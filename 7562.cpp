//7562 나이트의 이동
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int chess[310][310], visit[310][310];
int N, result;
int start_x, start_y, end_x, end_y;
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

typedef struct horse{
	int x;
	int y;
	int cnt;
}Horse;

Horse set_hor(int x, int y, int cnt){
	Horse hor = {x, y, cnt};
	return hor;
}

void bfs(int x, int y)
{
	queue<Horse> q;
	q.push(set_hor(x, y, 0));
	visit[y][x] = 1;

	while(!q.empty()){
		Horse hor = q.front();
		q.pop();
		int new_x = hor.x;
		int new_y = hor.y;
		int cnt = hor.cnt;

		if(new_x == end_x && new_y == end_y){
			result = cnt;
			return;
		}

		for(int i=0; i<8; i++){
			int next_x = new_x + dx[i];
			int next_y = new_y + dy[i];

			if(next_x>=0 && next_x<N && next_y>=0 && next_y<N){
				if(visit[next_y][next_x] == 0){
					cnt = hor.cnt+1;
					q.push(set_hor(next_x, next_y, cnt));
					visit[next_y][next_x] = 1;
				}
			}
		}

		result = cnt;
	}

}

int main(void)
{
	int t;
	scanf("%d", &t);
	while(t--){
		memset(chess, 0, sizeof(chess));
		memset(visit, 0, sizeof(chess));
		result = 0;
		scanf("%d", &N);
		scanf("%d %d", &start_y, &start_x);
		scanf("%d %d", &end_y, &end_x);

		bfs(start_x, start_y);

		printf("%d\n", result);
	}
}
