//11066 파일 합치기
#include <cstdio>
#include <cstring>
#include <algorithm>

#define INF 2<<29

using namespace std;

long long dp[510][510];
int sum[510];
int main(void)
{
	int t, n, cost;

	scanf("%d", &t);
	while(t--){
		memset(dp, 0, sizeof(dp));
		memset(sum, 0, sizeof(sum));
		scanf("%d", &n);

		for(int i=1; i<=n; i++){
			scanf("%d", &cost);
			//발생하는 합을 구하기 위해 1~n까지 모두 더함.
			sum[i] += sum[i-1]+cost;
		}

		//연쇄행렬곱셈 응용
		for(int len=1; len<n; len++){
			for(int i=1; i<=n-len; i++){
				int j = i+len;
				dp[i][j] = INF;
				for(int k=i; k<j; k++){
					//연쇄행렬곱셈 -> dp합 뒤는 고유의 값을 넣어야함.
					dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+ (sum[j]-sum[i-1]) );
				}
			}
		}

		printf("%lld\n", dp[1][n]);
	}


}
