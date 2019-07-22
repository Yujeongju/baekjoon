//1520 내리막길
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int cnt, m, n;
int arr[510][510], dp[510][510];

int dfs(int x, int y){
	if(!y && !x)
		return 1;

	if(dp[x][y] == -1){
		dp[x][y] = 0;
		for(int i=0; i<4; i++){
			int new_x = x + dx[i];
			int new_y = y + dy[i];

			if(new_x < 0 || new_x >= m || new_y < 0 || new_y >= n)
				continue;

			if(arr[new_x][new_y] > arr[x][y])
				dp[x][y] += dfs(new_x, new_y);
		}
	}

	return dp[x][y];
}

int main(void)
{
	scanf("%d %d", &m, &n);
	fill(&dp[0][0], &dp[m-1][n], -1);

	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			scanf("%d", &arr[i][j]);

	dfs(m-1, n-1);

	printf("%d\n", dp[m-1][n-1]);

}
