//1463 1로 만들기
#include <cstdio>
#include <algorithm>

using namespace std;

int dp[1000010];
int main(void)
{
	int input;
	scanf("%d", &input);

	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for(int i=4; i<=input; i++){
		if(i%2 == 0){
			if(i%3 == 0){
				dp[i] = min(dp[i/2], dp[i/3]);
				dp[i] = min(dp[i], dp[i-1]);
				dp[i] += 1;
			}
			else{
				dp[i] = min(dp[i/2], dp[i-1]);
				dp[i] += 1;
			}
		}
		else if(i%3 == 0){
			if(i%2 == 0){
				dp[i] = min(dp[i/3], dp[i/2]);
				dp[i] = min(dp[i], dp[i-1]);
				dp[i] += 1;
			}
			else{
				dp[i] = min(dp[i/3], dp[i-1]);
				dp[i] += 1;
			}
		}
		else{
			dp[i] = dp[i-1]+1;
		}

	}

	printf("%d\n", dp[input]);
}
