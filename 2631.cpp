//2631 줄세우기
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int line[210], dp[210];
int main(void)
{
	int cnt=0;
	scanf("%d", &N);
	for(int i=1; i<=N; i++)
		scanf("%d", &line[i]);

	dp[0] = -1;
	for(int i=1; i<=N; i++){
		for(int j=0; j<=i; j++){
			if(line[i] > line[j] && dp[i] < dp[j]+1){
				dp[i] = dp[j]+1;
				cnt = max(dp[i], cnt);
			}	
		}
	}

	printf("%d\n", N-cnt-1);
}
