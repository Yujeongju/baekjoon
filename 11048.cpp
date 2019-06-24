//11048 이동하기
#include <cstdio>
#include <algorithm>

using namespace std;

int arr[1010][1010];
int dp[1010][1010];
int main(void)
{
	int n,m;
	scanf("%d %d", &n, &m);

	for(int i=1; i<=m; i++){
		arr[i][0] = 0;
	}
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			scanf("%d", &arr[i][j]);

	for(int i=1; i<=m; i++){
		dp[1][i] = dp[1][i-1]+arr[1][i];
	}

	for(int i=2; i<=n; i++){
		for(int j=1; j<=m; j++){
			dp[i][j] = max(dp[i-1][j-1]+arr[i][j], max(dp[i][j-1]+arr[i][j], dp[i-1][j]+arr[i][j]));
		}
	}

	printf("%d\n", dp[n][m]);
}
