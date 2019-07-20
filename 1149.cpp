//1149 RGB거리
#include <cstdio>
#include <algorithm>

using namespace std;

int arr[1010][3], dp[1010][3];
int main(void)
{
	int N;
	scanf("%d", &N);

	for(int i=0; i<N; i++){
		for(int j=0; j<3; j++){
			scanf("%d", &arr[i][j]);
		}
	}

	dp[0][0] = arr[0][0];
	dp[0][1] = arr[0][1];
	dp[0][2] = arr[0][2];

	for(int i=1; i<N; i++){
		for(int j=0; j<3; j++){
			if(j == 0){
				dp[i][j] = min(dp[i-1][1], dp[i-1][2]) + arr[i][0];
			}
			else if(j == 1){
				dp[i][j] = min(dp[i-1][0], dp[i-1][2]) + arr[i][1];
			}
			else if(j == 2){
				dp[i][j] = min(dp[i-1][0], dp[i-1][1]) + arr[i][2];
			}
		}
	}

	int result = min(dp[N-1][0], dp[N-1][1]);
	result = min(result, dp[N-1][2]);
	printf("%d\n",result);
}
