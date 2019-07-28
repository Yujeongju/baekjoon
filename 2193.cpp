//2193 이친수
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

long long N, dp[100];
int main(void)
{
	scanf("%lld", &N);
	dp[0] = 0;
	dp[1] = 1;
	for(int i=2; i<=N; i++){
		dp[i] = dp[i-1]+dp[i-2];
	}
	printf("%lld\n", dp[N]);
}
