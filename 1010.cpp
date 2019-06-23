//1010 다리 놓기
#include <cstdio>
#include <algorithm>

using namespace std;

int dp[31][31];
int main(void)
{
	int T, n, m;
	scanf("%d", &T);

	while(T--){
		scanf("%d %d", &n, &m);

		for(int i=0; i<=m; i++)
			dp[1][i] = i;

		for(int i=2; i<=n; i++){
			for(int j=1; j<=m; j++){
				if(i==j)
					dp[i][j] = 1;
				else if(j>i){
					dp[i][j] = dp[i-1][j-1]+dp[i][j-1];
				}
				else if(i>j){
					dp[i][j] = dp[j][i];
				}
			}
		}

		printf("%d\n", dp[n][m]);
	}

}
