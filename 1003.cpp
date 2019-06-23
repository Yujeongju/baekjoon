//1003 피보나치 함수
#include <cstdio>
#include <utility>

using namespace std;
int main(void)
{
	int num, input;
	pair<int, int> dp[50];
	scanf("%d", &num);

	dp[0] = make_pair(1, 0);
	dp[1] = make_pair(0, 1);
	
	for(int i=2; i<=40; i++){
		dp[i] = make_pair(dp[i-2].first+dp[i-1].first, dp[i-2].second+dp[i-1].second);
	}

	for(int i=0; i<num; i++){
		scanf("%d", &input);

		printf("%d %d\n", dp[input].first, dp[input].second);

	}
}
