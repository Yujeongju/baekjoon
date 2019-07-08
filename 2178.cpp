//2178 미로찾기
#include <cstdio>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

int arr[110][110];
int visit[110][110];
int result, w, h;
	
typedef struct node{
	int x;
	int y;
	int cnt;
}Node;

Node set_node(int x, int y, int cnt){
	Node node = {x, y, cnt};
	return node;
}

void bfs(int x, int y)
{
	queue<Node> q;
	q.push(set_node(x, y, 1));
	visit[y][x] = 1;

	while(!q.empty()){
		Node tmp = q.front();
		q.pop();
		int new_x = tmp.x;
		int new_y = tmp.y;
		int new_cnt = tmp.cnt;

		if(new_x == w && new_y == h){
			result = new_cnt;
			return;
		}

		if(new_y-1>=0 && arr[new_y-1][new_x] == 1 && visit[new_y-1][new_x] == 0){
			new_cnt = tmp.cnt+1;
			q.push(set_node(new_x, new_y-1, new_cnt));
			visit[new_y-1][new_x] = 1;
		}

		if(new_y+1<=h && arr[new_y+1][new_x] == 1 && visit[new_y+1][new_x] == 0){
			new_cnt = tmp.cnt+1;
			q.push(set_node(new_x, new_y+1, new_cnt));
			visit[new_y+1][new_x] = 1;
		}

		if(new_x-1>=0 && arr[new_y][new_x-1] == 1 && visit[new_y][new_x-1] == 0){
			new_cnt = tmp.cnt+1;
			q.push(set_node(new_x-1, new_y, new_cnt));
			visit[new_y][new_x-1] = 1;
		}

		if(new_x+1<=w && arr[new_y][new_x+1] == 1 && visit[new_y][new_x+1] == 0){
			new_cnt = tmp.cnt+1;
			q.push(set_node(new_x+1, new_y, new_cnt));
			visit[new_y][new_x+1] = 1;
		}

		result = new_cnt;
	}
}

int main(void)
{
	scanf("%d %d", &h, &w);

	for(int i=1; i<=h; i++)
		for(int j=1; j<=w; j++)
			scanf("%1d", &arr[i][j]);

	bfs(1,1);

	printf("%d\n", result);
}
