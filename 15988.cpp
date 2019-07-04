//15988 1, 2, 3 더하기 3
#include <cstdio>
#include <algorithm>

#define MOD 1000000009

using namespace std;

long long dp[1000100];
int main(void)
{
	int t, n;
	scanf("%d", &t);
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	while(t--){
		scanf("%d", &n);
		
		for(int i=4; i<=n; i++){
			dp[i] = (dp[i-1]+dp[i-2]+dp[i-3])%MOD;
		}

		printf("%lld\n", dp[n]%MOD);
	}
}
