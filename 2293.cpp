//2293 동전1
#include <cstdio>

int main(void)
{
	int n, k;
	int dp[100010], coin[110]; //dp : dp, coin : 사용할 동전
	scanf("%d %d", &n, &k); // 입력

	for(int i=0; i<n; i++){
		scanf("%d", &coin[i]); //사용할 동전 입력
	}

	dp[0] = 1; // 0은 1개(없음)
	for(int i=0; i<n; i++){ //동전 종류만큼 반복
		for(int j=1; j<=k; j++){ //만들 수까지
			if(j - coin[i] >= 0){ //j가 i번째 coin으로 만들 수 있다면
				//지금까지의  개수와 그 시점에 coin[i]로 만들 수 있는 가지수를 더한다.
				dp[j] += dp[j-coin[i]];
			}
		}
	}

	//출력
	printf("%d\n", dp[k]);

}
