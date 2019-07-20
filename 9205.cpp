//9205 맥주 마시면서 걸어가기
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

#define MAX 32767
using namespace std;

int peon_cnt, result;
pair<int, int> ber_pos[110];
int visit[1010];

void bfs(int x, int y){
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	visit[0] = 1;

	while(!q.empty()){
		int new_x = q.front().first;
		int new_y = q.front().second;
		q.pop();

		if(new_x == ber_pos[peon_cnt+1].first && new_y == ber_pos[peon_cnt+1].second){
			result = 1;
			return;
		}

		for(int i=1; i<peon_cnt+2; i++){
			if(visit[i] == 0){
				int road = abs(new_x-ber_pos[i].first) + abs(new_y-ber_pos[i].second);
				if(road <= 1000){
					visit[i] = 1;
					q.push(ber_pos[i]);
				}
			}
		}
	}

	result = 0;
}

int main(void)
{
	int t;
	int pos1, pos2;
	scanf("%d", &t);
	while(t--){
		memset(visit, 0, sizeof(visit));
		scanf("%d", &peon_cnt);
		for(int i=0; i<peon_cnt+2; i++){
			scanf("%d %d", &pos1, &pos2);
			ber_pos[i] = make_pair(pos1, pos2);
		}

		bfs(ber_pos[0].first, ber_pos[0].second);

		if(result == 0){
			printf("sad\n");
		}
		else{
			printf("happy\n");
		}
	}
}
