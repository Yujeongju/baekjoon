//11051 이항계수2
#include <cstdio>
#include <algorithm>

#define MOD 10007
using namespace std;

long long dp[1010][1010];
int N, K;
int main(void)
{
	scanf("%d %d", &N, &K);
	dp[0][0] = 1;
	for(int i=0; i<=N; i++){
		for(int j=0; j<=i; j++){
			if(j == 0)
				dp[i][j] = 1;
			else if(j == i)
				dp[i][j] = 1;
			else{
				dp[i][j] = (dp[i-1][j-1]+dp[i-1][j])%MOD;
			}
		}
	}


	printf("%lld\n", dp[N][K]);
}
