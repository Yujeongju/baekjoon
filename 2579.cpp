//2579 계단 오르기
#include <cstdio>
#include <algorithm>

using namespace std;

int arr[310], dp[310];
int main(void)
{
	int N, result=0;
	scanf("%d", &N);

	for(int i=1; i<=N; i++)
		scanf("%d", &arr[i]);

	dp[1] = arr[1];
	dp[2] = arr[1]+arr[2];
	for(int i=3; i<=N; i++){
		dp[i] = arr[i] + max(dp[i-2], arr[i-1]+dp[i-3]);
	}

	printf("%d\n", dp[N]);
}

