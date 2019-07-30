//1495 기타리스트
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int N, S, M;
int arr[110], dp[110][1010];

void check(int i, int x){
	if(x + arr[i] <= M)
		dp[i][x+arr[i]] = x+arr[i];
	
	if(x - arr[i] >= 0)
		dp[i][x-arr[i]] = x-arr[i];
}

int main(void)
{
	int result = -99;

	scanf("%d %d %d", &N, &S, &M);
	for(int i=1; i<=N; i++)
		scanf("%d", &arr[i]);

	memset(dp, -1, sizeof(dp));
	dp[0][S] = S;
	for(int i=1; i<=N; i++)
		for(int j=0; j<=M; j++)
			if(dp[i-1][j] != -1)
				check(i, dp[i-1][j]);

	for(int i=0; i<=M; i++)
		result = max(dp[N][i], result);

	printf("%d\n", result);

}

