//2225 합분해
#include <cstdio>
#include <algorithm>

#define MOD 1000000000

using namespace std;
long long dp[220] = {0};
int main(void)
{
	int n, k, cnt=0;
	scanf("%d %d", &n, &k);

	dp[0] = 1;
	for(int i=1; i<=k; i++){
		for(int j=1; j<=n; j++){
			dp[j] = (dp[j]+dp[j-1]) % MOD;
		}

		for(int j=0; j<=n; j++)
			printf("%lld  ", dp[j]);
		printf("\n");
	}

	printf("%lld\n", dp[n]);

}
