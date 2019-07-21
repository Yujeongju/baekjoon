//2096 내려가기
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int arr[100100][3], dp[100100][3];
int main(void)
{
	int n, max_result=0, min_result=0;
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
	}

	dp[1][0] = arr[1][0];
	dp[1][1] = arr[1][1];
	dp[1][2] = arr[1][2];

	for(int i=2; i<=n; i++){
		dp[i][0] = max(dp[i-1][0], dp[i-1][1])+arr[i][0];
				
		dp[i][1] = max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2]))+arr[i][1];

		dp[i][2] = max(dp[i-1][1], dp[i-1][2])+arr[i][2];
	}
	max_result = max(dp[n][0], dp[n][1]);
	max_result = max(max_result, dp[n][2]);
	
	memset(dp, 0, sizeof(dp));

	dp[1][0] = arr[1][0];
	dp[1][1] = arr[1][1];
	dp[1][2] = arr[1][2];

	for(int i=2; i<=n; i++){
		dp[i][0] = min(dp[i-1][0], dp[i-1][1])+arr[i][0];
				
		dp[i][1] = min(dp[i-1][0], min(dp[i-1][1], dp[i-1][2]))+arr[i][1];

		dp[i][2] = min(dp[i-1][1], dp[i-1][2])+arr[i][2];
	}
	min_result = min(dp[n][0], dp[n][1]);
	min_result = min(min_result, dp[n][2]);

	printf("%d %d\n", max_result, min_result);
}
