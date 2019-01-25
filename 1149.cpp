// 1149 RGB거리 : dp

#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int arr[1010][10];
int dp[1010][10];

int main(void)
{

	scanf("%d", &n);

	for(int i=1; i<=n; i++)
		for(int j=1; j<=3; j++)
			scanf("%d", &arr[i][j]);

	dp[1][1] = arr[1][1];
	dp[1][2] = arr[1][2];
	dp[1][3] = arr[1][3];

	for(int i=2; i<=n; i++)
	{
		for(int j=1; j<=3; j++)
		{
			if(j==1)
				dp[i][1] = min(dp[i-1][2], dp[i-1][3])+arr[i][1];
			else if(j==2)
				dp[i][2] = min(dp[i-1][1], dp[i-1][3])+arr[i][2];
			else if(j==3)
				dp[i][3] = min(dp[i-1][1], dp[i-1][2])+arr[i][3];
		}
	}

	printf("%d", min(min(dp[n][1], dp[n][2]),dp[n][3]));

	return 0;


}
