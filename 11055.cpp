//11055 가장 큰 증가 부분 수열
#include <cstdio>
#include <algorithm>

using namespace std;

int arr[1010], dp[1010];
int main(void)
{
	int n, result=0;
	scanf("%d", &n);

	for(int i=1; i<=n; i++)
		scanf("%d", &arr[i]);

	for(int i=1; i<=n; i++){
		for(int j=0; j<=i; j++){
			if(arr[i] > arr[j] && dp[i] < dp[j]+arr[i]){
				dp[i] = dp[j]+arr[i];
				result = max(dp[i], result);
			}
		}
	}

	printf("%d\n", result);
}
