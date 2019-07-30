//9465 스티커
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[2][100100], arr[2][100100];
int t, n, result;
int main(void)
{
	scanf("%d", &t);
	while(t--){
		memset(dp, 0, sizeof(dp));
		memset(arr, 0, sizeof(arr));
		scanf("%d", &n);

		for(int i=0; i<2; i++)
			for(int j=1; j<=n; j++)
				scanf("%d", &arr[i][j]);

		dp[0][1] = arr[0][1];
		dp[1][1] = arr[1][1];

		for(int i=2; i<=n; i++){
			dp[0][i] = max(dp[1][i-1]+arr[0][i], dp[1][i-2]+arr[0][i]);
			dp[1][i] = max(dp[0][i-1]+arr[1][i], dp[0][i-2]+arr[1][i]);
		}

		result = max(dp[0][n], dp[1][n]);

		printf("%d\n", result);
	}
}
