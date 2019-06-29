//2775 부녀회장이 될테야
#include <cstdio>

int dp[15][15];
int main(void)
{
	int t, floor, number;
	scanf("%d", &t);

	for(int i=1; i<=14; i++){
		dp[0][i] = i;
	}
	for(int i=1; i<=14; i++){
		for(int j=1; j<=14; j++){
			for(int k=1; k<=j; k++){
				dp[i][j] += dp[i-1][k];
			}
		}
	}
	while(t--){
		scanf("%d", &floor);
		scanf("%d", &number);

		printf("%d\n", dp[floor][number]);
	}
}
