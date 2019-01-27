//10844 쉬운계단수 dp

#include <cstdio>

#define MOD 1000000000

int n;
long long result=0; // int -> long long
long long dp[110][11]; // int -> long long

int main(void)
{
	scanf("%d", &n);
	
	dp[1][0] = 0;
	for(int i=1; i<10; i++)
	{
		dp[1][i] = 1;
	}
/*
	for(int i=0; i<10; i++)
		printf("%d ", dp[1][i]);

	printf("\n");
*/
	for(int i=2; i<=n; i++) // 자리수
	{
		for(int j=0; j<10; j++) // 숫자의 맨 뒷자리
		{
			if(j==0)
				dp[i][0] = dp[i-1][1]%MOD;
			else if(j==9)
				dp[i][9] = dp[i-1][8]%MOD;
			else
				dp[i][j] = (dp[i-1][j-1])+(dp[i-1][j+1])%MOD;
		}
/*
		for(int k=0; k<10; k++)
			printf("%d ", dp[i][k]);
		printf("\n");
*/
	}

	for(int i=0; i<10; i++)
		result = (result+dp[n][i]);

	printf("%d", result%MOD);

	return 0;
}
