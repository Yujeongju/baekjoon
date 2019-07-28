//3184 양
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <utility>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int R, C, visit[300][300], v_cnt, o_cnt;
char arr[300][300];
void eat(int x, int y, char c)
{
	v_cnt = o_cnt = 0;

	queue<pair<int, int> > q;
	visit[x][y] = 1;
	q.push(make_pair(x, y));
	if(c == 'v')
		v_cnt++;
	else
		o_cnt++;

	while(!q.empty()){
		int tmp_x = q.front().first;
		int tmp_y = q.front().second;
		q.pop();

		for(int i=0; i<4; i++){
			int nxtx = tmp_x + dx[i];
			int nxty = tmp_y + dy[i];

			if(nxtx < 0 || nxty < 0 || nxtx >= R || nxty >= C)
				continue;

			if(visit[nxtx][nxty] == 0 && arr[nxtx][nxty] != '#'){
				visit[nxtx][nxty] = 1;
				if(arr[nxtx][nxty] == 'v')
					v_cnt++;
				else if(arr[nxtx][nxty] == 'o')
					o_cnt++;
				q.push(make_pair(nxtx, nxty));
			}
		}
	}
}

int main(void)
{
	int v_result=0, o_result=0;

	scanf("%d %d", &R, &C);
	for(int i=0; i<R; i++){
		scanf("%s", arr[i]);
		getchar();
	}

	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			if((arr[i][j] == 'v' || arr[i][j] == 'o') && visit[i][j] == 0){
				eat(i, j, arr[i][j]);
				if(o_cnt > v_cnt)
					o_result += o_cnt;
				else
					v_result += v_cnt;
			}
		}
	}

	printf("%d %d\n", o_result, v_result);
}
