//7576 토마토
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct tomato{
	int x;
	int y;
	int day;
}Tomato;

Tomato set_tomato(int x, int y, int day){
	Tomato t = {x, y, day};
	return t;
}

int box[1010][1010];
int result, box_cnt;
int w, h;

void bfs()
{
	queue<Tomato> q;
	int cnt=0;

	for(int y=0; y<h; y++){
		for(int x=0; x<w; x++){
			if(box[y][x] == 1){
				q.push(set_tomato(x, y, 0));
				cnt++;
			}
		}
	}

	while(!q.empty()){
		Tomato tmp = q.front();		
		q.pop();
		
		int new_x = tmp.x;
		int new_y = tmp.y;
		int new_day = tmp.day;

		if((new_y-1 >= 0) && box[new_y-1][new_x] == 0){
			box[new_y-1][new_x] = 1;
			cnt++;
			new_day = tmp.day+1;
			q.push(set_tomato(new_x, new_y-1, new_day));
		}

		if((new_y+1 < h) && box[new_y+1][new_x] == 0){
			box[new_y+1][new_x] = 1;
			cnt++;
			new_day = tmp.day+1;
			q.push(set_tomato(new_x, new_y+1, new_day));
		}

		if((new_x-1 >= 0) && box[new_y][new_x-1] == 0){
			box[new_y][new_x-1] = 1;
			cnt++;
			new_day = tmp.day+1;
			q.push(set_tomato(new_x-1, new_y, new_day));
		}

		if((new_x+1 < w) && box[new_y][new_x+1] == 0){
			box[new_y][new_x+1] = 1;
			cnt++;
			new_day = tmp.day+1;
			q.push(set_tomato(new_x+1, new_y, new_day));
		}

		result = new_day;
	}
}

int main(void)
{
	scanf("%d %d", &w, &h);
	box_cnt = w*h;

	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			scanf("%d", &box[i][j]);
			if(box[i][j] == -1)
				box_cnt--;
		}
	}

	bfs();

	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			if(box[i][j] == 0){
				printf("-1\n");
				return 0;
			}
		}
	}

	printf("%d\n", result);

}
