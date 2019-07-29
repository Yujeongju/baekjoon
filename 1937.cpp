//1937 욕심쟁이 판다
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int N, result;
int arr[510][510], dp[510][510];

int dfs(int x, int y)
{
	if(dp[x][y] != 0)
		return dp[x][y];

	dp[x][y] = 1;

	for(int i=0; i<4; i++){
		int nxtx = x + dx[i];
		int nxty = y + dy[i];

		if(nxtx < 0 || nxty < 0 || nxtx >= N || nxty >= N)
			continue;

		if(arr[nxtx][nxty] > arr[x][y])
			dp[x][y] = max(dp[x][y], dfs(nxtx, nxty)+1);
	}

	return dp[x][y];
}

int main(void)
{
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			scanf("%d", &arr[i][j]);

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			result = max(result, dfs(i, j));
		}
	}

	printf("%d\n", result);

}
