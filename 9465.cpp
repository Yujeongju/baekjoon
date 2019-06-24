//9465 스티커
#include <cstdio>
#include <algorithm>

using namespace std;
int main(void)
{
	int n, T;
	int arr[2][100010];
	int dp[2][100010];

	scanf("%d", &T);

	while(T--){
		for(int i=0; i<2; i++){
			for(int j=0; j<=100000; j++){
				dp[i][j] = 0;
				arr[i][j] = 0;
			}
		}

		scanf("%d", &n);
		for(int i=0; i<2; i++){
			for(int j=1; j<=n; j++){
				scanf("%d", &arr[i][j]);
			}
		}

		arr[0][0] = arr[1][0] = 0;
		dp[0][1] = arr[0][1];
		dp[1][1] = arr[1][1];

		for(int i=2; i<=n; i++){
			dp[0][i] = max(dp[1][i-1]+arr[0][i], dp[1][i-2]+arr[0][i]);
			dp[1][i] = max(dp[0][i-1]+arr[1][i], dp[0][i-2]+arr[1][i]);
		}

		printf("%d\n", max(dp[0][n], dp[1][n]));
	}
}
