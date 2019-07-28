//2133 타일 채우기
#include <cstdio>
#include <algorithm>

using namespace std;

int dp[40], N;
int main(void)
{
	scanf("%d", &N);

	dp[0] = 1;
	dp[2] = 3;
	for(int i=4; i<=N; i++){
		//홀수는 채울 수 없음
		if(i % 2 == 0){
			//2 짜리는 고유 개수가 3개
			dp[i] += 3 * dp[i-2];

			for(int j=4; j<=i; j+=2){
				//그외는 고유 개수가 2개 => 유니크 + @ = 유니크
				dp[i] += 2 * dp[i-j];
			}
		}
	}

	printf("%d\n", dp[N]);
}
