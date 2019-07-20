//1912 연속합
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int arr[100100], dp[100100];
int main(void)
{
	int n, result=0;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);

	dp[0] = arr[0];
	result = arr[0];
	for(int i=1; i<n; i++){
		dp[i] = max(arr[i], dp[i-1]+arr[i]);
		result = max(dp[i], result);
	}

	printf("%d\n", result);
}
