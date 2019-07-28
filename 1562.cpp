//1562 계단 수
#include <cstdio>
#include <algorithm>

#define MOD 1000000000
using namespace std;

int N;
long long dp[110][11][1<<10], result;
int main(void)
{
	scanf("%d", &N);
	int full = (1<<10) - 1;

	//dp[i][j][k] => i 길이의 계단수 맨 마지막 숫자가 j로 끝날 때 k라는 비트정보를 가지고 있는 방법의 수
	//방법의수가 되는 이유 :
	//1024칸에 비트를 가질 때 수가 추가되기때문에
	for(int i=1; i<=9; i++)
		dp[1][i][1<<i] = 1;

	for(int i=2; i<=N; i++){
		for(int j=0; j<=9; j++){
			for(int k=0; k<=full; k++){
				//or => 방문한 정보를 담는다
				if(j==0){
					dp[i][j][k | (1<<0)] += dp[i-1][j+1][k] % MOD;
				}
				else if(j==9){
					dp[i][j][k | (1<<9)] += dp[i-1][j-1][k] % MOD;
				}
				else{
					dp[i][j][k | (1<<j)] += (dp[i-1][j-1][k] + dp[i-1][j+1][k]) % MOD;
				}
			}
		}
	}

	for(int i=0; i<=9; i++){
		result += dp[N][i][full] % MOD;
	}

	printf("%lld\n", result%MOD);

}
