//2163 초콜릿자르기 dp

#include <cstdio>

int main(void)
{
	int N, M;
	int dp[310];

	scanf("%d %d", &N, &M);

	dp[1] = N-1;

	for(int i=2; i<=M; i++)
	{
		dp[i] = dp[i-1]+N;
	}

	printf("%d", dp[M]);

	return 0;
	
}
