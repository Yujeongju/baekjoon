#include <cstdio>
#define mod 10007

int DP[10010][10];
int n, sum=0;

int main(void)
{
	scanf("%d", &n);

	for(int i=0; i<10; i++)
		DP[1][i] = 1;

	for(int i=2; i<=n; i++)
	{
		for(int j=0; j<=9; j++)
		{
			for(int k=0; k<=j; k++)
			{
				DP[i][j] += DP[i-1][k];
			}
			DP[i][j] %= mod;
		}
	}
	for(int i=0; i<=9; i++)
		sum += DP[n][i];

	printf("%d", sum%mod);

	return 0;
}
