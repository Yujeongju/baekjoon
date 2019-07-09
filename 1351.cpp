//1351 무한수열
#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

map<long long, long long> dp;

long long N, P, Q;
long long recursive(long long N)
{
	if(N == 0)
		return 1;
	else if(dp[N])
		return dp[N];

	dp[N] = recursive(N/P) + recursive(N/Q);
	return dp[N];
}
int main(void)
{
	scanf("%lld %lld %lld", &N, &P, &Q);

	printf("%lld\n", recursive(N));
}
