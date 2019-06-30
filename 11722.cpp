//11722 가장 긴 감소하는 부분 수열
#include <cstdio>
#include <algorithm>

using namespace std;

int dp[1010], arr[1010];
int main(void)
{
	int input, result=0;
	scanf("%d", &input);

	for(int i=1; i<=input; i++){
		scanf("%d", &arr[i]);
		dp[i] = 1;
	}

	result = 1;
	for(int i=1; i<=input; i++){
		for(int j=0; j<i; j++){
			if(arr[i] < arr[j] && dp[i] < dp[j]+1){
				dp[i] = dp[j]+1;
				result = max(result, dp[i]);
			}
		}
		
	}

	printf("%d\n", result);

}
