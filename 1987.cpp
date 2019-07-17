//1987 알파벳
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>

using namespace std;

int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};
char arr[30][30];
int check[50];
int R, C, result, cnt;

void dfs(int x, int y, int ct){
	result = max(result, ct);
	for(int i=0; i<4; i++){
		int nxtx = x + dx[i];
		int nxty = y + dy[i];
		if(nxtx<0 || nxtx>=R|| nxty<0 || nxty>=C)
			continue;

		if(check[arr[nxtx][nxty]-'A'] != 0){
			continue;
		}

		//체크
		check[arr[nxtx][nxty]-'A']++;
		dfs(nxtx, nxty, ct+1);
		//다른 경로를 찾기 위해 --
		check[arr[nxtx][nxty]-'A']--;
	}

	return;
}

int main(void)
{
	scanf("%d %d", &R, &C);
	for(int i=0; i<R; i++){
		scanf("%s", arr[i]);
		getchar();
	}
	
	check[arr[0][0]-'A']++;
	dfs(0, 0, 1);

	printf("%d\n", result);
}
