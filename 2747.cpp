//2747 피보나치 수
#include <cstdio>

int main(void)
{
	int input, dp[100];
	scanf("%d", &input);

	dp[0] = 1;
	dp[1] = 1;
	for(int i=2; i<input; i++){
		dp[i] = dp[i-1] + dp[i-2];
	}

	printf("%d\n", dp[input-1]);

}
