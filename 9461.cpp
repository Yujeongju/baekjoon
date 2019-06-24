//9461 파도반수열
#include <cstdio>

int main(void)
{
	int T, n;
	long long dp[110];
	scanf("%d", &T);

	dp[1] = dp[2] = dp[3] = 1;
	while(T--){
		scanf("%d", &n);
		for(int i=4; i<=n; i++){
			dp[i] = dp[i-2]+dp[i-3];
		}

		printf("%lld\n", dp[n]);
	}
}
