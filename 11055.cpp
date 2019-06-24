//11055 가장 큰 증가 부분 수열
//LIS라는 알고리즘.....
#include <cstdio>
#include <algorithm>

using namespace std;

int arr[1010], dp[1010];
int main(void)
{
	int n, result=0;
	scanf("%d", &n);

	for(int i=1; i<=n; i++){
		scanf("%d", &arr[i]);
		dp[i] = arr[i];
	}

	result = dp[1];
	for(int i=1; i<=n; i++){
		for(int j=1; j<i; j++){
			if(arr[j] < arr[i]){
				dp[i] = max(dp[i], dp[j]+arr[i]);
				result = max(dp[i], result);
			}
		}
	}


	printf("%d\n", result);
}
