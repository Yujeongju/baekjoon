//2688 줄어들지 않아
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

long long dp[11];
int main(void)
{
	int t, n;
	scanf("%d", &t);
	
	while(t--){
		fill(dp, dp+11, 0);
		scanf("%d", &n);

		for(int i=0; i<=n; i++){
			dp[0] = 1;
			for(int j=1; j<10; j++){
				dp[j] = dp[j-1]+dp[j];
			}
		}

		printf("%lld\n", dp[9]);
	}
}
