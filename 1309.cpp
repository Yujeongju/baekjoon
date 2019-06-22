//1309 동물원
#include <cstdio>

long long dp[1000001];
int main(void)
{
	int input;
	scanf("%d", &input);

	dp[0] = 1;
	dp[1] = 3;
	for(int i=2; i<=input; i++){
		dp[i] = (dp[i-1]*2 + dp[i-2])%9901;
	}

	printf("%lld\n", dp[input]%9901);
}
