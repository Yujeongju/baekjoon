//1904 01타일
#include <cstdio>
#include <algorithm>

#define MOD 15746
using namespace std;

long long dp[1000100];
int main(void)
{
	int n;
	scanf("%d", &n);

	dp[1] = 0;
	dp[2] = 2;
	dp[3] = 3;
	for(long long i=4; i<=n; i++){
		dp[i] = (dp[i-1]+dp[i-2])%MOD;
	}

	printf("%lld\n", dp[n]);
	
}
