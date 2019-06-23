//1912 연속합
#include <cstdio>
#include <algorithm>

using namespace std;

int dp[100100];
int arr[100100];
int main(void)
{
	int n;
	int result=0;
	scanf("%d", &n);

	for(int i=1; i<=n; i++){
		scanf("%d", &arr[i]);
	}

	dp[1] = arr[1];
	result = dp[1];
	for(int i=2; i<=n; i++){
		dp[i] = max(dp[i-1]+arr[i], arr[i]);
		result = max(dp[i], result);
		//printf("dp[%d] : %d\tresult : %d\n", i, dp[i], result);
	}
	
	printf("%d\n", result);
	
}
