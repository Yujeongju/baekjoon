//1965 상자넣기
#include <cstdio>
#include <algorithm>

using namespace std;

int arr[1010],dp[1010], N, result;
int main(void)
{
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		scanf("%d", &arr[i]);
	}

	for(int i=1; i<=N; i++){
		for(int j=0; j<=i; j++){
			if(arr[i] > arr[j] && dp[i] < dp[j]+1){
				dp[i] = dp[j]+1;
				result = max(result, dp[i]);
			}
		}
	}

	printf("%d\n", result);
}
