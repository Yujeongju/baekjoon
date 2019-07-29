//1309 동물원
#include <cstdio>
#include <algorithm>

#define MOD 9901
using namespace std;

long long dp[100100];
int main(void)
{
	int N;
	scanf("%d", &N);
	dp[0] = 1;
	dp[1] = 3;
	for(int i=2; i<=N; i++){
		dp[i] = (dp[i-1]*2 + dp[i-2])%MOD;
	}

	printf("%lld\n", dp[N]);

}
