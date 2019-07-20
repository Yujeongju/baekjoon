//1932 정수 삼각형
#include <cstdio>
#include <algorithm>

using namespace std;

int arr[510][510];
int dp[510][510];
int main(void)
{
	int N, result=0;
	scanf("%d", &N);

	for(int i=0; i<N; i++){
		for(int j=0; j<=i; j++){
			scanf("%d", &arr[i][j]);
		}
	}

	dp[0][0] = arr[0][0];
	for(int i=1; i<N; i++){
		for(int j=0; j<=i; j++){
			if(j == 0){
				dp[i][j] = dp[i-1][j] + arr[i][j];
			}
			else if(j == i){
				dp[i][j] = dp[i-1][j-1] + arr[i][j];
			}
			else{
				dp[i][j] = max(dp[i-1][j-1] + arr[i][j], dp[i-1][j] + arr[i][j]);
			}
		}
	}

	for(int i=0; i<=N; i++){
		result = max(result, dp[N-1][i]);
	}
	printf("%d\n", result);
}
