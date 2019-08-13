//14430 자원 캐기
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n,m, arr[310][310], dp[310][310];
int main(void)
{
	int result = 0;
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			scanf("%d", &arr[i][j]);

	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + arr[i][j];
			result = max(result, dp[i][j]);
		}
	}

	printf("%d\n", result);
}
