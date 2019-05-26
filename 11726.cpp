#include <cstdio>

int main(void)
{
	int num, dp[1010];
	scanf("%d", &num);
	
	dp[0] = 1;
	dp[1] = 2;
	for(int i=2; i<num; i++){
		dp[i] = (dp[i-1]+dp[i-2])%10007;
	}

	printf("%d", dp[num-1]);

}

