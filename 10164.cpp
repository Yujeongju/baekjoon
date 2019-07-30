//10164 격자상의 경로
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M, K; // 행 열 표시
long long dp[20][20], arr[20][20], tmp=1;
int main(void)
{
	scanf("%d %d %d", &N, &M, &K);
	arr[(K-1)/M+1][(K-1)%M+1] = 1;
	
	dp[0][1] = 1;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			dp[i][j] = dp[i-1][j] + dp[i][j-1];
			if(arr[i][j] == 1){
				tmp = dp[i][j];
				memset(dp, 0, sizeof(dp));
				dp[i][j] = 1;
			}
		}
	}

	printf("%lld\n", tmp * dp[N][M]);
}
