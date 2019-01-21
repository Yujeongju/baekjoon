#include <cstdio>
#include <algorithm>

using namespace std;

int x, min_t;
int dp[1000100];

int main(void)
{
	scanf("%d", &x);

	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for(int i=4; i<=x; i++)
	{
		dp[i] = 1+dp[i-1];
		
		if(i%3==0)
		{
			min_t = 1+dp[i/3];
			dp[i] = min(dp[i], min_t);
		}
		
		if(i%2==0)
		{
			min_t = 1+dp[i/2];
			dp[i] = min(dp[i], min_t);
		}
		
		
	}

	printf("%d\n", dp[x]);

	return 0;
}
