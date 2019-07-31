//11048 이동하기
#include <cstdio>
#include <algorithm>

using namespace std;

int N, M;
int arr[1010][1010], dp[1010][1010];
int main(void)
{
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++)
		for(int j=1; j<=M; j++)
			scanf("%d", &arr[i][j]);

	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			dp[i][j] = max(dp[i-1][j-1], max(dp[i][j-1], dp[i-1][j])) + arr[i][j];
		}
	}

	printf("%d\n",	dp[N][M]); 
}
