//2156 포도주 시식
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, arr[10010], dp[10010];
int main(void)
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);

	dp[0] = arr[0];
	dp[1] = arr[0]+arr[1];
	for(int i=2; i<n; i++){
		dp[i] = max(dp[i-1], dp[i-2]+arr[i]);
		dp[i] = max(dp[i], dp[i-3]+arr[i-1]+arr[i]);
	}

	printf("%d\n", dp[n-1]);
}
