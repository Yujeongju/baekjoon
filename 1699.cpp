//1699 제곱수의 합
#include <cstdio>
#include <algorithm>

using namespace std;

int dp[100100];
int main(void)
{
	int n, tmp=0, cnt=0;
	scanf("%d", &n);

	for(int i=1; i<=n; i++)
		dp[i] = i;

	for(int i=2; i<=n; i++){
		for(int j=2; j*j<=i; j++){
			//12예외가 존재. 2^2 + 2^2 + 2^2 > 3^2 + 1+1+1
			dp[i] = min(dp[i], dp[i-j*j]+1);
		}
	}

	printf("%d\n", dp[n]);
}
