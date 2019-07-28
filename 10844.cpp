//10844 쉬운계단수
#include <cstdio>
#include <algorithm>

#define MOD 1000000000
using namespace std;

int n;
long long dp[110][11], result;
int main(void)
{
	scanf("%d", &n);

	dp[1][0] = 0;
	for(int i=1; i<10; i++)
		dp[1][i] = 1;

	for(int i=2; i<=n; i++){
		for(int j=0; j<10; j++){
			if(j == 0)
				dp[i][j] = dp[i-1][j+1] % MOD;
			else if(j == 9)
				dp[i][j] = dp[i-1][j-1] % MOD;
			else
				dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % MOD;
		}
	}

	for(int j=0; j<10; j++)
		result += dp[n][j];

	printf("%lld\n", result%MOD);
}
