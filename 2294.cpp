//2294 동전2
#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;
int main(void)
{
	int n, k;
	int dp[10010], coin[110];

	scanf("%d %d", &n, &k);
	for(int i=0; i<n; i++){
		scanf("%d", &coin[i]);
	}

	for(int i=1; i<=k; i++)
		dp[i] = 10001;

	sort(coin, coin+n);
	for(int i=0; i<n; i++){
		for(int j=1; j<=k; j++){
			if(j - coin[i] >= 0){
				dp[j] = min(dp[j], 1+dp[j-coin[i]]);
			}
		}
	}

	if(dp[k] != 10001)
		printf("%d\n", dp[k]);
	else
		printf("-1\n");
}
