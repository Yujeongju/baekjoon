//9507 Generations of Tribbles
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

long long dp[100];
int main(void)
{
	int n, t;
	scanf("%d", &t);
	while(t--){
		memset(dp, 0, sizeof(dp));
		scanf("%d", &n);
		
		dp[0] = 1;
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;
		for(int i=4; i<=n; i++)
			dp[i] = dp[i-1]+dp[i-2]+dp[i-3]+dp[i-4];

		printf("%lld\n", dp[n]);
	}
}
