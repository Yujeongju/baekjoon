//2225 합분해
#include <cstdio>
#include <algorithm>

#define MOD 1000000000
using namespace std;

int N, K;
long long dp[210];
int main(void)
{
	scanf("%d %d", &N, &K);
	dp[0] = 1;
	for(int i=1; i<=K; i++){
		for(int j=1; j<=N; j++){
			dp[j] = (dp[j-1] + dp[j]) % MOD;
		}
	}

	printf("%lld\n", dp[N]%MOD);
}
