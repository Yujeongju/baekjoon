//2749 피보나치 수3
#include <cstdio>

int mod = 1000000;
int p = mod/10*15;

int main(void)
{
	long long input;
	long long *dp = new long long[p];
	scanf("%lld", &input);

	dp[0] = 0;
	dp[1] = 1;
	for(int i=2; i<p; i++){
		dp[i] = dp[i-1] + dp[i-2];
		dp[i] %= mod;
	}

	printf("%lld\n", dp[input%p]);

	return 0;
}
