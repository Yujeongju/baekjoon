//9461 파도반 수열
#include <cstdio>
#include <algorithm>

using namespace std;

long long arr[110], dp[110];
int main(void)
{
	int N, input;
	scanf("%d", &N);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	for(int i=3; i<=100; i++){
		dp[i] = dp[i-3]+dp[i-2];
	}

	while(N--){
		scanf("%d", &input);
		printf("%lld\n", dp[input]);
	}
}
